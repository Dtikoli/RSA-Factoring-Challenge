#!/bin/bash

is_prime()
{
    number=$1

    if ((number < 2)); then
        return 1
    fi

    for ((i = 2; i <= number / 2; i++)); do
        if ((number % i == 0)); then
            return 1
        fi
    done

    return 0
}

find_prime_factors()
{
    n=$1

    for ((i = 2; i <= n / 2; i++)); do
        if ((n % i == 0)); then
            if is_prime "$i"; then
                p=$i
                q=$((n / i))
                break
            fi
        fi
    done

    echo "$n=$q*$p"
}

if [ $# -ne 1 ]; then
    echo "Usage: ./prime_factors.sh <filename>"
    exit 1
fi

filename=$1

if [ ! -f "$filename" ]; then
    echo "Failed to open the file."
    exit 1
fi

read -r n <"$filename"

if ! [[ $n =~ ^[0-9]+$ ]]; then
    echo "Invalid input in the file."
    exit 1
fi

find_prime_factors "$n"

