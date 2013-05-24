// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

class Student {
 public:
  Student(const std::string& name, int id) : name_(name), id_(id) {
    count++;
  }

  ~Student() {
    count--;
  }

  const std::string& GetName() const {
    return name_;
  }

  int GetId() const {
    return id_;
  }

  static int count;

 private:
  std::string name_;
  int id_;
};

int Student::count = 0;

class Group {
 public:
  Group(std::string group_name) : group_name_(group_name) {}
  void AddStudent(Student* student) {
    for (int i = 0; i < students_.size(); ++i) {
      if (students_[i] == student)
        return;
    }
    students_.push_back(student);
  }

  void RemoveStudentByName(const std::string& name) {
    for (int i = 0 ; i < students_.size(); ++i) {
      if (students_[i]->GetName() == name)
        students_.erase(students_.begin() + i);
    }
  }

  void RemoveStudentById(int id) {
    for (int i = 0 ; i < students_.size(); ++i) {
      if (students_[i]->GetId() == id)
        students_.erase(students_.begin() + i);
    }
  }

  int GetNumberOfStudents() {
    return students_.size();
  }

  const std::string& GetGroupName() const {
    return group_name_;
  }

 private:
  std::vector<Student*> students_;
  std::string group_name_;
};
