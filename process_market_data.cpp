#include "process_market_data.h"

using namespace std;

InvalidDataFormatException invalid_data = InvalidDataFormatException();

string data_element_to_string(char const *data, int begin, int end) {
    string buffer;
    for (int i = begin; i < end; ++i) {
        buffer += data[i];
    }
    return buffer;
}

double to_double(string input) {
    for (char digit : input) {
        if (!(isdigit(digit) || digit == '.')) {
            cerr << "ERROR: Invalid double " << input << "\n";
            throw invalid_data;
        }
    }
    return stod(input);
}

int to_int(string input) {
    for (char digit : input) {
        if (!isdigit(digit)) {
            cerr << "ERROR: Invalid integer " << input << "\n";
            throw invalid_data;
        }
    }
    return stoi(input);
}

void process_market_data_entry(char const *data, int begin, int end) {
    int start_element = begin;
    vector<string> elements; // symbol, bid_price, ask_price, bid_size, ask_size

    for (int i = begin; i < end; ++i) {
        // Market data element delimiter
        if (data[i] == ' ') {
            elements.push_back(data_element_to_string(data, start_element, i));
            start_element = i + 1;
        }
    }
    elements.push_back(data_element_to_string(data, start_element, end));

    MarketDataEntry entry = MarketDataEntry(
        to_double(elements[1]),
        to_double(elements[2]),
        to_int(elements[3]),
        to_int(elements[4])
    );
    
    lock_guard<mutex> lock(market_mutex);
    market[elements[0]] = entry;
}

void on_market_data(char const *data) {
    int i = 0, start_entry = 0;

    while (data[i] != '\0') {
        // Market entry delimiter
        if (data[i] == '\n') {
            try {
                process_market_data_entry(data, start_entry, i);
            } catch (InvalidDataFormatException) {
                // Log exception and continue
            }
            start_entry = i + 1;
        }

        i += 1;
    }
}