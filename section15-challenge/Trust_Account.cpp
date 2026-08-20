#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
    : Savings_Account{name, balance, interest_rate}, num_withdrawals{0} {
}

// Deposits of $5000 or more will receive a $50 bonus
bool Trust_Account::deposit(double amount) {
    if (amount >= BONUS_THRESHOLD) {
        amount += BONUS_AMOUNT; // Add the bonus to the deposit amount
    }
    return Savings_Account::deposit(amount); // Call the base class deposit method
}

// Withdrawals are limited to 3 per year and cannot exceed 20% of the account balance
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= MAX_WITHDRAWALS || amount > (balance * MAX_WITHDRAW_PERCENTAGE)) {
        std::cout << "Withdrawal denied: Exceeded maximum withdrawals or withdrawal amount exceeds 20% of balance." << std::endl;
        return false; // Deny the withdrawal
    } else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", Interest Rate: " << account.int_rate << ", Withdrawals: " << account.num_withdrawals << "]";
    return os;
}