import sys
import string
import random

def generate_test(num_lines):
    filename = f'test/market_data_auto_update.txt'
    with open(filename, 'w') as f:
        for _ in range(num_lines):
            symbol_len = random.randint(3, 5)
            symbol = random.choices(string.ascii_uppercase, k=symbol_len)
            bid_price = random.uniform(10, 1000000)
            ask_price = random.uniform(10, 1000000)
            bid_size = random.randint(1, 1000000)
            ask_size = random.randint(1, 1000000)
            line = f"{''.join(symbol)} {round(bid_price, 2)} {round(ask_price, 2)} {bid_size} {ask_size}\n"
            f.write(line)

if __name__ == '__main__':
    num_lines = int(sys.argv[1])
    generate_test(num_lines)