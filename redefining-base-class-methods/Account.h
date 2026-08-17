#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <ostream>

// Simple Account class

class Account {
    protected:
        double balance;
    public:
        Account();
        Account(double balance);
        void deposit(double amount);
        void withdraw(double amount);
        friend std::ostream &operator<<(std::ostream &os, const Account &account);
};

#endif // _ACCOUNT_H_