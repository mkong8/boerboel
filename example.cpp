#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "process_market_data.h"

void run_market(string filename) {
    cout << "Starting market..." << endl;
    int milliseconds;
    string line;
    ifstream file (filename);

    // Initialize market
    getline(file, line);
    line += '\n';
    on_market_data(line.c_str());

    // Update market at random time intervals
    srand(0);
    while (getline(file, line)) {
        milliseconds = rand() % 250 + 50;
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        line += '\n';
        on_market_data(line.c_str());
    }
    cout << "End of market:" << endl;
    for (auto entry : market) {
        cout << entry.first << " : " << entry.second << endl;
    }
}

void read_market(int reads) {
    int milliseconds;
    string symbol = "AAPL";
    for (int i = 0; i < reads; ++i) {
        milliseconds = rand() % 2000 + 50;
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        MarketDataEntry data = get_symbol(symbol);
        cout << "Current state of " + symbol + ": " << data << endl;
    }
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Input file required." << endl;
        return 0;
    }
    thread market_thread(run_market, argv[1]);
    thread read_thread(read_market, 15);
    market_thread.join();
    read_thread.join();
    return 0;
}