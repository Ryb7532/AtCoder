#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

map<int,int> memo;
int f(int n) {
  if (memo.find(n) != memo.end())
    return memo[n];
  int one = 0, n_ = n;
  while (n_ > 0) {
    if (n_&1)
      one++;
    n_ /= 2;
  }
  return memo[n] = f(n%one)+1;
}


int main() {
  int N;
  string X;
  cin >> N >> X;
  int cnt = 0;
  rep(i,N) {
    if (X[i] == '1')
      cnt++;
  }
  vector<vector<int>> P(N, vector<int>(2,1));
  if (cnt > 1)
    P[N-1][0] %= cnt-1;
  else
    P[N-1][0] = 0;
  P[N-1][1] %= cnt+1;
  rrep(i,N-1) {
    P[i][0] = P[i+1][0] * 2;
    P[i][1] = P[i+1][1] * 2;
    if (cnt > 1)
      P[i][0] %= cnt-1;
    P[i][1] %= cnt+1;
  }
  vector<int> R(2,0);
  rep(i,N) {
    R[0] *= 2;
    R[1] *= 2;
    if (cnt > 1)
      R[0] %= cnt-1;
    R[1] %= cnt+1;
    if (X[i] == '1') {
      R[0]++;
      R[1]++;
    }
  }
  if (cnt <= 1)
    R[0] = 0;
  memo[0] = 0;
  rep(i,N) {
    if (X[i] == '1') {
      if (cnt == 1) {
        print(0);
        continue;
      }
      int n = R[0] + cnt - 1 - P[i][0];
      n %= cnt-1;
      print(f(n)+1);
    } else {
      int n = R[1] + P[i][1];
      n %= cnt+1;
      print(f(n)+1);
    }
  }
  return 0;
}