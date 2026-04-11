#pragma once
#include <string>

class House {
private:
    std::string name;
    double balance;
    double initialBalance;

public:
    House(const std::string& n, double bal) : name(n), balance(bal), initialBalance(bal) {}

    std::string getName() const { return name; }
    double getBalance() const { return balance; }
    double getInitialBalance() const { return initialBalance; }

    void updateBalance(double change) {
        balance += change;
    }

    bool isBankrupt() const {
        return balance <= 0;
    }
};