#include <iostream>
#include <vector>   // donot forget to include the vector header
using namespace std;

int main()
{
    // vector <char> vowels;       // empty vector of char type
    // vector <char> vowels(5);   // vector of char type with 5 elements initialized to default value (null character)
    vector <char> vowels{'a', 'e', 'i', 'o', 'u'}; 

    cout << "The first vowel is: " << vowels[0] << endl; // prints 'a'
    cout << "The last vowel is: " << vowels[4] << endl; // prints 'u'

    // vector <int> test_scores (3);                // vector of int type with 3 elements initialized to default value (0)
    // vector <int> test_scores (3, 100);          // vector of int type with 3 elements initialized to 100

    vector <int> test_scores {100, 98, 89};        // vector of int type with 3 elements initialized to 100, 98, and 89

    cout <<"\nTest scores using array subscript ([]) notation: " << endl;
    cout << test_scores[0] << endl; // prints 100
    cout << test_scores[1] << endl; // prints 98
    cout << test_scores[2] << endl; // prints 89

    cout <<"\nTest scores using vector's at() method: " << endl;
    cout << test_scores.at(0) << endl; // prints 100
    cout << test_scores.at(1) << endl; // prints 98
    cout << test_scores.at(2) << endl; // prints 89
    cout <<"\nThere are " << test_scores.size() << " scores in the vector" << endl; // prints 3

    cout << "\nEnter 3 test scores: ";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout <<"\nUpdated test scores: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout <<"\nEnter a test score to add to the vector: ";
    int score_to_add {0};
    cin >> score_to_add;
    test_scores.push_back(score_to_add); // add score to the end of the vector
    cout <<"\nEnter one more test score to add to the vector: ";
    cin >> score_to_add;
    test_scores.push_back(score_to_add); // add score to the end of the vector


    cout <<"\nTest scores are now: " << endl;

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;


    cout <<"\nThere are " << test_scores.size() << " scores in the vector" << endl; // prints 5

    // cout <<"This should cause an exception!!" <<test_scores.at(10) << endl;

    //========================================================================//
    // Examplle of a 2D vector

    vector <vector<int>> movie_ratings
    {
        {1, 2, 3, 4},
        {1, 2, 4, 4},
        {1, 3, 4, 5}
    };

    cout <<"\nHere are the movie ratings for reviewer #1 using array subscript notation: " << endl;
    cout << movie_ratings[0][0] << endl; // prints 1
    cout << movie_ratings[0][1] << endl; // prints 2
    cout << movie_ratings[0][2] << endl; // prints 3
    cout << movie_ratings[0][3] << endl; // prints 4

    cout <<"\nHere are the movie ratings for reviewer #2 using vector's at() method: " << endl;
    cout << movie_ratings.at(1).at(0) << endl; // prints 1
    cout << movie_ratings.at(1).at(1) << endl; // prints 2
    cout << movie_ratings.at(1).at(2) << endl; // prints 4
    cout << movie_ratings.at(1).at(3) << endl; // prints 4

    cout <<endl;

    return 0;
}