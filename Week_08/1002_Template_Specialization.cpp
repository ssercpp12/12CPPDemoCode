#include <cstring>

template<typename T>
bool gt(T a, T b) {
  return a > b;
}

template<typename T>
bool gt(T* a, T* b) {
  return gt(*a, *b);
}

template<>
bool gt(char* a, char* b) {
  return strcmp(a, b) > 0;
}
