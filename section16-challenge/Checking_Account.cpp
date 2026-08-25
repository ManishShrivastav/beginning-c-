#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance} {
}

bool Checking_Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        balance += amount;
        return true;
    }
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    if (amount < 0 || amount > balance) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}