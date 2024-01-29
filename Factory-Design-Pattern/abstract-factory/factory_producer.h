#include "movie_factory.h"

enum class MovieType {
    Hollywood,
    Bollywood,
    Tollywood,
};

class MovieProducer {
    public:
    MovieFactory getFactory(MovieType type) {
        switch(type) {
            case MovieType::Hollywood:
                return HollyWoodMovieFactory();
            case MovieType::Bollywood:
                return BollyWoodMovieFactory();
            case MovieType::Tollywood:
                return TollyWoodMovieFactory();
            default:
                return HollyWoodMovieFactory();
        }
    }
};