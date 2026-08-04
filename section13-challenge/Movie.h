#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
private:
    std::string name;       /*the name of the movie */
    std::string rating;     /*the rating of the movie G, PG, PG-13, R */
    int watched;            /*the number of times the movie has been watched */
public:
    //constructor - expects all three movie attributes as arguments
    Movie(std::string name, std::string rating, int watched);

    //copy constructor
    Movie(const Movie &source);

    //destructor
    ~Movie();

    // Basic getter and setteer methods for private attributes
    // implemented inline for simplicity

    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }

    void set_rating(std::string rating) { this->rating = rating; }
    std::string get_rating() const { return rating; }

    void set_watched(int watched) { this->watched = watched; }
    int get_watched() const { return watched; }

    // increment the number of times watched
    void increment_watched() { ++watched; }

    // display the movie attributes
    void display() const;
};
#endif // _MOVIE_H_