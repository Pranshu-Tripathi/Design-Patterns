#include "chatroom.h"
#include "person.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
static int gen_id = ROOM_ID;

ChatRoom::ChatRoom() {
  std::cout << "Room Created !" << std::endl;
  m_people.clear();
}

Person *ChatRoom::get_person(const int id) const {

  auto check_person = [id](const Person *p) { return p->get_uuid() == id; };

  auto person_it = std::find_if(m_people.begin(), m_people.end(), check_person);
  if (person_it == std::end(m_people)) {
    throw std::out_of_range("Person not found");
  }
  return *person_it;
}

void ChatRoom::generate_id(Person *p) const {
  if (gen_id == std::numeric_limits<int>::max()) {
    throw std::runtime_error("ID Limit Reached!");
  }
  p->set_uuid(++gen_id);
}

void ChatRoom::join(Person *p) {
  generate_id(p);
  p->set_room(this);
  m_people.push_back(p);
  room_broadcast(p->to_string() + " joined the room");
}

void ChatRoom::join(std::initializer_list<Person *> people) {
  for (const auto &p : people) {
    join(p);
  }
}

void ChatRoom::leave(Person *p) {

  auto invalid_it = std::find(m_people.begin(), m_people.end(), p);

  if (invalid_it != std::end(m_people)) {
    room_broadcast((*invalid_it)->to_string() + " left the room");
    m_people.erase(invalid_it);
    m_inactive_users.push_back({p->get_uuid(), p->to_string() + "<inactive>"});
  }
}

void ChatRoom::broadcast(const Person *sender,
                         const std::string &message) const {
  auto receive_message = [sender, message](Person *p) {
    if (sender->get_uuid() != p->get_uuid()) {
      p->receive(sender->get_uuid(), message);
    }
  };

  std::for_each(m_people.begin(), m_people.end(), receive_message);
}

void ChatRoom::room_broadcast(const std::string &message) const {
  auto receive_message = [message](Person *p) { p->receive(ROOM_ID, message); };
  std::for_each(m_people.begin(), m_people.end(), receive_message);
}

void ChatRoom::private_message(const Person *sender, Person *receiver,
                               const std::string &message) const {
  receiver->receive(sender->get_uuid(), message);
}

std::string ChatRoom::get_person_detail(int person) const {
  if (person == INVALID_ID) {
    throw std::invalid_argument("Not a valid person");
  }
  if (person == ROOM_ID) {
    return "[- ROOM -]";
  }
  std::string person_details;
  try {
    person_details = get_person(person)->to_string();
  } catch (std::out_of_range &) {
    // check inactive user cache
    auto check_inactive_user =
        [person, &person_details](const std::pair<int, std::string> &user) {
          if (person == user.first) {
            person_details = user.second;
          }
        };
    std::for_each(m_inactive_users.begin(), m_inactive_users.end(),
                  check_inactive_user);
  }
  if (person_details.empty()) {
    throw std::runtime_error("No such user regiested");
  }
  return person_details;
}
