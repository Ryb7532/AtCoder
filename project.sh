#!/bin/bash

OPT_CONFIG="-c all"
OPT_TEMPLATE="--template cpp"
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
oj login https://beta.atcoder.jp/
acc login
acc new $contest $OPT_CONFIG $OPT_TEMPLATE
code $contest/*/main.cpp
