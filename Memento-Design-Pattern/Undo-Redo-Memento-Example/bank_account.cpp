#include "bank_account.h"
#include <memory>
#include <sstream>
#include <string>

Memento::Memento(int balance) : balance(balance) {}

BankAccount::BankAccount(int balance) : balance(balance) { save_snapshot(); }

void BankAccount::withdraw(int amount) {
  if (balance >= amount) {
    balance -= amount;
    save_snapshot();
  }
}

void BankAccount::deposit(int amount) {
  balance += amount;
  save_snapshot();
}

void BankAccount::restore(std::shared_ptr<Memento> &state) {
  if (state) {
    balance = state->balance;
    save_snapshot();
  }
}

void BankAccount::save_snapshot() {
  auto state = std::make_shared<Memento>(balance);
  states.push_back(state);
  current_state = static_cast<int>(states.size() - 1);
}

void BankAccount::undo() {
  if (current_state > 0) {
    balance = states[--current_state]->balance;
  }
}

void BankAccount::redo() {
  if (current_state + 1 < static_cast<int>(states.size())) {
    balance = states[++current_state]->balance;
  }
}

std::string BankAccount::to_string() const {
  std::ostringstream oss;
  oss << "Account Balance = [" << std::to_string(balance) << "]" << std::endl;
  return oss.str();
}
