#!/bin/bash
contest="abc"

FLAG_SUBMIT=1
FLAG_FORCE_SUBMIT=0
while (( $# > 0 ))
do
  case $1 in
    -n)
      FLAG_SUBMIT=0
      ;;
    -f)
      FLAG_FORCE_SUBMIT=1
      ;;
    -*)
      echo "invalid option"
      exit 1
      ;;
  esac
  shift
done

printf "which task?\n"
read task
cd $task
rm -f a.out
g++ -Wall -std=c++17 -o a.out main.cpp
export TIMEFORMAT="%Es"
i=1
while [ -s tests/sample-$i.in ];
do
  runtime=`(time ./a.out < tests/sample-$i.in > tests/answer-$i.out)2>&1`
  # diff tests/sample-$i.out tests/answer-$i.out > tests/text.txt
  res=`.././check_testcase.out tests/sample-$i.out tests/answer-$i.out`
  if [ $res == 1 ]; then
    printf "\e[31merror\e[m\t\t${runtime}\n"
    FLAG_SUBMIT=0
  else
    printf "\e[32msuccess\e[m\t\t${runtime}\n"
    rm tests/answer-$i.out
  fi

  # rm tests/text.txt
  i=`expr $i + 1 `
done

if [ $FLAG_SUBMIT == 1 ] || [ $FLAG_FORCE_SUBMIT == 1 ]; then
  echo $contest$task | acc submit
fi
