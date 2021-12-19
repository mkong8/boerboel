#include <assert.h>
#include "process_market_data.h"

using namespace std;

void run_test(string test_name) {
    cout << test_name << "...\n";
    string filename = "test/" + test_name + ".txt";
    ifstream file (filename);
    string market_data, market_data_row;

    while (getline(file, market_data_row)) {
        market_data += market_data_row + '\n';
    }
    on_market_data(market_data.c_str());
}

void test_small() {
    MarketDataEntry aapl = MarketDataEntry(174, 176, 1000, 1000);
    MarketDataEntry goog = MarketDataEntry(2855, 2857, 1000, 1000);
    
    run_test("market_data_small");
    assert(market["AAPL"] == aapl);
    assert(market["GOOG"] == goog);
    market.clear();
}

void test_small_error() {
    run_test("market_data_small_error");
    assert(market.empty());
    market.clear();
}

void test_10() {
    MarketDataEntry rojas = MarketDataEntry(245071.55, 928213.6, 229167, 34025);
    MarketDataEntry qlqge = MarketDataEntry(691504.8, 198055.9, 940837, 809175);
    MarketDataEntry error = MarketDataEntry();

    run_test("market_data_auto_10");
    assert(market["ROJAS"] == rojas);
    assert(market["QLQGE"] == qlqge);
    assert(!(market["ROJAS"] == error));
    market.clear();
}

void test_1000() {
    MarketDataEntry ofp = MarketDataEntry(650926.24, 155140.32, 51540, 451648);
    MarketDataEntry sbhd = MarketDataEntry(321075.75, 504205.92, 856769, 726533);
    MarketDataEntry error = MarketDataEntry();

    run_test("market_data_auto_1000");
    assert(market["OFP"] == ofp);
    assert(market["SBHD"] == sbhd);
    assert(!(market["RTC"] == error));
    market.clear();
}

void test_update() {
    MarketDataEntry aapl = MarketDataEntry(590514.12, 638989.05, 68014, 375521);

    run_test("market_data_auto_update");
    assert(market["AAPL"] == aapl);
    market.clear();
}

int main() {
    cout << "Running test suite...\n";
    test_small();
    test_small_error();
    test_10();
    test_1000();
    test_update();
    cout << "SUCCESS!\n";
    return 0;
}