#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account{name, balance}, int_rate{int_rate} {
}

bool Savings_Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        amount += amount * (int_rate / 100);
        return Account::deposit(amount);
    }
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Savings Account: " << name << ": " << balance << ", " << int_rate << "%]";
}

// std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
//     os << "[Savings Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
//     return os;
// }