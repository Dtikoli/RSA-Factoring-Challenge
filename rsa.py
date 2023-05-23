#!/usr/bin/python3
import sys
import math


def is_prime(number):
    if number <= 1:
        return False
    if number <= 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(number)) + 1, 6):
        if number % i == 0 or number % (i + 2) == 0:
            return False
    return True


def find_prime_factors(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and is_prime(i):
            p = i
            q = n // i
            return p, q

    return None, None


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python prime_factors.py <filename>")
        sys.exit(1)

    filename = sys.argv[1]

    try:
        with open(filename, "r") as file:
            n = int(file.readline())
    except FileNotFoundError:
        print("Failed to open the file.")
        sys.exit(1)
    except ValueError:
        print("Invalid input in the file.")
        sys.exit(1)

    p, q = find_prime_factors(n)

    if p is not None and q is not None:
        print(f"{n}={q}*{p}")
    else:
        print("No distinct prime factors found.")
