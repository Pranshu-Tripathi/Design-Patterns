#pragma once
#include <sstream>
#include <string>

enum { INVALID_Memento = -1 };

class BankAccount;

class Memento {
  int balance;
  friend class BankAccount;

public:
  Memento(int balance) : balance(balance) {}
};

class BankAccount {
  int balance;

public:
  BankAccount(int balance) : balance(balance) {}
  Memento withdraw(int amount) {
    if (balance >= amount) {
      balance -= amount;
      return {balance};
    }
    /*
    One can simply return the balance here.
    Did specificly to show that we can use
    Memento for status as well.
    */
    return {INVALID_Memento};
  }
  Memento deposit(int amount) {
    balance += amount;
    return {balance};
  }

  void restore(Memento &m) {
    if (m.balance != INVALID_Memento)
      balance = m.balance;
  }

  std::string to_string() const {
    std::ostringstream oss;
    oss << "Account Balance = [" << std::to_string(balance) << "]" << std::endl;
    return oss.str();
  }
};
