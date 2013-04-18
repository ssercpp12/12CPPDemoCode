/* copyright(c) Jianhong Li, all rights reserved. */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
  string name;
  string phone_number;
  bool operator<(const Person& other) const {
    if (name != other.name)
      return name < other.name;
    else
      return phone_number < other.phone_number;
  }
};

class PhoneBook {
  public:
    PhoneBook();
    PhoneBook(const Person[], int);
    PhoneBook(const PhoneBook&);
    ~PhoneBook();
    PhoneBook& operator=(const PhoneBook&);
    void set(int i, const Person&);
    bool operator==(const PhoneBook&) const;
    void print() const;
  private:
    Person *p;
    int size_;
};


PhoneBook::PhoneBook() {
  size_ = 0;
}

PhoneBook::PhoneBook(const Person p_array[], int size) : size_(size) {
  p = new Person[size_];
  for (int i = 0; i < size_; i++)
    p[i] = p_array[i];
}

PhoneBook::PhoneBook(const PhoneBook& other) {
  size_ = other.size_;
  p = new Person[size_];
  for (int i = 0; i < size_; i++)
    p[i] = other.p[i];
}

PhoneBook::~PhoneBook() {
  delete []p;
}
void PhoneBook::set(int i, const Person& person) {
  if (i < size_ && i >= 0)
    p[i] = person;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
  size_ = other.size_;
  delete []p;
  p = new Person[size_];
  for (int i = 0; i < size_; i++)
    p[i] = other.p[i];
  return *this;
}

bool PhoneBook::operator==(const PhoneBook& other) const {
  if (size_ != other.size_)
    return false;
  for (int i = 0; i < size_; i++)
    if (p[i].name != other.p[i].name ||
        p[i].phone_number != other.p[i].phone_number)
      return false;
  return true;
}

void PhoneBook::print() const {
  Person *tmp;
  tmp = new Person[size_];
  for ( int i = 0; i < size_; i++)
    tmp[i] = p[i];
  sort(tmp, tmp + size_);
  for (int i = 0; i < size_; i++)
    cout << tmp[i].name << ' ' << tmp[i].phone_number << endl;
  delete []tmp;
}
