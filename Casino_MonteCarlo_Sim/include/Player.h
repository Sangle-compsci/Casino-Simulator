#pragma once
#include <string>
#include <memory>
#include "BettingStrategy.h"

class Player {
private:
    std::string name;
    double balance;
    double baseBet;
    int consecutiveLosses = 0;
    std::unique_ptr<BettingStrategy> strategy;

public:
    Player(std::string n, double bal, double bBet, std::unique_ptr<BettingStrategy> strat)
        : name(n), balance(bal), baseBet(bBet), strategy(std::move(strat)) {
    }

    std::string getName() const { return name; }
    double getBalance() const { return balance; }

    double getBetAmount() {
        return strategy->calculateBet(balance, baseBet, consecutiveLosses);
    }

    void updateBalance(double change) {
        balance += change;
        if (change < 0) consecutiveLosses++;
        else consecutiveLosses = 0;
    }
};