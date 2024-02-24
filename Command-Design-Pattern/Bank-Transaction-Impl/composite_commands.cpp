#include "composite_commands.h"
#include "bank_account.h"
#include "commands.h"
#include <initializer_list>
#include <stack>
#include <vector>

CompositeCommands::CompositeCommands(
    const std::initializer_list<BankAccountCommand> &list)
    : std::vector<BankAccountCommand>(list) {}

void CompositeCommands::call() {
  for (auto &command : *this) {
    command.call();
  }
}

void CompositeCommands::undo() {
  for (auto it = rbegin(); it != rend(); ++it) {
    it->undo();
  }
}

MoneyTransaction::MoneyTransaction(BankAccount &from, BankAccount &to,
                                   int amount)
    : CompositeCommands(
          {BankAccountCommand{from, amount, BankAccountOpeartion::WITHDRAW},
           BankAccountCommand{to, amount, BankAccountOpeartion::DEPOSIT}}),
      from{from}, to{to}, amount{amount} {}

ReliableMoneyTransaction::ReliableMoneyTransaction(BankAccount &from,
                                                   BankAccount &to, int amount)
    /*
    Transaction done in halves just to check the reliability of this approach
     */
    : CompositeCommands(
          {BankAccountCommand{from, amount / 2, BankAccountOpeartion::WITHDRAW},
           BankAccountCommand{to, amount / 2, BankAccountOpeartion::DEPOSIT},
           BankAccountCommand{from, amount / 2, BankAccountOpeartion::WITHDRAW},
           BankAccountCommand{to, amount / 2, BankAccountOpeartion::DEPOSIT}}) {
}

void ReliableMoneyTransaction::call() {
  std::stack<BankAccountCommand> commands_processed;
  for (auto &command : *this) {
    command.call();
    auto status = command.command_return_status();
    if (not status) {
      while (not commands_processed.empty()) {
        auto revert_command = commands_processed.top();
        revert_command.undo();
        commands_processed.pop();
      }
      break;
    }
    commands_processed.push(command);
  }
}
