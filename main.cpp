#include "BookSeller.h"
#include "Book.h"
#include <iostream>
using namespace std;

int main() {
  
  BookSeller shop("Books r Us", 100);

  cout << "Name: " << shop.getShopName() << endl;
  cout << "Balance: $" << shop.getBalance() << endl;
  

  Book *book1 = new Book("Harry Potter", "JK Rowling", 40, 50, 1996);
  
   // -> because its book1 is a pointer
  cout << "Title: " << book1->getTitle() << endl;
  cout << "Author: " << book1->getAuthor() << endl;
  cout << "Cost Price: $" << book1->getcostPrice() << endl;
  cout << "Sale Price: $" << book1->getsalePrice() << endl;
  cout << "Publication Year: " << book1->publicationYear() << endl;
  cout << "ID: " << book1->getID() << endl;

  if (book1->isSold()){
    cout << "its SOLD" << endl;
  }else{
    cout << "not SOLD" << endl;
  }

  cout << endl << endl;

  Book *book2 = new Book("Harry Potter and the Prisoner of Azkaban", "JK Rowling", 50, 80, 2000);

  Book *book3 = new Book("Harry Potter and the Goblet of Fire", "JK Rowling", 60, 100, 2004);

   Book *book4 = new Book("Harry Potter", "JK Rowling", 40, 50, 1996);

   // -> because its book1 is a pointer
  cout << "Title: " << book2->getTitle() << endl;
  cout << "Author: " << book2->getAuthor() << endl;
  cout << "Cost Price: $" << book2->getcostPrice() << endl;
  cout << "Sale Price: $" << book2->getsalePrice() << endl;
  cout << "Publication Year: " << book2->publicationYear() << endl;
  cout << "ID: " << book2->getID() << endl;
  if (book2->isSold()){
    cout << "its SOLD" << endl;
  }else{
    cout << "not SOLD" << endl;
  }

  cout << endl;

  cout << "Title: " << book3->getTitle() << endl;
  cout << "Author: " << book3->getAuthor() << endl;
  cout << "Cost Price: $" << book3->getcostPrice() << endl;
  cout << "Sale Price: $" << book3->getsalePrice() << endl;
  cout << "Publication Year: " << book3->publicationYear() << endl;
  cout << "ID: " << book3->getID() << endl;
  if (book3->isSold()){
    cout << "its SOLD" << endl;
  }else{
    cout << "not SOLD" << endl;
  }
  
  cout << endl << endl;
  shop.purchaseStock(book1);
  shop.purchaseStock(book2);
  shop.purchaseStock(book3);
  shop.purchaseStock(book4);

  cout << "Name: " << shop.getShopName() << endl;
  cout << "Balance: $" << shop.getBalance() << endl;

  cout << endl << endl;
  cout << "Amount of books in collection: " << shop.totalNumberOfBooks()<< endl;

  cout << endl;
  Book* result = shop.retrieveBookFromID(1);

  if (result != 0){
    cout << "Book ID Found: "<< (shop.retrieveBookFromID(1))->getTitle() << endl;
  }
  else {
    cout << "No book was found with that ID" << endl;
  }
  
  shop.scanAndSellBook(1);
  cout << "Book Sold: " << (shop.retrieveBookFromID(1))->getTitle() << " for $" << (shop.retrieveBookFromID(1))->getsalePrice() << endl ;
  
  cout << "New cash balance: $" << shop.getBalance() << endl << endl;
  if (book1->isSold()){
    cout << "its SOLD" << endl;
  }else{
    cout << "not SOLD" << endl;
  }
  
  

  
  cout << "Books left:" << shop.totalNumberOfUnsoldBooks() << endl;

  std::string keyword = "Prisoner";
  Book* bookSearch = shop.searchKeyword(keyword);
  cout << bookSearch->getTitle();

  cout << endl << endl;
  int numberOfCopiesSold = shop.sellAllCopiesOfBook(book4);

  delete book1;
  delete book2;
  delete book3;
  return 0;
}