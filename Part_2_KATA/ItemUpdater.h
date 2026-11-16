#pragma once
#include "Item.h"

class ItemUpdater {
public:
    virtual ~ItemUpdater() = default;
    virtual void update(Item& item) = 0;
};