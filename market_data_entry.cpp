#include "market_data_entry.h"

MarketDataEntry::MarketDataEntry() {
    bid_price = 0;
    ask_price = 0;
    bid_size = 0;
    ask_size = 0;
}

MarketDataEntry::MarketDataEntry(double _bid_price, double _ask_price, int _bid_size, int _ask_size) {
    bid_price = _bid_price;
    ask_price = _ask_price;
    bid_size = _bid_size;
    ask_size = _ask_size;
}

bool MarketDataEntry::operator==(const MarketDataEntry &other) const {
    return bid_price == other.bid_price &&
        ask_price == other.ask_price &&
        bid_size == other.bid_size &&
        ask_size == other.ask_size;
}

ostream& operator<<(ostream& os, const MarketDataEntry& entry) {
    return os << setprecision(8) << entry.bid_price << " "
            << entry.ask_price << " "
            << entry.bid_size << " "
            << entry.ask_size;
}