#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


using edge = struct {int d; ll c;};

int main() {
  int N,M,Q;
  cin >> N >> M >> Q;
  // nanの条件：連結成分でない
  // infの条件：連結成分かつ連結成分内にコストがプラスになるサイクルを持つ
  // 値が定まる条件：上記以外
  // 値の計算方法：木を構築し，根からのコストを計算しておく．目的地へのコスト-出発地へのコスト．
  vector<vector<edge>> Edge(N);
  vector<int> Root(N,-1);
  vector<ll> Cost(N,0); // from root
  set<int> hasNotZeroCycle;
  rep(i,M) {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    Edge[a].push_back({b,c});
    Edge[b].push_back({a,-c});
  }
  rep(i,N) {
    if (Root[i] != -1)
      continue;
    Root[i] = i;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      for (edge e: Edge[s]) {
        int d = e.d;
        ll c = e.c;
        if (Root[d] == -1) {
          q.push(d);
          Root[d] = i;
          Cost[d] = Cost[s] + c;
        } else if (Cost[d] != Cost[s] + c) {
          hasNotZeroCycle.insert(i);
        }
      }
    }
  }
  rep(_,Q) {
    int X,Y;
    cin >> X >> Y;
    X--; Y--;
    if (Root[X] != Root[Y])
      print("nan");
    else if (hasNotZeroCycle.find(Root[X]) != hasNotZeroCycle.end())
      print("inf");
    else
      print(Cost[Y]-Cost[X]);
  }
  return 0;
}
