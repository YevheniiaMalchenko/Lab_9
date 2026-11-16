#include <iostream>
#include "Library.h"
#include "DatabaseRepository.h"
#include "FileRepository.h"
#include "EmailNotificationService.h"
using namespace std;

int main() {
    cout << "Demo 1: Database + Email" << endl;
    DatabaseRepository dbRepo;
    EmailNotificationService emailService;
    Library lib1(dbRepo, emailService);
    
    lib1.addBook(Book("The Catcher in the Rye", "J.D. Salinger"));
    lib1.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    lib1.displayBooks();

    cout << "\nDemo 2: File + Email (New Extension)" << endl;
    FileRepository fileRepo;
    Library lib2(fileRepo, emailService);
    
    lib2.addBook(Book("1984", "George Orwell"));
    lib2.addBook(Book("Animal Farm", "George Orwell"));
    lib2.displayBooks();

    return 0;
}