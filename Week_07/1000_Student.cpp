/* copyright(c) Jianhong Li, all rights reserved. */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
  public:
    static int count();
    Student() {}
    Student(string, int, string);
    virtual void print();
    string get_name();
    int get_age();
    string get_id();
  protected:
    string name_;
    int age_;
    string student_id_;
  private:
    static int total;
};

int Student::total = 0;
int Student::count() {
  return total;
}

Student::Student(string name, int age, string student_id)
  : name_(name),
    age_(age),
    student_id_(student_id) {
  total++;
}

inline string Student::get_name() {
  return name_;
}

inline int Student::get_age() {
  return age_;
}

inline string Student::get_id() {
  return student_id_;
}

void Student::print() {
  cout << "This is " << name_ << ':' << endl;
  cout << age_ << endl;
  cout << student_id_ << endl;
}

class Leader: public Student {
  public:
    Leader(string, int, string, int);
    Leader& addMember(Student&);
    void print();
  private:
    int group_id_;
    int group_size_;
    vector<Student*> member;
};

Leader::Leader(string name, int age, string student_id, int group_id)
  : Student(name, age, student_id),
    group_id_(group_id) {
    group_size_ = 0;
}

Leader& Leader::addMember(Student& other) {
  member.push_back(&other);
  group_size_++;
  return *this;
}

void Leader::print() {
  cout << "This is " << name_ << ':' << endl;
  cout << age_ << endl;
  cout << student_id_ <<endl;
  cout << group_id_ << endl;
  if ( group_size_ != 0 )
    cout << "Members:" << endl;
  for (int i = 0; i < group_size_; i++)
    cout << member[i]->get_name() << endl;
}
