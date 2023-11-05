#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,X;
  cin>> N;
  vector<vector<int>> A(N);
  rep(i,N) {
    int C;
    cin >> C;
    A[i].resize(C);
    rep(j,C) {
      cin >> A[i][j];
    }
  }
  cin >> X;
  int mcnt = 1e9;
  vector<int> res;
  rep(i,N) {
    bool hasX = false;
    for (int a: A[i]) {
      if (a == X) {
        hasX = true;
        break;
      }
    }
    if (hasX && mcnt > A[i].size()) {
      res.clear();
      res.push_back(i+1);
      mcnt = A[i].size();
    } else if (hasX && mcnt == A[i].size()) {
      res.push_back(i+1);
    }
  }
  print(res.size());
  for (int a: res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}