#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED
#include "BookList.h"
#include "Book.h"
#include "User.h"
class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount;
public:
    static int counter,b;
    int indOfAuthor[100000];
    int biggestId(); // new fun to get number of books
    int idDelete;
    void addBook(Book book);
    BookList(const BookList& anotherList);
    BookList(int capacity);
    Book& searchBook(string name);
    Book& searchBook(int id);
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User); // get all books of this author
    Book & operator [ ] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books

   void updateBook(Book &book);
    void anotherUpdate(Book &book);
    void updateTitle(Book &book);
    void updateCategory(Book &book);
    void updateRate(Book &book);
    //~BookList();       // let the the user name to turn into garbage


};
#endif
