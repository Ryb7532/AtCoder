#!/bin/bash

FLAG_SUBMIT=1
while (( $# > 0 ))
do
  case $1 in
    -n)
      FLAG_SUBMIT=0
      ;;
    -*)
      echo "invalid option"
      exit 1
      ;;
  esac
  shift
done

printf "which problem?\n"
read problem
cd $problem
g++ -Wall -o a.out main.cpp
export TIMEFORMAT="%Es"
i=1
while [ -s tests/sample-$i.in ];
do
  runtime=`(time ./a.out < tests/sample-$i.in > tests/answer-$i.out)2>&1`
  diff tests/sample-$i.out tests/answer-$i.out > tests/text.txt
  if [ -s tests/text.txt ]; then
    printf "\e[31merror\e[m\t\t${runtime}\n"
    FLAG_SUBMIT=0
  else
    printf "\e[32msuccess\e[m\t\t${runtime}\n"
    rm tests/answer-$i.out
  fi

  rm tests/text.txt
  i=`expr $i + 1 `
done

if [ $FLAG_SUBMIT == 1 ]; then
  echo abc${problem} | acc submit
fi
