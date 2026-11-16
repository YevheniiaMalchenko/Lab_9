#pragma once
#include "ItemUpdater.h"

class ConjuredItemUpdater : public ItemUpdater {
public:
    void update(Item& item) override {
        //Зачаровані товари втрачають якість удвічі швидше
        if (item.quality > 0) item.quality -= 2;
        if (item.quality < 0) item.quality = 0; //Якість не може бути від'ємною
        
        item.sellIn--;
        
        if (item.sellIn < 0 && item.quality > 0) {
            item.quality -= 2;
            if (item.quality < 0) item.quality = 0;
        }
    }
};