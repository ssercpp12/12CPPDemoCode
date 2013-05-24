// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

class Integer {
 public:
  explicit Integer(int value = 0);
  friend istream& operator>>(istream& in, Integer& integer);
  friend ostream& operator<<(ostream& out, const Integer& integer);

  Integer operator+(const Integer& other);
  Integer operator-(const Integer& other);
  Integer operator*(const Integer& other);
  Integer operator/(const Integer& other);

  Integer& operator++();
  Integer operator++(int);
  Integer& operator--();
  Integer operator--(int);

  Integer& operator+=(const Integer& other);
  Integer& operator-=(const Integer& other);

  bool operator==(const Integer& other);
  bool operator!=(const Integer& other);

 private:
  int value_;
};

Integer::Integer(int value) : value_(value) {}

istream& operator>>(istream& in, Integer& integer) {
  in >> integer.value_;
  return in;
}

ostream& operator<<(ostream& out, const Integer& integer) {
  out << integer.value_;
  return out;
}

Integer Integer::operator+(const Integer& other) {
  return Integer(value_ + other.value_);
}

Integer Integer::operator-(const Integer& other) {
  return Integer(value_ - other.value_);
}

Integer Integer::operator*(const Integer& other) {
  return Integer(value_ * other.value_);
}

Integer Integer::operator/(const Integer& other) {
  return Integer(value_ / other.value_);
}

Integer& Integer::operator++() {
  value_ += 1;
  return *this;
}

Integer Integer::operator++(int) {
  int tmp = value_;
  value_ += 1;
  return Integer(tmp);
}

Integer& Integer::operator--() {
  value_ -= 1;
  return *this;
}

Integer Integer::operator--(int) {
  int tmp = value_;
  value_ -= 1;
  return Integer(tmp);
}

Integer& Integer::operator+=(const Integer& other) {
  value_ += other.value_;
  return *this;
}

Integer& Integer::operator-=(const Integer& other) {
  value_ -= other.value_;
  return *this;
}

bool Integer::operator==(const Integer& other) {
  return value_ == other.value_;
}
  
bool Integer::operator!=(const Integer& other) {
  return value_ != other.value_;
}
