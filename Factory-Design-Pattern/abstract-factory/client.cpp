#include "movie_factory.h"
#include "movie.h"
#include "factory_producer.h"


int main(){
    auto factory_producer = new MovieProducer();
    auto movie_factory = factory_producer->getFactory(MovieType::Hollywood);
    auto movie = movie_factory.getMovie(Genre::Action);

    // use the movie object
}