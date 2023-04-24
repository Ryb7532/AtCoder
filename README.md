# AtCoder

AtCoder用のレポジトリ

User ID: Ryb7532

主な使用言語: C++

## Directory / file

### ~~`contest`~~

~~開催中のコンテスト用テンプレート~~

### `library`

よく使用するアルゴリズム／データ構造

参考: https://ei1333.github.io/luzhiled/

### `submissions`

acceptされた提出コード  

`scraping.py` 提出コードの取得  
参考: https://zenn.dev/tishii2479/articles/6b381fb86e0369


### `template`

テンプレートファイルまとめ  

`test.sh` サンプルケースを自動でチェック，コードを提出  
~~（完全一致のみ判定，コンテスト開催中は使えない？）~~

`check_testcase.cpp` サンプルケースの想定解と出力を比較  
（浮動小数点数の誤差（絶対誤差，相対誤差どちらかが10^-9以下）判定も可能に）


### その他
`project.sh` ~~過去問用の~~コンテストのディレクトリ作成とサンプルケースの取得  
参考: http://tatamo.81.la/blog/2018/12/07/atcoder-cli/

`git_push.sh` コードの取得，gitへの追加，コミット，プッシュ