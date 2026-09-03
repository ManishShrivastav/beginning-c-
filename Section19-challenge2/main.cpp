// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>

void print_header() {
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(5) << "Score"
              << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << ""
              << std::setfill(' ') // reset fill character to space
              << std::endl;
}

int process_response(const std::string &answer_key, const std::string &response) {
    int score {0};
    for (size_t i = 0; i < answer_key.length(); ++i) {
        if (i < response.length() && answer_key[i] == response[i]) {
            ++score; // increment score for each correct answer
        }
    }
    return score;
}

void print_student_score(const std::string &name, int score) {
    std::cout << std::setprecision(2) << std::fixed; // set precision for score output
    std::cout << std::setw(15) << std::left << name
              << std::setw(5) << score
              << std::endl;
}

void print_footer(double average_score) {
    std::cout << std::setw(20) << std::setfill('-') << ""
              << std::setfill(' ') // reset fill character to space
              << std::endl;
    std::cout << std::setw(15) << std::left << "Average Score"
              << std::setw(5) << average_score
              << std::endl;
}

using namespace std;

int main() {
    std::ifstream in_file;
    std::string answer_key {};
    std::string name {};
    std::string response {};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};

    in_file.open("responses.txt");
    if(!in_file) {
        std::cerr << "Problem opening file responses.txt";
        return 1;
    }

    in_file >> answer_key; // read the answer key from the file

    print_header(); // print the header for the output
    
    while (in_file >> name >> response) {
        ++total_students; // increment the total number of students
        int score = process_response(answer_key, response); // calculate the score for the student
        running_sum += score; // add the score to the running sum
        print_student_score(name, score); // print the student's name and score
    }

    if (total_students != 0) {
        average_score = static_cast<double>(running_sum) / total_students; // calculate the average score
    }

    print_footer(average_score); // print the footer with the average score

    in_file.close(); // close the file
    std::cout << std::endl; // print a newline for better formatting

    return 0;
}

