#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += DEFAULT_FEE; // Add the transaction fee to the withdrawal amount
    return Account::withdraw(amount); // Call the base class withdraw method
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}