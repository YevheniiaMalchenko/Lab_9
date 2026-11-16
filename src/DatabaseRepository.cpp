#include "DatabaseRepository.h"
#include <iostream>
using namespace std;

void DatabaseRepository::save(const string& title, const string& author) {
    cout << "Saving book to database: " << title << " by " << author << endl;
}