#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title_;
    string author_;

public:
    Book(const string& title, const string& author)
        : title_(title), author_(author) {}

    const string& getTitle() const { return title_; }
    const string& getAuthor() const { return author_; }

    void display() const {
        cout << "Title: " << title_ << ", Author: " << author_ << endl;
    }
};