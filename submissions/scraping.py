import requests
import json

userID = "Ryb7532" # 自分のAtCoderのユーザーIDを設定する
api_path = "https://kenkoooo.com/atcoder/atcoder-api/results?user="

# APIを用いた提出データの取得
def getSubmissionData(userID):
    api_url = api_path + userID
    response = requests.get(api_url)
    jsonData = response.json()
    return jsonData

submissions = getSubmissionData(userID)

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





import os

for contestName in newestSubmits:
    path = contestName
    os.makedirs(path, exist_ok=True)





import re
import html
from selenium import webdriver
from time import sleep
import subprocess

driver = webdriver.Firefox()

add_cnt = 0

for submissions in newestSubmits.values():
    for sub in submissions:
        # 問題番号の取得
        problem_num = sub["problem_id"][-1]
        
        # 古い問題の場合には数字になっているので、アルファベットに戻す
        if problem_num.isdigit():
            problem_num = chr(int(problem_num)+ord('a')-1)
        
        # 作成するファイルへのパス
        path = sub["contest_id"] + "/" + problem_num
        # 拡張子の設定（C++, Cのみ）
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
        code = driver.find_element_by_id("submission-code")
        
        # code.text は提出時に含めていない空白が期待に反して含まれてしまう
        # 空白はシンタックスハイライティングによるものであるように見える
        # innerHTML から不要なタグなどを消し、空白が意図通りのテキストを得る
        inner_html = code.get_attribute('innerHTML')
        list_items = re.findall(r'<li[^>]*>.*?</li>', inner_html)
        lines = []
        for li in list_items:
            line1 = re.sub(r'<[^>]+>', '', li)
            line2 = re.sub(r'&nbsp;', '', line1)
            line3 = html.unescape(line2)
            lines.append(line3 + "\n")
        code_text = ''.join(lines)
            
        # 書き込み
        with open(path, 'w') as f:
            f.write(code_text)
        
        # 追加したファイルの数を増やす
        add_cnt += 1
            
        # アクセス負荷軽減のために時間をおく(3秒)
        sleep(3)
        
driver.quit()