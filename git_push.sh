#!/bin/bash

cd submissions
python3 scraping.py
git add .
today=`date "+%y/%m/%d"`
git commit -m "${today}"
git push