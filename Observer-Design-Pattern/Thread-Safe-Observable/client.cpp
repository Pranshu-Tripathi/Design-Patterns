#include "fake_friend.h"
#include "friend.h"
#include "person.h"

int main() {
  auto pranshu = new Person("Pranshu");

  auto anurag = new Friend("Anurag");
  auto divi = new Friend("Divyendra");

  pranshu->subscribe(anurag);
  pranshu->subscribe(divi);
  pranshu->ask_watch_party();

  pranshu->unsubscribe(anurag);
  pranshu->subscribe(new Friend("Priyansh"));
  pranshu->ask_watch_party(Platform::GOOGLE_MEET);

  auto fake = new FakeFriend("Name don't matter");
  pranshu->subscribe(fake);

  pranshu->ask_watch_party(Platform::ZOOM);
  pranshu->ask_watch_party();
  pranshu->ask_watch_party(Platform::GOOGLE_MEET);
}
