#include "bank_account.h"
#include "composite_commands.h"
#include <iostream>

int main() {
  BankAccount sender{5000, -1000};
  BankAccount reciever{100, -500};

  MoneyTransaction transaction(sender, reciever, 1000);
  transaction.call();
  std::cout << sender.to_string() << std::endl;
  std::cout << reciever.to_string() << std::endl;
  transaction.undo();
  std::cout << sender.to_string() << std::endl;
  std::cout << reciever.to_string() << std::endl;

  /*
  In MoneyTranscation failure is not handled correctly.
  If withdraw fails it dosn't stop the deposit.
  See the Example below
  */
  MoneyTransaction incorrect_transaction{sender, reciever, 9000};
  incorrect_transaction.call();
  std::cout << sender.to_string() << std::endl;
  std::cout << reciever.to_string() << std::endl;

  BankAccount sender_new{5000, -1000};
  BankAccount reciever_new{500, -500};

  ReliableMoneyTransaction reliable_transaction{sender_new, reciever_new, 9000};
  reliable_transaction.call();
  std::cout << sender_new.to_string() << std::endl;
  std::cout << reciever_new.to_string() << std::endl;
}
