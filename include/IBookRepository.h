#pragma once
#include <string>

class IBookRepository {
public:
    virtual ~IBookRepository() = default;
    virtual void save(const std::string& title, const std::string& author) = 0;
};