#include <iostream>
using namespace std;

class Book {
  public:
    Book() : price_(0) {}
    Book(double price, std::string name);
    /* return the original price of a book */
    double GetPrice() const;
    std::string GetName() const;
  protected:
    double price_;
  private:
    std::string name_;
};

class PYBook : public Book{
  public:
    // assigning default value of discount_ to 1 is better
    PYBook() : Book(), discount_(1) {}
    PYBook(double price, std::string name, double discount);
    /*
     * return the price with discount of a book
     * the new price = orig. price * discount
     */
    double GetPrice() const;
  private:
    double discount_;
};

class StupidCow {
  public:
    /* PY stand on the street and shout:
     * "We are selling xxx" xxx for book name
     * "It's not yyy" yyy for orig. price
     * "It's zzz" zzz for price with discount
     */
    static void Shout(const PYBook &book);
};

void StupidCow::Shout(const PYBook &book) {
  cout << "We are selling " << book.GetName() << endl;
  cout << "It's not " << book.Book::GetPrice() << endl;
  cout << "It's " << book.GetPrice() << endl;
}

Book::Book(double price, std::string name) : price_(price), name_(name) {}

std::string Book::GetName() const {
  return name_;
}

PYBook::PYBook(double price, std::string name, double discount)
    : Book(price, name), discount_(discount) {}

    double Book::GetPrice() const {
      return price_;
    }

double PYBook::GetPrice() const {
  return discount_ * price_;
}

int main(int argc, const char *argv[]) {
  PYBook a(997.0, "The Art of Computer Programming", 0.65);
  StupidCow::Shout(a);
  return 0;
}
