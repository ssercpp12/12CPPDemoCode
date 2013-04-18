/* copyright(c) Jianhong Li, all rights reserved. */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
class Base {
  protected:
    double result, a, b, step;
    int n;
  public:
    virtual double fun(double x) = 0;
    virtual void integrate() {}
    Base(double aa = 0, double bb = 0, int nn = 100) :
      a(aa), b(bb), n(nn), result(0.0) {}
    void print() {
      cout << result << endl;
    }
};

class Rectangle :public Base {
  public:
    Rectangle(double aa, double bb, int nn)
      : Base(aa, bb, nn) {
        step = (b-a)/n;
    }
    double fun(double x);
    void integrate();
};

double Rectangle::fun(double x) {
  return sin(x);
}

void Rectangle::integrate() {
  double s = 0;
  for (int i = 0; i <= n; i++)
    s += fun(a + i * step);
  result = step*s;
}

class Ladder :public Base {
  public:
    Ladder(double aa, double bb, int nn)
      : Base(aa, bb, nn) {
      step = (b - a) / n;
    }
    double fun(double x);
    void integrate();
};

double Ladder::fun(double x) {
  return sin(x);
}

void Ladder::integrate() {
  double s = 0;
  for (int i = 1; i < n; i++)
    s += this->fun(a + i * step);
  result = step / 2.0* (2 * s + fun(a) + fun(b));
}

class Simpson :public Base {
  public:
    Simpson(double aa, double bb, int nn)
      : Base(aa, bb, nn) {
      step = (b - a) / n;
    }
    double fun(double x);
    void integrate();
};

double Simpson::fun(double x) {
  return sin(x);
}

void Simpson::integrate() {
  double s1 = 0, s2 = 0;
  for (int i = 1; i < n; i++)
    if (i % 2 == 0)
      s1 += fun(a + i * step);
    else
      s2 += fun(a + i * step);
  result = step / 3.0 * (2 * s1 + 4 * s2 + fun(a) + fun(b));
}
