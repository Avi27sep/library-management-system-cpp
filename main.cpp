#include<bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;
    Book(int id,string title,string author) : id(id), title(title), author(author), available(true) {}
};

void addBook(vector<Book>& inventory) {
    int id;
    string title,author;
    cout<<"Enter book ID: ";
    cin>>id;
    cin.ignore();
    cout<<"Enter book title: ";
    getline(cin, title);
    cout<<"Enter book author: ";
    getline(cin, author);
    inventory.push_back(Book(id, title, author));
    cout<<"Book added successfully."<<endl;
}

void issueBook(vector<Book>& inventory) {
    int id;
    cout<<"Enter book ID to issue: ";
    cin>>id;
    for(auto& book : inventory) {
        if (book.id == id) {
            if(book.available){
                book.available=false;
                cout<<"Book issued successfully."<<endl;
            } 
            else cout<<"Book already issued."<<endl;
            return;
        }
    }
    cout<<"Book not found."<<endl;
}

void returnBook(vector<Book>& inventory) {
    int id;
    cout<<"Enter book ID to return: ";
    cin>>id;
    for(auto& book : inventory) {
        if(book.id==id) {
            if(!book.available){
                book.available = true;
                cout<<"Book returned successfully."<<endl;
            } 
            else cout << "Book was not issued." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void searchBook(const vector<Book>& inventory) {
    string title;
    cout<<"Enter book title to search: ";
    cin.ignore();
    getline(cin, title);
    for(const auto& book : inventory){
        if(book.title == title){
            cout<<"Book found: ID="<<book.id<<", Title="<<book.title<<", Author="<<book.author<<", Available="<<(book.available ? "Yes" : "No")<<endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void displayAvailableBooks(const vector<Book>& inventory){
    cout<<"Available books:"<<endl;
    for(const auto& book : inventory) {
        if(book.available) {
            cout<<"ID="<<book.id<<", Title="<<book.title<<", Author="<<book.author<<endl;
        }
    }
}

int main() {
    vector<Book> inventory;
    int choice;
    do{
        cout<<"\nLibrary Management System\n";
        cout<<"1. Add Book\n";
        cout<<"2. Issue Book\n";
        cout<<"3. Return Book\n";
        cout<<"4. Search Book by Title\n";
        cout<<"5. Display Available Books\n";
        cout<<"6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                addBook(inventory);
                break;
            case 2:
                issueBook(inventory);
                break;
            case 3:
                returnBook(inventory);
                break;
            case 4:
                searchBook(inventory);
                break;
            case 5:
                displayAvailableBooks(inventory);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }while(choice!=6);
    return 0;
}
