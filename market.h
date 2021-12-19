#include <unordered_map>
#include <mutex>
#include "market_data_entry.h"

/*
    Global market object that maps:
    Symbol -> Basic market data
*/
extern unordered_map<string, MarketDataEntry> market;
extern mutex market_mutex;
MarketDataEntry get_symbol(string symbol);