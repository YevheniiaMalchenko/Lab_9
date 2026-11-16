#pragma once
#include "IBookRepository.h"

class DatabaseRepository : public IBookRepository {
public:
    void save(const std::string& title, const std::string& author) override;
};