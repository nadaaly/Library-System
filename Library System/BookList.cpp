#include <iostream>
#include "BookList.h"
#include "UserList.h"
#include "Book.h"
#include "User.h"
using namespace std;

int BookList::counter=0;
int BookList::b=0;

BookList::BookList(int capacity)  // a parameterized constructor that sets the capacity to our private int value
                                  // as well as defining the array dynamically.
{
    this -> capacity = capacity;
    books = new Book[capacity];
}
BookList::BookList(const BookList& anotherList) // copy constructor that works as a member assignment for copying
                                                // the dynamic array into another one
{
    books=anotherList.books;

}
void BookList::addBook(Book book)  // function that helps in adding books to the array written in by the user
{
        books[booksCount] = book;
        booksCount++;
        b=booksCount;
}

void BookList::updateBook(Book &book) {

    books[book.getId()-1]=book;
    indOfAuthor[counter]=(book.getId()-1);
    counter++;

}

Book& BookList::searchBook(string name)  // search for a certain book using its name and then having to either
                                         // assign it to a certain author or continue with the demo
{
    for (int counter = 0 ; counter <booksCount ; counter++)
    {
        if( books[counter].getTitle() == name)
        {
            idDelete = books[counter].getId();
            return books[counter];
        }

    }
}
Book& BookList::searchBook(int id)    // search for a certain book using its id and then having to either
                                      // assign it to a certain author or continue with the demo

{
    for (int counter = 0 ; counter <booksCount ; counter++)
    {
        if( books[counter].getId() == id)
        {
            idDelete = books[counter].getId();
            return books[counter];
        }

    }
}
void BookList::deleteBook(int id)  // a function that deletes a certain book determined by its id that is
                                    // written by whoever uses the program
{
    for (int counter = 0 ; counter <booksCount ; counter++)
    {
        if( books[counter].getId() == id)
        {
            books[counter] = books[counter+1];
            booksCount--;
        }

    }
}
Book BookList::getTheHighestRatedBook()  //function that print out the book with the highest rating
{
    int i,c;
    Book maxi;
    for (int i = 0 ; i<booksCount ; i++)
    {
        if(maxi.getRate() < books[i].getRate())
        {
            c=i;
        }
    }
    return books[c];


}

Book* BookList::getBooksForUser(User user) // get all books of this author
{
    int booksofUser = 0;
    Book* UserBooks = new Book[booksCount];
    for(int counter = 0; counter<booksCount ; counter++)
    {
        if (books[counter].getAuthor() == user)
        {
            UserBooks[booksofUser] = books[counter];
            booksofUser++;
        }
    }
    return UserBooks;

}
Book& BookList::operator [ ] (int position) // helps in printing a specific element by the "position" variable that is passed to it
{
    if(position<0 || position> booksCount)
    {
        cout<<"Try again"<<endl;
        exit(0);
    }
    else
    {
        return books[position];
    }
}
ostream &operator<<( ostream &output, BookList &booklist ) //to display all books
{
    for (int counter=0 ; counter<booklist.booksCount ; counter++)
    {
        output<<booklist.books[counter]<<endl;
        if(counter==booklist.indOfAuthor[counter]&&booklist.indOfAuthor[counter]!=1000)
            output<<booklist.books[counter].getAuthor();
    }
}

void BookList::anotherUpdate(Book &book) {
    books[book.getId()-1].setAuthor(book.getAuthor());
    books[book.getId()-1].setBookAuthor(book.getBookAuthor());
}
void BookList::updateTitle(Book &book) {
    books[book.getId()-1].setTitle(book.getTitle());
}
void BookList::updateCategory(Book &book) {
    books[book.getId()-1].setCategory(book.getCategory());
}
void BookList::updateRate(Book &book) {
    books[book.getId()-1].rateBook(book.getRate());
}

int BookList::biggestId()  // function that helps to get the greatest id to help in getTheHighestRatedBook() function
{
    int big = books[0].getId();

    for (int i = 0; i < booksCount; i++) {

        if (books[i].getId() > books[i + 1].getId())
        {
            big = books[i].getId();
        }
        else {
            big= books[i + 1].getId();
        }
    }
    return big;
}

/*
BookList::~BookList() // destructor that deletes the dynamic array to help the memory
{                       // let the the user name to turn into garbage
    delete [] books;
}
*/
