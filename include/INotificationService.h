#pragma once
#include <string>

class INotificationService {
public:
    virtual ~INotificationService() = default;
    virtual void notify(const std::string& message) = 0;
};