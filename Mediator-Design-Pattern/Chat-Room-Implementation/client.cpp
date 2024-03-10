#include "chatroom.h"
#include "person.h"
#include <iostream>

int main() {
  ChatRoom room;

  auto anurag = new Person("Anurag");
  auto priyansh = new Person("Priyansh");
  auto divi = new Person("Divyendra");
  auto pranshu = new Person("Pranshu");
  room.join({anurag, priyansh, divi, pranshu});

  anurag->send("Pranshu we want party!! Congratulations");
  pranshu->private_message(anurag->get_uuid(), "About what bro?");
  anurag->private_message(pranshu->get_uuid(),
                          "Your company giving cool perks");
  divi->send("Yes bhai noice company");
  pranshu->send("Bro I got fired :)");
  priyansh->send("I am done");
  room.leave(priyansh);
  pranshu->send("What's up with him?");

  std::cout << pranshu->get_chatlogs() << std::endl;
}
