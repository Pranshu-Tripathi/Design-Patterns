#include "movie.h"


enum class Genre {
    Action,
    Comedy
};

class MovieFactory {
    public:
    virtual Movie getMovie(Genre type) = 0;
};

class HollyWoodMovieFactory : public MovieFactory{
    public:
    Movie getMovie(Genre type) {
        switch(type) {
            case Genre::Action:
                return HollywoodActionMovie();
            case Genre::Comedy:
                return HollywoodComedyMovie();
            default:
                return HollywoodActionMovie();
        }
    }
};

class BollyWoodMovieFactory : public MovieFactory{
    public:
    Movie getMovie (Genre type) {
        switch(type) {
            case Genre::Action:
                return BollywoodActionMovie();
            case Genre::Comedy:
                return BollywoodComedyMovie();
            default:
                return BollywoodActionMovie();
        }
    }
};

class TolloyWoodMovieFactory : public MovieFactory{
    public:
    Movie getMovie (Genre type) {
        switch(type) {
            case Genre::Action:
                return TolloywoodActionMovie();
            case Genre::Comedy:
                return TolloywoodComedyMovie();
            default:
                return TolloywoodActionMovie();
        }
    }
};