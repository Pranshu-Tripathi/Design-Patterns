#pragma once

#include "friend.h"
#include "observer.h"

class FakeFriend : public Friend {
public:
  FakeFriend(const std::string &name);
  void notify(Person &p, const Platform platform) const override;
};
