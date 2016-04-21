#!/bin/bash
if [[ $1 ]]; then
    clang-format -i -style="{BasedOnStyle: google, IndentWidth: 4, ColumnLimit: 100}" $1
    echo "Formatted $1."
else
    clang-format -i -style="{BasedOnStyle: google, IndentWidth: 4, ColumnLimit: 100}" main.cpp
    echo "Formatted main.cpp."
fi
