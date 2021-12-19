#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct MarketDataEntry {
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;

    MarketDataEntry();
    
    MarketDataEntry(double _bid_price, double _ask_price, int _bid_size, int _ask_size);

    bool operator==(const MarketDataEntry &other) const;
};

ostream& operator<<(ostream& os, const MarketDataEntry& market);