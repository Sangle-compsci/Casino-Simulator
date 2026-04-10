#include "Simulator.h"
#include "PlayerFactory.h"
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>
#include <cstdlib>

void runSimulationNode(int threadID, int numSimulations) {
    std::string fileName = "data_" + std::to_string(threadID) + ".csv";
    Simulator sim(numSimulations, fileName);

    sim.addPlayer(PlayerFactory::createPlayer(PlayerFactory::Type::MARTINGALE, "GapThep", 50000.0));
    sim.addPlayer(PlayerFactory::createPlayer(PlayerFactory::Type::SAFE, "AnToan", 50000.0));

    sim.run();
}

int main() {
    int totalSimulations = 10000000;
    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    std::cout << "========================================\n";
    std::cout << "Phat hien CPU co " << numThreads << " luong. Bat dau ep xung...\n";
    std::cout << "========================================\n";

    int simsPerThread = totalSimulations / numThreads;
    std::vector<std::thread> workers;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (unsigned int i = 1; i <= numThreads; ++i) {
        workers.push_back(std::thread(runSimulationNode, i, simsPerThread));
    }

    for (auto& t : workers) {
        t.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "\nMo phong hoan tat 100%!\n";
    std::cout << "Thoi gian chay: " << elapsed.count() << " giay.\n";
    std::cout << "----------------------------------------\n";
    std::cout << "[+] Dang chuyen giao du lieu cho Python...\n";

    std::system("python scripts/bao_cao_casino.py");

    return 0;
}