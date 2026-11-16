#pragma once
#include "ItemUpdater.h"

class NormalItemUpdater : public ItemUpdater {
public:
    void update(Item& item) override {
        if (item.quality > 0) item.quality--;
        item.sellIn--;
        if (item.sellIn < 0 && item.quality > 0) item.quality--;
    }
};