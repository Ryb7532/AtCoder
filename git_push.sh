#!/bin/bash

cd submissions
python scraping.py
git add .
today=`date "+%y/%m/%d"`
git commit -m "${today}"
git push