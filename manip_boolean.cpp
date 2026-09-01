#include <iostream>
#include <iomanip>

int main() {
    // Default
    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    // Set to true/false
    std::cout << "\n==============================================" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // setting still says for future insertions
    std::cout << "\n==============================================" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // Toggle to 0/1
    std::cout << "\n==============================================" << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl;

    // set back to true/false using setf method
    std::cout << "\n==============================================" << std::endl;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // resets to default which is 0/1
    std::cout << "\n==============================================" << std::endl;
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "Default (10 == 20): " << (10 == 20) << std::endl;
    
    return 0;
}