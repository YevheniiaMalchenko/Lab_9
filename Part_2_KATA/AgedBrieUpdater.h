#pragma once
#include "ItemUpdater.h"

class AgedBrieUpdater : public ItemUpdater {
public:
    void update(Item& item) override {
        if (item.quality < 50) item.quality++;
        item.sellIn--;
        if (item.sellIn < 0 && item.quality < 50) item.quality++;
    }
};