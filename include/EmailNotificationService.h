#pragma once
#include "INotificationService.h"

class EmailNotificationService : public INotificationService {
public:
    void notify(const std::string& message) override;
};
