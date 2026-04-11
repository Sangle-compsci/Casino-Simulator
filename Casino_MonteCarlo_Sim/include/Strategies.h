#pragma once
#include "BettingStrategy.h"
#include <cmath>
#include <algorithm>

class ChungThuyStrategy : public BettingStrategy {
public:
    std::map<Symbol, double> calculateBets(double balance, double baseBet, int losses) const override {
        std::map<Symbol, double> bets;
        double amount = baseBet * std::pow(2, losses);
        amount = std::min(amount, balance);

        if (amount > 0) {
            bets[Symbol::BAU] = amount;
        }
        return bets;
    }
};

class RaiThamStrategy : public BettingStrategy {
public:
    std::map<Symbol, double> calculateBets(double balance, double baseBet, int losses) const override {
        std::map<Symbol, double> bets;

        double splitBet = std::min(baseBet, balance / 3.0);

        if (splitBet > 0) {
            bets[Symbol::BAU] = splitBet;
            bets[Symbol::CUA] = splitBet;
            bets[Symbol::TOM] = splitBet;
        }
        return bets;
    }
};