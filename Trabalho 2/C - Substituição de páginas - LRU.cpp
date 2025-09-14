#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int quadros, n_referencias;
    std::cin >> quadros;
    std::cin >> n_referencias;

    std::list<int> lru_list;
    std::unordered_map<int, std::list<int>::iterator> page_map;
    int page_faults = 0;

    for (int i = 0; i < n_referencias; ++i) {
        int pagina_referenciada;
        std::cin >> pagina_referenciada;

        auto it = page_map.find(pagina_referenciada);

        if (it == page_map.end()) {
            page_faults++;

            if (lru_list.size() == quadros) {
                int lru_page = lru_list.back();
                lru_list.pop_back();
                page_map.erase(lru_page);
            }
        } else {
            lru_list.erase(it->second);
        }

        lru_list.push_front(pagina_referenciada);
        page_map[pagina_referenciada] = lru_list.begin();
    }

    std::cout << page_faults << std::endl;

    return 0;
}