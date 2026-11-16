#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "Item.h"
#include "NormalItemUpdater.h"
#include "AgedBrieUpdater.h"
#include "BackstagePassUpdater.h"
#include "SulfurasUpdater.h"
#include "ConjuredItemUpdater.h" 
using namespace std;

class GildedRose {
private:
    vector<Item> items;
    map<string, unique_ptr<ItemUpdater>> updaters;

    ItemUpdater* getUpdater(const string& name) {
        if (name == "Aged Brie") return updaters["brie"].get();
        if (name == "Backstage passes to a TAFKAL80ETC concert") return updaters["backstage"].get();
        if (name == "Sulfuras, Hand of Ragnaros") return updaters["sulfuras"].get();
        if (name == "Conjured Mana Cake") return updaters["conjured"].get(); 
        return updaters["normal"].get();
    }

public:
    GildedRose(vector<Item> items) : items(items) {
        updaters["normal"] = make_unique<NormalItemUpdater>();
        updaters["brie"] = make_unique<AgedBrieUpdater>();
        updaters["backstage"] = make_unique<BackstagePassUpdater>();
        updaters["sulfuras"] = make_unique<SulfurasUpdater>();
        updaters["conjured"] = make_unique<ConjuredItemUpdater>(); 
    }

    void updateQuality() {
        for (auto& item : items) {
            getUpdater(item.name)->update(item);
        }
    }

    vector<Item> getItems() const { return items; }
};

int main() {
    vector<Item> items = {
        Item("+5 Dexterity Vest", 10, 20),
        Item("Aged Brie", 2, 0),
        Item("Elixir of the Mongoose", 5, 7),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 15, 20),
        Item("Conjured Mana Cake", 3, 6) // Додати новий товар
    };

    GildedRose app(items);

    cout << "Before update:" << endl;
    for (const auto& item : app.getItems()) {
        cout << item.name << ", sellIn: " << item.sellIn << ", quality: " << item.quality << endl;
    }

    app.updateQuality();

    cout << "\nAfter update:" << endl;
    for (const auto& item : app.getItems()) {
        cout << item.name << ", sellIn: " << item.sellIn << ", quality: " << item.quality << endl;
    }

    return 0;
}