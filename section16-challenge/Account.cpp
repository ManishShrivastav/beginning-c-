#include "Account.h"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    } else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (amount < 0 || amount > balance) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}