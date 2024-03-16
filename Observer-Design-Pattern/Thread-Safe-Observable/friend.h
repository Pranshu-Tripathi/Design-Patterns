#pragma once
#include "observer.h"
#include "person.h"
#include <string>

enum class Platform;

class Friend : public Observer<Person> {
  std::string name;

public:
  Friend(const std::string &name);

  void join_watch_party(const Platform platform) const;

  void notify(Person &p, const Platform platform) const override;

  std::string get_name() const;
};
