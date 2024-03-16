#pragma once
#include "observable.h"
#include <string>

enum class Platform { DISCORD, GOOGLE_MEET, ZOOM };

class Person : public Observable<Person> {
  std::string name;

public:
  Person(const std::string &name);

  void ask_watch_party(const Platform platform = Platform::DISCORD);

  std::string get_name() const;
};
