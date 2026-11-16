#include "EmailNotificationService.h"
#include <iostream>
using namespace std;

void EmailNotificationService::notify(const string& message) {
    cout << "Sending email notification: " << message << endl;
}