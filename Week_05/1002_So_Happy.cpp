#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(int argc, const char* argv[]) {
  string s;
  int b;
  cin >> s;
  cin >> b;
  int len = s.size();
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    *it = tolower(*it);
  for (string::iterator it = s.begin(); it != s.end(); ++it)
    *it = (*it < b + 'a') ? toupper(*it) : *it;
  cout << s << endl;
  return 0;
}
