#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

// Savings Account is a type of Account
//   adds an interest rate
// Withdraw - same as a regular account
// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//

class Savings_Account : public Account {
private:
    static constexpr const char* DEFAULT_NAME = "Unnamed Savings Account";
    static constexpr double DEFAULT_BALANCE = 0.0;
    static constexpr double DEFAULT_INT_RATE = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE, double int_rate = DEFAULT_INT_RATE);
    bool deposit(double amount);
    // Inherits Account::withdraw methods
    // Inherits Account::get_balance methods
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
};

#endif // _SAVINGS_ACCOUNT_H_