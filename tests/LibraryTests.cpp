#include <gtest/gtest.h>
#include "Library.h"
#include "Book.h"
#include "IBookRepository.h"
#include "INotificationService.h"
#include <vector>
#include <string>
using namespace std;

//Фейковий репозиторій для тестів, замість реальної БД
class FakeBookRepository : public IBookRepository {
public:
    vector<string> savedBooks;

    void save(const string& title, const string& author) override {
        savedBooks.push_back(title + " by " + author);
    }
};

//Фейковий сервіс сповіщень для тестів
class FakeNotificationService : public INotificationService {
public:
    vector<string> messages;

    void notify(const string& message) override {
        messages.push_back(message);
    }
};

//Тест 1. перевірка, що книга додається до колекції
TEST(LibraryTest, AddBookIncreasesCount) {
    FakeBookRepository repo;
    FakeNotificationService notifier;
    Library library(repo, notifier);

    Book book("Test Title", "Test Author");
    library.addBook(book);

    // Перевіряємо, що репозиторій отримав виклик save
    ASSERT_EQ(repo.savedBooks.size(), 1);
    EXPECT_EQ(repo.savedBooks[0], "Test Title by Test Author");
}

//Тест 2. перевірка, що сповіщення відправляється
TEST(LibraryTest, AddBookSendsNotification) {
    FakeBookRepository repo;
    FakeNotificationService notifier;
    Library library(repo, notifier);

    Book book("Test Title", "Test Author");
    library.addBook(book);

    ASSERT_EQ(notifier.messages.size(), 1);
    EXPECT_EQ(notifier.messages[0], "New book added: Test Title");
}

//Тест 3. перевірка, що displayBooks не падає на порожній колекції
TEST(LibraryTest, DisplayBooksOnEmptyLibrary) {
    FakeBookRepository repo;
    FakeNotificationService notifier;
    Library library(repo, notifier);

    //Не додаємо книг, а просто викликаємо displayBooks
    EXPECT_NO_THROW(library.displayBooks());
}

//Тест 4.перевірка додавання декількох книг
TEST(LibraryTest, AddMultipleBooks) {
    FakeBookRepository repo;
    FakeNotificationService notifier;
    Library library(repo, notifier);

    library.addBook(Book("Book 1", "Author 1"));
    library.addBook(Book("Book 2", "Author 2"));

    ASSERT_EQ(repo.savedBooks.size(), 2);
    EXPECT_EQ(notifier.messages.size(), 2);
}