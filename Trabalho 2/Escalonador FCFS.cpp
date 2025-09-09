#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int process_id;
    int completion_time;
};

int main() {
    int N;
    cin >> N;

    queue<Process> process_queue;

    for (int i = 1; i <= N; i++) {
        Process process;
        process.process_id = i;
        process.completion_time = 0;
        process_queue.push(process);
    }

    int total_instructions;
    cin >> total_instructions;

    int current_time = 0;

    for (int i = 0; i < total_instructions; i++) {
        int instruction;
        for (int j = 0; j < N; j++) {
            cin >> instruction;

            Process current_process = process_queue.front();
            process_queue.pop();

            if (instruction == 0) {
                // Instrução não bloqueante
                current_time += 10;
            } else {
                // Instrução bloqueante
                current_time += 0;  // Simula o processo de transformação, mas não consome tempo
            }

            current_process.completion_time = current_time;
            process_queue.push(current_process);
        }
    }

    // Imprimindo o resultado
    while (!process_queue.empty()) {
        Process completed_process = process_queue.front();
        process_queue.pop();
        cout << completed_process.process_id << " (" << completed_process.completion_time << ")\n";
    }

    return 0;
}
