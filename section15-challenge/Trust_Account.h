#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"

class Trust_Account : public Savings_Account {
private:
    static constexpr const char* DEFAULT_NAME = "Unnamed Trust Account";
    static constexpr double DEFAULT_BALANCE = 0.0;
    static constexpr double DEFAULT_INTEREST_RATE = 0.0; // 5% interest
    static constexpr double BONUS_THRESHOLD = 5000.0; // Bonus threshold
    static constexpr double BONUS_AMOUNT = 50.0; // Bonus amount
    static constexpr int MAX_WITHDRAWALS = 3; // Maximum number of withdrawals
    static constexpr double MAX_WITHDRAW_PERCENTAGE = 0.2; // Maximum withdrawal percentage

protected:
    int withdrawals; // Track the number of withdrawals
    
public:
    Trust_Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE, double interest_rate = DEFAULT_INTEREST_RATE);
    
    // Deposits of $5000 or more will receive a $50 bonus
    bool deposit(double amount);

    // Withdrawals are limited to 3 per year and cannot exceed 20% of the account balance
    bool withdraw(double amount);
    // Inherits Account::get_balance methods
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
};

#endif // _TRUST_ACCOUNT_H_