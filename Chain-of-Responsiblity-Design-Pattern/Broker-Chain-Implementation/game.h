#pragma once
#include "queries.h"
#include <boost/signals2.hpp>
/*
    Mediator Class
*/
class Game {
public:
  Game(){};
  ~Game(){};
  boost::signals2::signal<void(Query &)> queries;
};
