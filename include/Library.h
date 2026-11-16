#pragma once
#include <vector>
#include "Book.h"
#include "IBookRepository.h"
#include "INotificationService.h"

class Library {
private:
    vector<Book> books_;
    IBookRepository& repository_;
    INotificationService& notifier_;

public:
    Library(IBookRepository& repository, INotificationService& notifier)
        : repository_(repository), notifier_(notifier) {}

    void addBook(const Book& book);
    void displayBooks() const;
};