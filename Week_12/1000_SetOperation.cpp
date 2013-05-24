// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

class SetOperation {
 public:
  SetOperation(int a[], int s1, int b[], int s2);
  set<int> Union();
  set<int> Intersetion();

 private:
  set<int> arrayA_;
  set<int> arrayB_;
};

SetOperation::SetOperation(int a[], int s1, int b[], int s2) {
  arrayA_.insert(a, a + s1);
  arrayB_.insert(b, b + s2);
}

set<int> SetOperation::Union() {
  set<int> s(arrayA_);
  s.insert(arrayB_.begin(), arrayB_.end());
  return s;
}

set<int> SetOperation::Intersetion() {
  set<int> s;
  set<int>::iterator it;
  for (it = arrayB_.begin(); it != arrayB_.end(); it++) {
    if (arrayA_.find(*it) != arrayA_.end())
      s.insert(*it);
  }

  return s;
}
