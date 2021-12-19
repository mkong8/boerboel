#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>
#include "market.h"

/*
    Custom exception class for invalid market data input
*/
class InvalidDataFormatException: public exception {
    virtual const char* what() const throw() {
        return "Invalid data format.";
    }
};

/*
    Helper functions for processing char data elements into
    market data types.
*/
string data_element_to_string(char const *data, int begin, int end);
double to_double(string input);
int to_int(string input);

void process_market_data_entry(char const *data, int begin, int end);
/*
    Processes a stream of strings into the global market object.
    Expected input for each row:
    <SYMBOL> <BID_PRICE> <ASK_PRICE> <BID_SIZE> <ASK_SIZE>\n
    Block of rows expected to end in the terminating null byte '\0'.

    Example:
    AAPL 174.00 176.00 1000 1000\n
    GOOG 2855.00 2857.00 1000 1000\n
    \0
*/
void on_market_data(char const *data);