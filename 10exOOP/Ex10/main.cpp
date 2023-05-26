/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 * @desc [Book Store]
 */
#include <iostream>
#include <string>

using namespace std;


/*Class Book*/
class Book {
private:
    string title;
    string author;
    int year;
    int quantity;

public:
    Book(string title, string author, int year, int quantity);

    void displayInfo();
    void borrow();
    void returnBook();
};

/*
* Class: Book
* Description: The constructor implementation for the Book class
*/
Book::Book(string title, string author, int year, int quantity) {
    this->title = title;
    this->author = author;
    this->year = year;
    this->quantity = quantity;
}

/*
* Class: Book
* Function: displayInfo
* Description: This method display Information
* Input:
*   no input
* Output:
*   None
*/
void Book::displayInfo() {
    cout << "Book Information:" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "Quantity: " << quantity << endl;
}

/*
* Class: Book
* Function: borrow
* Description: This method borrow book
* Input:
*   no input
* Output:
*   None
*/
void Book::borrow() {
    if (quantity > 0) {
        quantity--;
        cout << "Book borrowed successfully." << endl;
    } else {
        cout << "No more copies available for borrowing." << endl;
    }
}

/*
* Class: Book
* Function: displayInfo
* Description: This method return book
* Input:
*   no input
* Output:
*   None
*/
void Book::returnBook() {
    quantity++;
    cout << "Book returned successfully." << endl;
}

int main() {
    // Tạo một đối tượng Book
    Book book("Tay Tien", "Quang Dung", 1956, 5);

    // In thông tin sách
    book.displayInfo();
    cout << "-------------" << endl;

    // Mượn sách
    book.borrow();
    cout << "-------------"<< endl;
    // In thông tin sau khi mượn sách
    book.displayInfo();
    cout << "-------------"<< endl;
    // Trả sách
    book.returnBook();
    cout << "-------------"<< endl;
    // In thông tin sau khi trả sách
    book.displayInfo();

    return 0;
}
