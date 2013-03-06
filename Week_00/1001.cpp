// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
 public:
  Date(int year, int month, int day)
    : year_(year),
      month_(month),
      day_(day) {}
  int GetWeekday() const;

 private:
  int year_;
  int month_;
  int day_;

  bool isLeapyear() const;
  bool isValid() const;
};

int Date::GetWeekday() const {
  if (!isValid())
    return -1;

  int t = static_cast<int>((12 - month_) / 10);
  // This is just a formula.
  int x = year_ + static_cast<int>((year_ - t) / 4)
      - static_cast<int>((year_ - t) / 100)
      + static_cast<int>((year_ - t) / 400)
      + static_cast<int>((month_ + 1) * (2.6 + t))
      + day_ - 1;

  int re = x % 7;
  if (re == 0)
    re = 7;
  return re;
}

bool Date::isLeapyear() const {
  return (year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0;
}

bool Date::isValid() const {
  if (month_ <= 0 || month_ > 12)
    return false;

  isLeapyear() ? days[1] = 29 : days[1] = 28;
  if (day_ <= 0 || day_ > days[month_ -1])
    return false;

  return true;
}
