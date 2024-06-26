#!/bin/bash

cd submissions
python3 scraping.py
while [ `find */* -empty | wc -l` != 0 ]; do
  find */* -empty -delete
  python3 scraping.py
done
git add .
echo "Will you push? (if not, type n.)"
read flag_push
if [ "$flag_push" != "n" ]; then
  today=`date "+%y/%m/%d %H:%M"`
  git commit -m "${today}"
  git push
fi
