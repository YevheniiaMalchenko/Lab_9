#include "FileRepository.h"
#include <fstream>
#include <iostream>
using namespace std;

void FileRepository::save(const string& title, const string& author) {
    ofstream file("library.txt", ios::app);
    if (file.is_open()) {
        file << title << ";" << author << "\n";
        file.close();
        cout << "Saved to file: " << title << " by " << author << endl;
    } else {
        cerr << "Error: Cannot open file!" << endl;
    }
}

