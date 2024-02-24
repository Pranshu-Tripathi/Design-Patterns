#pragma once
#include "bank_account.h"
#include "commands.h"
#include <initializer_list>
#include <vector>

/*
   This is a bad practice but just for
   state of the art implementation we can ignore this
   for now. This is bad because STL don't have virtual
   destructor and we can't delete the derived class
*/
class CompositeCommands : public std::vector<BankAccountCommand>,
                          public Command {
public:
  CompositeCommands(const std::initializer_list<BankAccountCommand> &list);
  ~CompositeCommands() = default;
  void call() override;
  void undo() override;
};

class MoneyTransaction : public CompositeCommands {
private:
  BankAccount &from;
  BankAccount &to;
  int amount;

public:
  MoneyTransaction(BankAccount &from, BankAccount &to, int amount);
  ~MoneyTransaction() = default;
};

class ReliableMoneyTransaction : public CompositeCommands {
public:
  ReliableMoneyTransaction(BankAccount &from, BankAccount &to, int amount);
  ~ReliableMoneyTransaction() = default;
  void call() override;
};
