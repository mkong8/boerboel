#include "market.h"

unordered_map<string, MarketDataEntry> market;
mutex market_mutex;
MarketDataEntry get_symbol(string symbol) {
    lock_guard<mutex> lock(market_mutex);
    if (market.count(symbol)) {
        return market[symbol];
    }
    return MarketDataEntry();
}