#pragma once
#include <string>
#include <vector>

enum { INVALID_ID = -1, ROOM_ID = 0 };

class ChatRoom;

class Person {
  ChatRoom *m_room{nullptr};
  std::vector<std::pair<int, std::string>> m_chatlog;
  std::string m_name;
  int m_id{INVALID_ID};

public:
  Person(const std::string &name);
  ~Person() = default;

  void send(const std::string &message) const;

  void private_message(const int reciever, const std::string &message) const;

  void receive(const int sender, const std::string &message);

  int get_uuid() const;

  void set_uuid(const int id);

  std::string get_name() const;

  void set_room(ChatRoom *room);

  std::string to_string() const;

  std::string get_chatlogs() const;
};
