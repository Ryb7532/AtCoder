#!/bin/bash

OPT_CONFIG=""
while (( $# > 0 ))
do
  case $1 in
    -c)
      OPT_CONFIG="-c inquire"
      ;;
    -*)
      ;;
  esac
  shift
done

printf "Which contest?\n"
read contest
acc login
oj login https://beta.atcoder.jp/
acc new $contest $OPT_CONFIG
cp template/test.sh $contest/.
cp template/check_testcase.out $contest/.
chmod u+x $contest/test.sh
cd $contest
