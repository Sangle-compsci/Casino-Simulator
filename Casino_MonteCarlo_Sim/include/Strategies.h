#pragma once
#include "BettingStrategy.h"
#include <cmath>
#include <algorithm>
class MartingaleStrategy : public BettingStrategy {
public:
    double calculateBet(double balance, double baseBet, int losses) override {
        double amount = baseBet * std::pow(2, losses);
        return std::min(amount, balance);
    }
};
class SafeStrategy : public BettingStrategy {
public:
    double calculateBet(double balance, double baseBet, int losses) override {
        return std::min(baseBet, balance);
    }
};

