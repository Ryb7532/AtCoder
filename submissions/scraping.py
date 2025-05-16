#-*- coding: utf-8 -*-
from typing import Sized
import requests
import json
from time import sleep

with open('../info.json', 'r') as f:
    info = json.load(f)
api_path = "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={}&from_second={}".format(info["userID"], info["min_second"])

# APIを用いた提出データの取得
def getSubmissionData():
    api_url = api_path
    response = requests.get(api_url)
    jsonData = response.json()
    return jsonData

submissions = getSubmissionData()

def collectNewestAcceptedSubmissions(submissions):
    sortedData = sorted(submissions, key=lambda x: x['id'])  # IDで昇順ソートすると古い順になる
    submits = {} # 各問題ごとに最新の提出に更新する
    for data in sortedData:
        if data["result"] != "AC": # ACだった提出だけ対象
            continue
        submits[data["problem_id"]] = data

    result = {} # コンテストごとにまとめる
    for sub in submits.values():
        if not sub["contest_id"] in result:
            result[sub["contest_id"]] = []
        result[sub["contest_id"]].append(sub)
    return result

newestSubmits =  collectNewestAcceptedSubmissions(submissions)

if not newestSubmits:
    exit()




import os

for contestName in newestSubmits:
    path = contestName
    os.makedirs(path, exist_ok=True)





import re
import html
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
import subprocess
import geckodriver_autoinstaller

geckodriver_autoinstaller.install()

driver = webdriver.Firefox()

add_cnt = 0
max_epoch_second = info["min_second"]

for submissions in newestSubmits.values():
    for sub in submissions:
        # 問題番号の取得
        problem_num = sub["problem_id"][-1]

        # 古い問題の場合には数字になっているので、アルファベットに戻す
        if problem_num.isdigit():
            problem_num = chr(int(problem_num)+ord('a')-1)

        # 作成するファイルへのパス
        path = sub["contest_id"] + "/" + problem_num
        # 拡張子の設定
        if "C++" in sub["language"]:
            path += ".cpp"
        elif "C" in sub["language"]:
            path += ".c"
        elif "Python" in sub["language"]:
            path += ".py"

        # 既に提出コードがある場合は取得せず、次の問題の提出を探す
        if os.path.isfile(path): continue

        # 提出ページへアクセス
        sub_url = "https://atcoder.jp/contests/" + sub["contest_id"] + "/submissions/" + str(sub["id"])

        driver.get(sub_url)

        # 提出コードの取得
        code = driver.find_element("id", "for_copy0")
        code_text = code.get_attribute("textContent")

        # 書き込み
        with open(path, 'w') as f:
            f.write(code_text)

        # 追加したファイルの数を増やす
        add_cnt += 1

        # 次回以降の探索範囲を削減
        max_epoch_second = max(max_epoch_second, sub["epoch_second"])

        # アクセス負荷軽減のために時間をおく(3秒)
        sleep(3)

driver.quit()

info["min_second"] = max_epoch_second
with open('../info.json', 'w') as f:
    json.dump(info, f)
