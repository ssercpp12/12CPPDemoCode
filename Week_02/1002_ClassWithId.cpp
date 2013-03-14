// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

///////////////////// The code which should submit //////////////////////
#include <iostream>
using namespace std;

int counter = 0;

class ClassWithCounter {
 public:
  ClassWithCounter();
  ~ClassWithCounter();

 private:
  int id;
};

ClassWithCounter::ClassWithCounter() {
  id = counter;
  counter++;
  cout << "ClassWithCounter::ClassWithCounter(): " << id << endl;
}

ClassWithCounter::~ClassWithCounter() {
  cout << "ClassWithCounter::~ClassWithCounter(): " << id << endl;
}

///////////////////// framework code to test your code. //////////////////////
int main(int argc, char *argv[]) {
  ClassWithCounter cwc_0;
  ClassWithCounter *ptr_cwc_2;
  {
    ClassWithCounter cwc_1;
    ptr_cwc_2 = new ClassWithCounter;
  }

  delete ptr_cwc_2;
  return 0;
}
