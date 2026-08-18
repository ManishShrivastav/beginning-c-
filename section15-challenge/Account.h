#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class Account {
private:
    static constexpr const char* DEFAULT_NAME = "Unnamed Account";
    static constexpr double DEFAULT_BALANCE = 0.0;

protected:
    std::string name;
    double balance;
    
public:
    Account(std::string name = DEFAULT_NAME, double balance = DEFAULT_BALANCE);
    // Account(std::string name = "Unnamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif // _ACCOUNT_H_