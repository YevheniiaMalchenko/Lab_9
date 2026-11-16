#include "Library.h"
using namespace std;

void Library::addBook(const Book& book) {
    books_.push_back(book);
    repository_.save(book.getTitle(), book.getAuthor());
    notifier_.notify("New book added: " + book.getTitle());
}

void Library::displayBooks() const {
    for (const auto& book : books_) {
        book.display();
    }
}