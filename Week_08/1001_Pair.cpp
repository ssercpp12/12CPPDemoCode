#include <iostream>
#include <algorithm>
using namespace std;

template<class T1, class T2>
class Pair
{
  public:
    Pair() {};
    Pair(T1 a, T2 b);
    void setFirst(T1 a);
    void setSecond(T2 b);
    T1 getFirst();
    T2 getSecond();
    void swap(Pair &b);
  private:
    T1 first;
    T2 second;
};

template<class T1, class T2>
Pair<T1,T2>::Pair(T1 a, T2 b) {
  first = a;
  second = b;
}

template<class T1, class T2>
void Pair<T1,T2>::setFirst(T1 a) {
  first = a;
}

template<class T1, class T2>
void Pair<T1,T2>::setSecond(T2 b) {
  second = b;
}

template<class T1, class T2>
T1 Pair<T1,T2>::getFirst() {
  return first;
}

template<class T1, class T2>
T2 Pair<T1,T2>::getSecond() {
  return second;
}

template<class T1, class T2>
void Pair<T1,T2>::swap(Pair &b) {
  std::swap(first,b.first);
  std::swap(second,b.second);
}
