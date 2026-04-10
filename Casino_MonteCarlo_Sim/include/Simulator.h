#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include <string>

class Simulator {
private:
    int numSimulations;
    std::string outputFileName;
    std::vector<std::unique_ptr<Player>> players;

public:
    Simulator(int nums, std::string fileName) : numSimulations(nums), outputFileName(fileName) {}
    void addPlayer(std::unique_ptr<Player> p);

    void run();
};