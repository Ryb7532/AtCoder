#!/bin/bash

cd submissions
python3 scraping.py
git add .
today=`date "+%y/%m/%d"`
git commit -m "${today}"
echo "Will you push? (if not, type n.)"
read push
if [ "$push" != "n" ]; then
  git push
fi
