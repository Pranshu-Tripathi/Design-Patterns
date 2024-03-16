#include "person.h"

Person::Person(const std::string &name) : name(name) {}

void Person::ask_watch_party(const Platform platform) {
  notify_all(*this, platform);
}

std::string Person::get_name() const { return this->name; }
