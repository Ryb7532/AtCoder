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
  int N;
  string S,T;
  cin >> N >> S >> T;
  S += "..";
  T += "..";
  N += 2;
  queue<string> q;
  map<string,int> dp;
  dp[T] = -1;
  dp[S] = 0;
  if (S != T)
    q.push(S);
  while (!q.empty()) {
    string U = q.front();
    q.pop();
    int cost = dp[U];
    int k = 0;
    rep(i,N-1) {
      if (U[i] == '.' && U[i+1] == '.')
        k = i;
    }
    rep(i,N-1) {
      if (i >= k-1 && i <= k+1)
        continue;
      swap(U[i], U[k]);
      swap(U[i+1], U[k+1]);
      if (U == T) {
        dp[T] = cost+1;
        while (!q.empty())
          q.pop();
        break;
      }
      if (dp.find(U) == dp.end()) {
        dp[U] = cost+1;
        q.push(U);
      }
      swap(U[i], U[k]);
      swap(U[i+1], U[k+1]);
    }
  }
  print(dp[T]);
  return 0;
}