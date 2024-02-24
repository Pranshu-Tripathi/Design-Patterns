#pragma once
#include <iostream>
#include <sstream>
#include <string>

class BankAccount {
  int balance{0};
  int overdue_limit{-500};

public:
  BankAccount(int balance, int overdue_limit)
      : balance(balance), overdue_limit(overdue_limit) {}
  ~BankAccount() = default;

  bool withdraw(int amount) {
    if (balance - amount >= overdue_limit) {
      balance -= amount;
      std::cout << "Amount: {" << amount
                << "} withdrawn sucessfuly. New Balance: {" << balance << "}"
                << std::endl;

      return true;
    }
    std::cout << "Withdraw{" << amount << "} Operation Failed" << std::endl;
    return false;
  }

  bool deposit(int amount) {
    balance += amount;
    std::cout << "Amount: {" << amount
              << "} deposited sucessfuly. New Balance: {" << balance << "}"
              << std::endl;
    return true;
  }

  std::string to_string() const {
    std::ostringstream oss;
    oss << "Bank Accout Detail : { Balance: " << balance
        << "}, overdue limit : {" << overdue_limit << "}";
    return oss.str();
  }
};
