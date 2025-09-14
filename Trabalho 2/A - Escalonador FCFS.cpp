#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

struct Process {
    int id;
    std::queue<int> instructions;
};

struct Result {
    int id;
    int completion_time;
};

bool compareResults(const Result& a, const Result& b) {
    return a.completion_time < b.completion_time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int count;
        std::cin >> count;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::queue<Process> scheduler_queue;
    for (int i = 0; i < n; ++i) {
        Process p;
        p.id = i + 1;
        std::string instruction_line;
        std::getline(std::cin, instruction_line);
        
        for (char c : instruction_line) {
            if (c == '0' || c == '1') {
                p.instructions.push(c - '0');
            }
        }
        scheduler_queue.push(p);
    }

    int current_time = 0;
    std::vector<Result> finished_processes;

    while (!scheduler_queue.empty()) {
        Process current_process = scheduler_queue.front();
        scheduler_queue.pop();
        bool was_blocked = false;

        // O processo executa continuamente até ser bloqueado ou terminar.
        while (!current_process.instructions.empty()) {
            int instruction = current_process.instructions.front();
            
            if (instruction == 0) {
                current_process.instructions.pop();
                current_time += 10;
            } else {
                // Ao encontrar uma instrução '1', ela é transformada em '0'.
                current_process.instructions.front() = 0;
                scheduler_queue.push(current_process);
                was_blocked = true;
                break;
            }
        }

        if (!was_blocked) {
            finished_processes.push_back({current_process.id, current_time});
        }
    }
    
    std::sort(finished_processes.begin(), finished_processes.end(), compareResults);

    for (const auto& result : finished_processes) {
        std::cout << result.id << " (" << result.completion_time << ")\n";
    }

    return 0;
}