#ifndef BOOKSELLER_H_
#define BOOKSELLER_H_

#include <string>
#include "Book.h"
#include <vector>
#include <iostream>
using namespace std;

class BookSeller {
  private:
    std::string shopName;
    double cashBalance;
    //empty vector of book collection, stores the instance rather than the address
    std::vector<Book*> collection; 
  public:
    BookSeller(const std::string &shopName, double initialBalance);
    std::string getShopName() const;
    int totalNumberOfBooks() const;
    int getBalance() const;
    void purchaseStock(Book *book);
    Book* retrieveBookFromID(int id) const;
    bool scanAndSellBook(int id);
    int totalNumberOfUnsoldBooks() const;
    Book* searchKeyword(const std::string &keyword) const;
    int sellAllCopiesOfBook(Book *book);
    virtual ~BookSeller();
};
#endif /* BOOKSELLER_H_ */