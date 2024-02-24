#pragma once

#include "bank_account.h"
class Command {
public:
  virtual void call() = 0;
  virtual void undo() = 0;

protected:
  bool sucess{false};
};

enum class BankAccountOpeartion { WITHDRAW, DEPOSIT };

class BankAccountCommand : public Command {
private:
  BankAccount &account;
  int amount;
  BankAccountOpeartion operation;

public:
  BankAccountCommand(BankAccount &account, const int amount,
                     const BankAccountOpeartion operation)
      : account(account), amount(amount), operation(operation) {}
  ~BankAccountCommand() = default;

  void call() override {
    switch (operation) {
    case BankAccountOpeartion::WITHDRAW:
      sucess = account.withdraw(amount);
      break;
    case BankAccountOpeartion::DEPOSIT:
      sucess = account.deposit(amount);
    }
  }

  void undo() override {
    if (not sucess) {
      std::cout << "Command Not Successful : undo rejected" << std::endl;
      return;
    }
    /*
    Assumption that withdraw and deposit are symmetric operations.
    Undo here is not handling failed command operations.
    In a real world scenerio its more of a transaction rollback
    till last valid check point.
    */
    switch (operation) {
    case BankAccountOpeartion::WITHDRAW:
      sucess = account.deposit(amount);
      break;
    case BankAccountOpeartion::DEPOSIT:
      sucess = account.withdraw(amount);
    }
  }

  bool command_return_status() { return sucess; }
};
