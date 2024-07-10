#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define out1(a) cout << (a) << endl
#define out2(a,b) cout << (a) << " " << (b) << endl
#define out3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl
#define print(...) GET_MACRO(__VA_ARGS__,out3,out2,out1)(__VA_ARGS__)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define Yes "Yes"
#define No "No"
#define printyn(f) cout << (f ? Yes : No) << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}

int main() {
  string T;
  int N;
  cin >> T >> N;
  int M = T.size();
  vector<int> A(N);
  vector<vector<string>> S(N);
  rep(i,N) {
    cin >> A[i];
    rep(A[i]) {
      string s;
      cin >> s;
      S[i].push_back(s);
    }
  }
  vector<vector<int>> dp(N+1, vector<int>(M+1,1e9));
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,M) {
      rep(k,A[i]) {
        bool flag = true;
        int L = S[i][k].size();
        rep(l,L) {
          if (j+l >= M || S[i][k][l] != T[j+l]) {
            flag = false;
            break;
          }
        }
        if (!flag)
          continue;
        chmin(dp[i+1][j+L], dp[i][j]+1);
      }
      chmin(dp[i+1][j], dp[i][j]);
    }
    chmin(dp[i+1][M], dp[i][M]);
  }
  if (dp[N][M] == 1e9)
    dp[N][M] = -1;
  print(dp[N][M]);
  return 0;
}