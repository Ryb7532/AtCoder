#!/bin/bash

printf "which problem?\n"
read problem
cd $problem
g++ -Wall -o $problem $problem.cpp
i=1
while [ -s tests/sample-$i.in ];
do
  ./$problem < tests/sample-$i.in > tests/answer-$i.out
  diff tests/sample-$i.out tests/answer-$i.out > tests/text.txt
  if [ -s tests/text.txt ]; then
    printf "\e[31merror\e[m\n"
  else
    printf "\e[32msuccess\e[m\n"
    rm tests/answer-$i.out
  fi

  rm tests/text.txt
  i=`expr $i + 1 `
done
