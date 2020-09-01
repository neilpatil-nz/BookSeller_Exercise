#include "BookSeller.h"
#include <iostream>
using namespace std;

BookSeller::BookSeller(const std::string &shopName, double initialBalance){
  this->shopName = shopName;
  cashBalance = initialBalance;
}

std::string BookSeller::getShopName() const{
  return shopName;
}

int BookSeller::getBalance() const{
  return cashBalance;
}

void BookSeller::purchaseStock(Book *book){
  cashBalance = book->getcostPrice();
  collection.push_back(book);
}

int BookSeller::totalNumberOfBooks() const{
  return size(collection);
}

Book* BookSeller::retrieveBookFromID(int id) const {
  for (int i = 0; i < size(collection); i++){
    if (i == id){
      //my way
      return collection[i];
      // Nasser's way
      Book *book = collection[i];
      int bookID = book->getID();

      if (bookID == id){
        return book;
      }
    }
  }
  return 0;
}

bool BookSeller::scanAndSellBook(int id){
  Book* result = retrieveBookFromID(id);
  if (result == 0 || result->isSold()){
    return false;
  }
  result->setSold();
  cashBalance = cashBalance + result->getsalePrice();
  return true;
}

int BookSeller::totalNumberOfUnsoldBooks() const{
  int countUnsold = 0;
  for (int i = 0; i <  collection.size(); i++){
    if (!(retrieveBookFromID(i)->isSold())){
      countUnsold++;
    }
  }
  return countUnsold;
}

Book* BookSeller::searchKeyword(const std::string &keyword) const{
  for (int i = 0; i <  collection.size(); i++){
    std::size_t found = retrieveBookFromID(i)->getTitle().find(keyword);
    if (found != std::string::npos){
      cout << "Book found" << endl;
      return collection[i];
    }
  }
  cout << "Book not found" << endl;
  return 0;
}

int BookSeller::sellAllCopiesOfBook(Book *bookTryingToSell){
  int copies = 0;

  for (int i = 0; i <  collection.size(); i++){
    Book *book = collection[i];
    
    if(*book == *bookTryingToSell){
      bool successfullySold = scanAndSellBook(collection[i]->getID());
      
      if(successfullySold){
        cout << "One copy sold" <<endl << endl;
        copies++;
      }
    }
  }

  return copies;
}

BookSeller::~BookSeller(){

}