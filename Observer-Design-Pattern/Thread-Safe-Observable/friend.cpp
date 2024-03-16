#include "friend.h"
#include "observer.h"
#include "person.h"
#include <iostream>
#include <sstream>
#include <unordered_map>

static std::string get_platform_name(const Platform platform) {
  static std::unordered_map<Platform, std::string> platform_to_name = {
      {Platform::DISCORD, std::string("Discord")},
      {Platform::GOOGLE_MEET, std::string("GMEET")},
      {Platform::ZOOM, std::string("ZOOM")}};

  return platform_to_name.at(platform);
}

Friend::Friend(const std::string &name) : name(name) {}

void Friend::join_watch_party(const Platform platform) const {
  std::ostringstream oss;
  oss << "Joining stream on :: " << get_platform_name(platform);
  std::cout << oss.str() << std::endl;
}

std::string Friend::get_name() const { return this->name; }

void Friend::notify(Person &p, const Platform platform) const {

  std::ostringstream oss;
  oss << get_name() << " notified by " << p.get_name() << " :: ";
  std::cout << oss.str();
  join_watch_party(platform);
}
