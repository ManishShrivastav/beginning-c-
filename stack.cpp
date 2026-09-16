#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include <list>

/* This function displays a stack of  by repeatedly topping and popping the stack
    NOTE that the stack is passed in value so we don't affect the passed-in stack */


template <typename T>
void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::stack<int> s;
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;

    for (int i: {1, 2, 3, 4, 5})
        s.push(i);

    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty()) {
        s.pop();
    }
    display(s);

    std::cout << "\nSize of stack s is: " << s.size() << std::endl;

    s.push(10);
    display(s);

    s.top() = 100;          // change the top element to 100
    display(s);

    return 0;
}