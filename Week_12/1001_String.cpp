// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#define SIZE 1000

class String {
 public:
  //通过char数组指针来初始化String对象，深复制！你懂的
  String(const char* str);
  //拷贝构造函数
  String(const String& s);
  ~String();
  //字符串拼接，例如："abc" + "def" 结果是"abcdef"
  String operator+(const String& s);
  //=号赋值，记得拷贝构造函数跟=号差别~
  String& operator=(const String& s);
  //以下三个是比较操作符，用于比较字符串的字典序
  bool operator==(const String& s);
  bool operator<(const String& s);
  bool operator>(const String& s);
  //取出字符串的第n位, n 保证合法
  //String str("abc");str[0]为a，str[1]为b；
  //切记此话：注意当上边的str做以下赋值：str[1] = '\0'时，str实际上是字符串"a"，
  //长度为1，因为字符串是以\0结束的
  char& operator[](const int& n);

  //获取字符串的长度
  int size() const;

  //输出重载 记得末尾是不需要空行的！
  friend ostream& operator<<(ostream& out, const String& s);

 private:
  // String里边实现实际也是一个char指针，但是我们通过类将它封装得更好用了！
  char *cstr;
};

String::String(const char* str) {
  cstr = new char[SIZE];
  strcpy(cstr, str);
}

String::String(const String& s) {
  cstr = new char[SIZE];
  strcpy(cstr, s.cstr);
}

String::~String() {
  delete []cstr;
}

String String::operator+(const String& s) {
  String tmp = *this;
  strcat(tmp.cstr, s.cstr);
  return tmp;
}

String& String::operator=(const String& s) {
  strcpy(cstr, s.cstr);
  return *this;
}

bool String::operator==(const String& s) {
  return strcmp(cstr, s.cstr) == 0;
}

bool String::operator<(const String& s) {
  return strcmp(cstr, s.cstr) < 0;
}

bool String::operator>(const String& s) {
  return strcmp(cstr, s.cstr) > 0;
}

char& String::operator[](const int& n) {
  return cstr[n];
}

int String::size() const {
  return strlen(cstr);
}

ostream& operator<<(ostream& out, const String& s) {
  out << s.cstr;
  return out;
}
