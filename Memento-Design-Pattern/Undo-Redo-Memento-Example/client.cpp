#include "bank_account.h"
#include <iostream>
int main() {

  BankAccount account{100};

  account.deposit(30);
  std::cout << account.to_string() << std::endl;
  account.deposit(20);
  std::cout << account.to_string() << std::endl;
  account.withdraw(80);
  std::cout << account.to_string() << std::endl;

  account.undo();
  std::cout << account.to_string() << std::endl;
  account.undo();
  std::cout << account.to_string() << std::endl;
  account.redo();
  std::cout << account.to_string() << std::endl;
}
