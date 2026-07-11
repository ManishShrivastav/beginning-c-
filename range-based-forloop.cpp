#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int scores[] {10, 20, 30};
    for (auto score: scores)
    {
        cout << score << endl;
    }

    // ====================================================================
    vector <double> temperatures {87.9, 77.9, 80.0, 72.5};
    double average_temp {};
    double running_total {};

    for (auto temp : temperatures)
    {
        running_total += temp;
    }

    if (temperatures.size() != 0)
    {
        average_temp = running_total / temperatures.size();
    }
    
    cout << fixed << setprecision(2);
    cout << "Average temperatur is " << average_temp << endl;

    // ====================================================================
    for (auto val : {1, 2, 3, 4, 5})
    {
        cout << val << endl;
    }

    // ====================================================================
    for (auto c : "This is a test")
    {
        if (c != ' ')
        {        
            cout << c;
        }
    }

    // ====================================================================
    for (auto c : "This is a test")
    {
        if (c == ' ')
        {        
            cout << "\t";
        }
        else
        {
            cout << c;
        }
    }
    
    
    cout << endl;

    return 0;
}