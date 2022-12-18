#!/bin/bash

printf "Which contest?\n"
read contest
acc login
oj login https://beta.atcoder.jp/
acc new $contest
cp template/test.sh $contest/test.sh
chmod u+x $contest/test.sh
cd $contest
