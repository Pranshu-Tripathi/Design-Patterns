#pragma once
#include "person.h"
#include <initializer_list>

class ChatRoom {
  std::vector<Person *> m_people;
  std::vector<std::pair<int, std::string>> m_inactive_users;

public:
  ChatRoom();
  Person *get_person(const int id) const;
  void generate_id(Person *p) const;
  void join(Person *p);
  void join(std::initializer_list<Person *> people);
  void leave(Person *p);
  void broadcast(const Person *sender, const std::string &message) const;
  void room_broadcast(const std::string &message) const;
  void private_message(const Person *sender, Person *reciever,
                       const std::string &message) const;
  std::string get_person_detail(int person) const;
};
