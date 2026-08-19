#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
#include <string>
#include <iostream>

class Checking_Account : public Account {
private:
    static constexpr const char* DEFAULT_NAME = "Unnamed Checking Account";
    static constexpr double DEFAULT_BALANCE = 0.0;
    static constexpr double DEFAULT_FEE = 1.50;
public:
    Checking_Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE);
    bool withdraw(double amount);
    // Inherits Account::deposit methods
    // Inherits Account::get_balance methods
};

#endif // _CHECKING_ACCOUNT_H_