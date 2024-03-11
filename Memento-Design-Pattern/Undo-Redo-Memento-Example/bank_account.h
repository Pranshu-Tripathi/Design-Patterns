#pragma once
#include <memory>
#include <string>
#include <vector>

class Memento {
  int balance;
  friend class BankAccount;

public:
  Memento(int balance);
};

class BankAccount {
  int balance;
  std::vector<std::shared_ptr<Memento>> states;
  int current_state;

public:
  BankAccount(int balance);
  void withdraw(int amount);
  void deposit(int amount);
  void restore(std::shared_ptr<Memento> &state);
  void undo();
  void redo();
  std::string to_string() const;
  void save_snapshot();
};
