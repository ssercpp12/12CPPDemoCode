#include <iostream>
using namespace std;

int y, m, d;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapyear() {
  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    return true;
  return false;
}

bool isValid() {
  if (m <= 0 || m > 12)
    return false;

  if (isLeapyear())
    days[1] = 29;
  else
    days[1] = 28;
  if (d <= 0 || d > days[m - 1])
    return false;

  return true;
}

int getWeekday() {
  if (!isValid())
    return -1;
  int t = (int)((12 - m) / 10);
  // This is just a formula.
  int x = y
          + (int)((y - t) / 4)
          - (int)((y - t) / 100)
          + (int)((y - t) / 400)
          + (int)((m + 1) * (2.6 + t))
          + d - 1;
  int re = x % 7;
  if (re == 0)
    re = 7;
  return re;
}

int main(int argc, char *argv[])
{
  while (cin >> y >> m >> d && y != 0) {
    cout << getWeekday() << endl;
  }

  return 0;
}
