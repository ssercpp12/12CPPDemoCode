// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <map>
#include <string>

using namespace std ;

class Array {
 public:
  int& operator[](const string &) ;
  int& operator[]( int ) ;
 private:
  map<int, int> array_a_;
  map<string, int> array_b_;
};

int& Array::operator[](const string& index) {
  return array_b_[index];
}

int& Array::operator[](int index) {
  return array_a_[index];
}
