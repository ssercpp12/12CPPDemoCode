// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

class Observer {
 public:
  virtual ~Observer() {}
  virtual void notify() = 0;
};

class Subject {
 public:
  void AddObserver(Observer* observer) {
    observers.push_back(observer);
  }

  void RemoveObserver(Observer* observer) {
    for (int i = 0; i < observers.size(); ++i) {
      if (observers[i] == observer)
        observers.erase(observers.begin() + i);
    }
  }
  
  void Change() {
    // Do something.
    notifyObservers();
  }

 private:
  std::vector<Observer*> observers;
  void notifyObservers() {
    for (int i = 0; i < observers.size(); ++i) {
      observers[i]->notify();
    }
  }
};

class ObserverA : public Observer {
 public:
  virtual void notify() {
    std::cout << "ObserverA is notified that Subject change." << std::endl;
  }
};

class ObserverB : public Observer {
 public:
  virtual void notify() {
    std::cout << "ObserverB is notified that Subject change." << std::endl;
  }
};
