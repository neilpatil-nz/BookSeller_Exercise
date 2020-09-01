#include "Book.h"
#include "BookSeller.h"
#include <string>

static int nextAvailableID = 0;

Book::Book(const std::string &title,  const std::string &author, double costPrice, double salePrice, int year) :
title(title), author(author), costPrice(costPrice), salePrice(salePrice), year(year), sold(false){
  
  this->id = nextAvailableID;
  nextAvailableID++;
}

std::string Book::getTitle() const{
  return title;
}

std::string Book::getAuthor() const{
  return author;
}

double Book::getcostPrice() const{
  return costPrice;
}

double Book::getsalePrice() const {
  return salePrice;
}
int Book::publicationYear() const{
  return year;
}

bool Book::isSold() const{
  return sold;
}
void Book::setSold(){
  this->sold = true;
}

int Book::getID() const{
  return id;
}

bool Book::operator==(const Book &other) const{
  bool sameTitle = this->title == other.title;
  bool sameAuthor = this->author == other.author;
  bool sameYear = this->year == other.year;

  return sameTitle && sameAuthor && sameYear;
}

Book::~Book() {
  
}