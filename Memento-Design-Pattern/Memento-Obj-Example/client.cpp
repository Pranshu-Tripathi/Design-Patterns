#include "bank_account.h"
#include <iostream>

int main() {
  BankAccount account{100};

  auto checkpoint1 = account.deposit(30);
  std::cout << account.to_string() << std::endl;
  auto checkpoint2 = account.withdraw(200);
  std::cout << account.to_string() << std::endl;
  auto checkpoint3 = account.withdraw(40);
  std::cout << account.to_string() << std::endl;
  auto checkpoint4 = account.deposit(20);
  std::cout << account.to_string() << std::endl;

  account.restore(checkpoint1);
  std::cout << account.to_string() << std::endl;
  account.restore(checkpoint2);
  std::cout << account.to_string() << std::endl;
  account.restore(checkpoint3);
  std::cout << account.to_string() << std::endl;
  account.restore(checkpoint4);
  std::cout << account.to_string() << std::endl;
}
