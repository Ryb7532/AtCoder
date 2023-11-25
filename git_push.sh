#!/bin/bash

cd submissions
gitstat=""
while [ "$gitstat" == "" ] || [ `find */* -empty | wc -l` != 0 ]; do
  find */* -empty -delete
  python3 scraping.py
  gitstat=`git status -s`
done
git add .
echo "Will you push? (if not, type n.)"
read flag_push
if [ "$flag_push" != "n" ]; then
  today=`date "+%y/%m/%d %H:%M"`
  git commit -m "${today}"
  git push
fi
