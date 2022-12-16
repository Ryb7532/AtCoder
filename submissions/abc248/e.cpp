#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


bool on_line(pair<int,int> A, pair<int,int> B, pair<int,int> C) {
  return (B.first - A.first) * (C.second - A.second) == (B.second - A.second) * (C.first - A.first);
}


int main() {
  int N,K;
  cin >> N >> K;
  vector<pair<int,int>> P(N);
  rep(i,N) {
    cin >> P[i].first >> P[i].second;
  }
  if (K == 1) {
    print("Infinity");
    return 0;
  }
  int res = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      int cnt_on_line = 0;
      rep(k,N) {
        if (on_line(P[i], P[j], P[k])) {
          if (k<i || (k>i && k<j)) {
            cnt_on_line = 0;
            break;
          } else {
            cnt_on_line++;
          }
        }
      }
      if (cnt_on_line >= K)
        res++;
    }
  }
  print(res);
  return 0;
}
