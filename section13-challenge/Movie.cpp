#include "Movie.h"
#include <iostream>

// Implementation of the Movie class methods

// Implementation of thec onstructor (using member initializer list)
Movie::Movie(std::string name, std::string rating, int watched)
    : name{name}, rating{rating}, watched{watched} {
}

// Implementation of the copy constructor (using delegating constructor)
Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched} {
}

// Implementation of the destructor
Movie::~Movie() {
}

// Implementation of the display method
void Movie::display() const {
    std::cout << "Movie: " << name << ", Rating: " << rating << ", Watched: " << watched << std::endl;
}