#!/usr/bin/env python3
"""
Generate N distinct random integers within a user-supplied range.

Usage:
    python push_rnd.py <low> <high> <count>

Example:
    python push_rnd.py -1000 1000 50
"""
import argparse
import random
import sys


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description="Generate distinct random integers in the given inclusive range."
    )
    p.add_argument("low", type=int, help="Lowest integer in the range (inclusive)")
    p.add_argument("high", type=int, help="Highest integer in the range (inclusive)")
    p.add_argument("count", type=int, help="Number of integers to generate")
    return p.parse_args()


def main() -> None:
    args = parse_args()

    # Validate arguments
    if args.low > args.high:
        sys.exit("low must be ≤ high")
    span = args.high - args.low + 1
    if args.count > span:
        sys.exit("count cannot exceed the size of the range")

    # random.sample guarantees uniqueness
    nums = random.sample(range(args.low, args.high + 1), args.count)

    # One per line; pipe/redirect as desired
    vals = ' '.join(map(str, nums))
    print(f'ARG="{vals}"; ./push_swap $ARG | wc -l');
    print(f'ARG="{vals}"; ./push_swap $ARG | ./checker_linux $ARG');


if __name__ == "__main__":
    main()
