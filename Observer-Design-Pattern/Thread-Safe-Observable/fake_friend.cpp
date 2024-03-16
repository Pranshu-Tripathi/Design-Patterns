#include "fake_friend.h"
#include "friend.h"
#include "observer.h"
#include <iostream>
FakeFriend::FakeFriend(const std::string &name) : Friend(name) {}

void FakeFriend::notify(Person &p, const Platform platform) const {
  if (platform == Platform::DISCORD) {
    std::cout << get_name() << "say's Discord is complicated :: leaving "
              << p.get_name() << std::endl;

    p.unsubscribe(const_cast<FakeFriend *>(this));
  } else {
    join_watch_party(platform);
  }
}
