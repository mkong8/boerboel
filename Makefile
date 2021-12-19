all: example.o market_data_entry.o market.o process_market_data.o
	g++ -std=c++20 -o run example.o market_data_entry.o market.o process_market_data.o

test: run_tests.o market_data_entry.o market.o process_market_data.o
	g++ -std=c++20 -o run_tests run_tests.o market_data_entry.o market.o process_market_data.o

example.o: example.cpp market.h process_market_data.h
	g++ -std=c++20 -c example.cpp

run_tests.o: run_tests.cpp market.h process_market_data.h
	g++ -std=c++20 -c run_tests.cpp

market.o: market.h

market_data_entry.o: market_data_entry.h

process_market_data.o: process_market_data.h

zip:
	zip -r boerboel.zip . -x /.vscode/* *.o

clean:
	rm *.o run run_tests