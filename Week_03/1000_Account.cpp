// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

///////////////////// The code which should submit //////////////////////
class Account {
 public:
  Account(const string& name);
  Account(const string& name, int balance);
  void deposit(int amount);
  bool withdraw(int amount);
  inline const string& getName() const;
  inline int getBalance() const;

 private:
  string name_;
  int balance_;
};

class AccountManager {
 public:
  static Account* createAccount(const string& name);
  static Account* createAccount(const string& name, int balance);
};

Account::Account(const string& name) : name_(name), balance_(0) {
}

Account::Account(const string& name, int balance)
    : name_(name),
      balance_(balance) {
}

void Account::deposit(int amount) {
  if (amount < 0)
    return;
  balance_ += amount;
}

bool Account::withdraw(int amount) {
  if (amount < 0)
    return false;
  if (balance_ - amount >= 0) {
    balance_ -= amount;
    return true;
  }

  return false;
}

const string& Account::getName() const {
  return name_;
}

int Account::getBalance() const {
  return balance_;
}

// static
Account* AccountManager::createAccount(const string& name) {
  return new Account(name);
}

// static
Account* AccountManager::createAccount(const string& name, int balance) {
  return new Account(name, balance);
}

///////////////////// framework code to test your code. //////////////////////
int main(int argc, char *argv[]) {
  Account* account_ptr = AccountManager::createAccount("py");
  cout << account_ptr->getBalance() << endl;
  cout << account_ptr->withdraw(100) << endl;

  account_ptr->deposit(10000);

  cout << account_ptr->getBalance() << endl;
  cout << account_ptr->withdraw(100) << endl;
  cout << account_ptr->getBalance() << endl;
  cout << account_ptr->getName() << endl;

  account_ptr->deposit(-100);
  account_ptr->withdraw(-100);

  cout << account_ptr->getBalance() << endl;

  delete account_ptr;
  return 0;
}

