#include "person.h"
#include "chatroom.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Person::Person(const std::string &name) : m_name(name), m_id(INVALID_ID) {}

void Person::send(const std::string &message) const {
  if (m_room == nullptr) {
    throw std::runtime_error("No Room Created!");
  }
  m_room->broadcast(this, message);
}

void Person::private_message(const int receiver,
                             const std::string &message) const {
  if (m_room == nullptr) {
    throw std::runtime_error("No Room Created!");
  }
  auto receiver_person = m_room->get_person(receiver);
  m_room->private_message(this, receiver_person, message);
}

void Person::receive(const int sender, const std::string &message) {
  if (m_room == nullptr) {
    throw std::runtime_error("No Room Created!");
  }

  std::cout << this->to_string() << "::" << m_room->get_person_detail(sender)
            << "==>" << message << std::endl;
  m_chatlog.push_back({sender, message});
}

int Person::get_uuid() const { return m_id; }

void Person::set_uuid(const int id) { m_id = id; }

std::string Person::get_name() const { return m_name; }

void Person::set_room(ChatRoom *room) { m_room = room; }

std::string Person::to_string() const {
  std::ostringstream oss;
  oss << get_name() + "[" + std::to_string(get_uuid()) + "]";
  return oss.str();
}

std::string Person::get_chatlogs() const {
  std::ostringstream oss;
  oss << " ------------ Chat Logs ----------------" << std::endl;
  for (const auto &log : m_chatlog) {
    const auto &[sender, message] = log;
    auto sender_details = m_room->get_person_detail(sender);
    oss << sender_details << "-->" << message << std::endl;
  }
  oss << " ---------------------------------------" << std::endl;
  return oss.str();
}
