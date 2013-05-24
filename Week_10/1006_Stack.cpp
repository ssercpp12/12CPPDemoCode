// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

template<typename T, int capacity>
class Stack {
 public:
  Stack();
  bool empty() const;
  ResultCode pop();
  ResultCode top(T& item) const;
  ResultCode push(const T& item);

 private:
  int count_;
  T entry_[capacity];
};

template<typename T, int capacity>
Stack<T, capacity>::Stack() : count_(0) {}

template<typename T, int capacity>
bool Stack<T, capacity>::empty() const {
  return count_ == 0;
}

template<typename T, int capacity>
ResultCode Stack<T, capacity>::pop() {
  if (count_ <= 0)
    return underflow;
  count_--;
  return success;
}

template<typename T, int capacity>
ResultCode Stack<T, capacity>::top(T &item) const {
  if (count_ == 0)
    return underflow;
  item = entry_[count_ - 1];
  return success;
}

template<typename T, int capacity>
ResultCode Stack<T, capacity>::push(const T& item) {
  if (count_ >= capacity)
    return overflow;
  entry_[count_++] = item;
  return success;
}
