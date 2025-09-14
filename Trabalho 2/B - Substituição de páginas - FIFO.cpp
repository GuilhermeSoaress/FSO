#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int quadros, n_referencias;
    std::cin >> quadros;
    std::cin >> n_referencias;

    std::queue<int> fifo_queue;
    std::unordered_set<int> paginas_na_ram;
    int page_faults = 0;

    for (int i = 0; i < n_referencias; ++i) {
        int pagina_referenciada;
        std::cin >> pagina_referenciada;

        if (paginas_na_ram.count(pagina_referenciada) == 0) {
            page_faults++;

            if (fifo_queue.size() == quadros) {
                int pagina_vitima = fifo_queue.front();
                fifo_queue.pop();
                paginas_na_ram.erase(pagina_vitima);
            }

            fifo_queue.push(pagina_referenciada);
            paginas_na_ram.insert(pagina_referenciada);
        }
    }

    std::cout << page_faults << std::endl;

    return 0;
}