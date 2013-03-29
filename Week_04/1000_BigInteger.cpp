// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <iostream>
using namespace std;

///////////////////// The code which should submit //////////////////////
class BigInteger {
 public:
  BigInteger(int* data, int size);
  BigInteger(const BigInteger &other);
  int getBitByPos(int pos) const;

  ~BigInteger();

 private:
  int* data_;
  int size_;
};

BigInteger::BigInteger(int *data, int size) : size_(size) {
  data_ = new int[size_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = data[i];
  };
}

BigInteger::BigInteger(const BigInteger &other) {
  size_ = other.size_;
  data_ = new int[size_];
  for (int i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

BigInteger::~BigInteger() {
  delete []data_;
}

int BigInteger::getBitByPos(int pos) const {
  return data_[pos];
}

///////////////////// framework code to test your code. //////////////////////
#define MAX 1000

int main(int argc, char *argv[]) {
  int arr[MAX];
  for (int i = 0; i < MAX; ++i) {
    arr[i] = i % 10;
  }

  for (int i = 0; i < MAX ; ++i) {
    BigInteger bi_1(arr, MAX);
    BigInteger bi_2 = bi_1;
    arr[10] = 100;
    if (bi_1.getBitByPos(10) == 100) {
      cout << "0" << endl;
    }

    arr[10] = 0;
  }

  return 0;
}
