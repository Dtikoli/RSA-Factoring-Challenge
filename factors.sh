#!/bin/bash

factorize()
{
    number=$1
    for ((i=2; i <= number/2; i++)); do
        if ((number % i == 0)); then
            echo "$number=$((number / i))*$i"
            break
        fi
    done
}

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

filename=$1

while IFS= read -r line; do
    number=$line
    factorize "$number"
done < "$filename"

