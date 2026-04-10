#pragma once

class BettingStrategy {
public:
    virtual ~BettingStrategy() = default;
    virtual double calculateBet(double balance, double baseBet, int losses) = 0;
};
