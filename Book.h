#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
using namespace std;
#include <string>

class Book {
private: 
    std::string title;
    std::string author;
    double costPrice;
    double salePrice;
    int year;
    
    bool sold;
    int id;
public:
    Book(const std::string &title,  const std::string &author, double costPrice, double salePrice, int year);
    std::string getTitle() const;
    std::string getAuthor() const;
    double getcostPrice() const;
    double getsalePrice() const;
    int publicationYear() const;
    bool isSold() const;
    int getID() const;
    bool operator==(const Book &other) const;
    void setSold();
    virtual ~Book();
};

#endif /* BOOK_H_ */