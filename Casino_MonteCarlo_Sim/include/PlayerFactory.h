#pragma once
#include "Player.h"
#include "Strategies.h"
#include <memory>
#include <string>

class PlayerFactory {
public:
    enum class Type { MARTINGALE, SAFE };

    static std::unique_ptr<Player> createPlayer(Type type, std::string name, double balance) {
        double defaultBaseBet = 10.0;
        std::unique_ptr<BettingStrategy> strat;

        switch (type) {
        case Type::MARTINGALE:
            strat = std::make_unique<MartingaleStrategy>(); break;
        case Type::SAFE:
            strat = std::make_unique<SafeStrategy>(); break;
        }

        return std::make_unique<Player>(name, balance, defaultBaseBet, std::move(strat));
    }
};