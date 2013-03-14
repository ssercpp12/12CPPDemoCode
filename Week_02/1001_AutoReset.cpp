// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <iostream>

///////////////////// The code which should submit //////////////////////
class AutoReset {
 public:
  AutoReset(int *scoped_variable, int new_value);
  ~AutoReset();

 private:
  int *scoped_variable_;
  int original_value_;
};

AutoReset::AutoReset(int *scoped_variable, int new_value)
    : scoped_variable_(scoped_variable),
      original_value_(*scoped_variable) {
  *scoped_variable_ = new_value;
}

AutoReset::~AutoReset() {
  *scoped_variable_ = original_value_;
}

///////////////////// framework code to test your code. //////////////////////
int main(int argc, char *argv[]) {
  int value;
  int count = 0;

  while (std::cin >> value) {
    {
      AutoReset auto_reset(&value, count);
      value += count;
      count++;
    }
    std::cout << value << std::endl;
  }
}
