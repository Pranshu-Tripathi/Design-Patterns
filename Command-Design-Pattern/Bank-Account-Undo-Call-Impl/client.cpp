#include "bank_account.h"
#include "commands.h"
#include <vector>

int main() {
  BankAccount account{1000, -500};
  std::vector<Command *> commands = {
      new BankAccountCommand{account, 500, BankAccountOpeartion::WITHDRAW},
      new BankAccountCommand{account, 100, BankAccountOpeartion::DEPOSIT},
      new BankAccountCommand{account, 1000, BankAccountOpeartion::WITHDRAW},
      new BankAccountCommand{account, 200, BankAccountOpeartion::WITHDRAW},
      new BankAccountCommand{account, 500, BankAccountOpeartion::DEPOSIT}};

  for (const auto command : commands) {
    command->call();
  }
  std::reverse(commands.begin(), commands.end());
  for (const auto rev_command : commands) {
    rev_command->undo();
  }

  std::cout << account.to_string() << std::endl;
}
