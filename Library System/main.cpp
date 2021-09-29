#include <iostream>
#include "BookList.h"
#include "UserList.h"
#include "Book.h"
#include "User.h"
#include <cstring>
using namespace std;

int main()
{
    UserList ulist1;
        Book book1;
        User user1;
        int number;
    while(true)
    {

        cout<<"Select one of the following:"<<endl;
        cout<<"1-Books Menu"<<endl<<"2-User Menu"<<endl<<"3-Exit"<<endl;
        cin>>number;
        switch(number)
        {
        case 1:
        {
            cout<<"How many books will be added?"<<endl;
            int capacity;
            cin>>capacity;
            BookList blist1(capacity);
            for(int counter = 0; counter<capacity ; counter++)
            {
                int number;
                cout<<"BOOKS MENU"<<endl<<"1-Create a book and add it to the list"<<endl<<
                    "2-Search for a book"<<endl<<"3-Display all books (with book rating)"<<endl<<
                    "4-Get the highest rating book"<<endl<<"5-Get all books of a user"<<endl<<
                    "6- Copy the current Book List to a new book list"<<endl<<"7-Back to the main menu"<<endl;
                cin>>number;
                switch(number)
                {
                case 1:
                {
                    cin>>book1;
                    blist1.addBook(book1);
                    while(true)
                    {
                        cout<<"1-Assign Author"<<endl<<"2-Continue"<<endl;
                        cin>>number;
                        switch (number)
                        {
                        case 1:
                        {
                            int id = 0;
                            cout<<"Enter author (user) id"<<endl;
                            cin>>id;

                            if(id>ulist1.arrayCount){
                                cout<<"Wrong Id"<<endl;
                                continue;
                            }
                            else
                            {
                               book1.setAuthor(ulist1.searchUser(id));
                                blist1.updateBook(book1);
                                break;
                            }


                            break;
                        }
                        case 2:
                        {
                            blist1.indOfAuthor[blist1.counter]=1000;
                            blist1.counter++;
                            break;
                        }
                        }
                       break;

                    }
                    break;
                }
                case 2:
                {
                    cout<<"1-Search by name"<<endl<<"2-Search by id"<<endl<<
                        "3-Return to main menu"<<endl;
                    cin>>number;
                    switch (number)
                    {
                    case 1:
                    {
                        string name;
                        cout<<"Enter the book name"<<endl;
                        cin>>name;
                        cout<<blist1.searchBook(name);
                          Book book(blist1.searchBook(name));
                        while(true)
                        {
                            cout<<"1-Update Author"<<endl<<"2-Update name"<<endl<<"3-Update category"<<endl<<
                                "4-Delete book"<<endl<<"5-Rate book"<<endl<<"6-Get back to books menu"<<endl;
                            cin>>number;

                            switch(number)
                            {
                            case 1:
                            {
                                cout<<"Enter new author"<<endl;
                                cin>>name;
                                user1.setName(name);
                                book.setAuthor(user1);
                                blist1.anotherUpdate(book);
                                break;
                            }
                            case 2:
                            {
                                cout<<"Enter new name"<<endl;
                                cin>>name;

                                book.setTitle(name);
                                blist1.updateTitle(book);
                                break;
                            }
                            case 3:
                            {
                                cout<<"Enter new category"<<endl;
                                cin>>name;
                                book.setCategory(name);
                                blist1.updateCategory(book);
                                break;
                            }
                            case 4:
                            {
                                blist1.deleteBook(blist1.idDelete);
                                break;
                            }
                            case 5:
                            {
                                int rating = 0;
                                cout<<"Enter Rating Value"<<endl;
                                cin>>rating;
                                book.rateBook(rating);
                                blist1.updateRate(book);
                                break;
                            }
                            case 6:
                            {
                                break;
                            }
                            }
                            if(number==6){break;}else{continue;}
                        }
                        break;
                    }
                    case 2:
                    {
                        int id;
                        cout<<"Enter the book id"<<endl;
                        while(true)
                        {cin>>id;
                        cout<<blist1.searchBook(id);
                          Book book(blist1.searchBook(id));
                            cout<<"1-Update Author"<<endl<<"2-Update name"<<endl<<"3-Update category"<<endl<<
                                "4-Delete book"<<endl<<"5-Rate book"<<endl<<"6-Get back to books menu"<<endl;
                            cin>>number;

                            switch(number)
                            {
                            case 1:
                            {
                                string name;
                                cout<<"Enter new author"<<endl;
                                cin>>name;
                                user1.setName(name);
                                book.setAuthor(user1);
                                blist1.anotherUpdate(book);
                                break;
                            }
                            case 2:
                            {
                                string name;
                                cout<<"Enter new name"<<endl;
                                cin>>name;
                                book.setTitle(name);
                                blist1.updateTitle(book);
                                break;
                            }
                            case 3:
                            {
                                string cat;
                                cout<<"Enter new category"<<endl;
                                cin>>cat;
                                book.setCategory(cat);
                                blist1.updateCategory(book);
                                break;
                            }
                            case 4:
                            {
                                blist1.deleteBook(blist1.idDelete);

                                break;
                            }
                            case 5:
                            {
                                int rating = 0;
                                cout<<"Enter Rating Value"<<endl;
                                cin>>rating;
                                book.rateBook(rating);
                                blist1.updateRate(book);
                                break;
                            }
                            case 6:
                            {
                                break;
                            }
                            }
                            if(number==6)
                            {
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        break;
                    }
                    }
                    break;
                }
                case 3:
                {
                    cout<<blist1;

                    break;
                }
                case 4:
                {
                cout<<blist1.getTheHighestRatedBook();


                    break;
                }
                case 5:
                {
                    cout<<"Enter user ID"<<endl;
                    int id = 0;
                    cin>>id;

                        Book * bookUser = new Book[100000];
                        bookUser = blist1.getBooksForUser(ulist1.searchUser(id));
                       for(int i=0;i<blist1.counter;i++)
                           cout<<bookUser[i];

                    break;

                }
                case 6:
                {
                    BookList bookList2(blist1);
                    cout<<"Copied current list ("<<
                        blist1.b<<" books) to a new list and switched it"<<endl;
                    break;
                }
                case 7:
                {
                    break;
                }
                }
                if(number==7){break;}else{continue;}
            }
            break;
        }

//*************************************User Menu**************************************************************
        case (2):
        {
            int capacity;
            cout<<"How many users will you add?"<<endl;
            cin>>capacity;
            ulist1.addSize(capacity);
            for(int counter = 0 ; counter<capacity ; counter++)
            {
                cout<<"USERS MENU"<<endl;
                cout<<"1- Create a USER and add it to the list"<<endl<<
                    "2-Search for a user"<<endl<<"3-Display all users"<<endl<<
                    "4-Back to the main menu"<<endl;
                cin>>number;
                switch(number)
                {
                case (1):
                {
                    cin>>user1;
                    ulist1.addUser(user1);
                    break;
                }
                case (2):
                {
                    while(true)
                    {
                        cout<<"1-Search by name"<<endl<<"2- Search by id"<<endl<<
                            "3-Return to Users Menu"<<endl;
                        cin>>number;


                        switch (number)
                        {

                        case 1:
                        {
                            string name;
                            cout<<"Enter Name"<<endl;
                            cin>>name;
                            cout<<ulist1.searchUser(name);
                            cout<<"1-Delete User"<<endl<<"2-Return to Users Menu"<<endl;
                            cin>>number;
                            switch(number)
                            {
                            case 1:
                            {
                                ulist1.deleteUser(ulist1.idDelete);
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            }
                            break;
                        }



                        case 2:
                        {
                            int id;
                            cout<<"Enter the ID"<<endl;
                            cin>>id;
                            cout<<ulist1.searchUser(id);
                            cout<<"1-Delete User"<<endl<<"2-Return to Users Menu"<<endl;
                            cin>>number;
                            switch(number)
                            {
                            case 1:
                            {
                                ulist1.deleteUser(ulist1.idDelete);
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            }
                            break;
                        }
                        case 3:
                        {
                            break;
                        }

                        }
                        if(number == 3)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }

                    }
                    break;
                }
                case (3):
                {
                    cout<<ulist1;
                    break;
                }
                case 4:
                {
                    break;
                }

                }
                if(number==4)
                {
                    break;
                }
                else
                {
                    continue;
                }

            }
            break;
        }

        case 3:
        {
            break;
        }
        }
        if(number==3)
        {
            break;
        }
        else
        {
            continue;
        }
    }
}


