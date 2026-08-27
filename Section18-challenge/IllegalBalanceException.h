#ifndef _ILLEGAL_BALANCE_EXCEPTION_H_
#define _ILLEGAL_BALANCE_EXCEPTION_H_

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "Illegal balance exception.";
    }
};

#endif      // _ILLEGAL_BALANCE_EXCEPTION_H_