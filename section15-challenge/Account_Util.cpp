#include <iostream>
#include "Account_Util.h"

// Display Account objects in a vector of Account objects
void display(const std::vector<Account> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}

// Deposit supplied amount to each Account object in a vector of Account objects
void deposit(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts ============================" << std::endl;
    for (auto &acc: accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Account object in a vector of Account objects
void withdraw(std::vector<Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts =========================" << std::endl;
    for (auto &acc: accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Helper functions for Savings_Account class

// Display Savings_Account objects in a vector of Savings_Account objects
void display(const std::vector<Savings_Account> &accounts) {
    std::cout << "\n=== Savings Accounts ==================================" << std::endl;
    for (const auto &acc: accounts)
        std::cout << acc << std::endl;
}   

// Deposit supplied amount to each Savings_Account object in a vector of Savings_Account objects
void deposit(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ====================" << std::endl;
    for (auto &acc: accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}

// Withdraw supplied amount from each Savings_Account object in a vector of Savings_Account objects
// Note: Savings_Account inherits withdraw from Account, so we can use the same function as
// the one for Account objects. However, we can also create a separate function for Savings_Account objects if we want to customize the behavior for Savings_Account withdrawals in the future.
void withdraw(std::vector<Savings_Account> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ==================" << std::endl;
    for (auto &acc: accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}
