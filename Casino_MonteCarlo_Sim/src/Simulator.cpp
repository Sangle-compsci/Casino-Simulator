#include "Simulator.h"
#include <fstream>
#include <iostream>
#include <random>

void Simulator::addPlayer(std::unique_ptr<Player> p) {
    players.push_back(std::move(p));
}

void Simulator::run() {
    std::string fullPath = "data/" + outputFileName;
    std::ofstream outFile(fullPath);

    if (!outFile.is_open()) {
        std::cerr << "Loi: Khong the tao file " << fullPath << "\n";
        return;
    }
    outFile << "Van";
    for (const auto& p : players) {
        outFile << ",Von_" << p->getName();
    }
    outFile << "\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 100.0);

    for (int i = 1; i <= numSimulations; ++i) {
        double ket_qua = dist(rng);
        bool isWin = (ket_qua <= 48.6);

        outFile << i;
        bool allBankrupt = true;

        for (auto& p : players) {
            if (p->getBalance() > 0) {
                allBankrupt = false;
                double bet = p->getBetAmount();
                if (bet > 0) {
                    if (isWin) p->updateBalance(bet);
                    else p->updateBalance(-bet);
                }
            }
            outFile << "," << p->getBalance();
        }
        outFile << "\n";

        if (allBankrupt) break;
    }
    outFile.close();
}