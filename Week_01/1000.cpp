// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
  int id;
  double height;
  int count = 0;
  while (cin >> id >> height) {
    cout << count << " ";
    cout << setw(8) << setfill('0') << id << " ";
    cout << fixed;
    cout << setprecision(2) << height << endl;
    count++;
  }

  return 0;
}

