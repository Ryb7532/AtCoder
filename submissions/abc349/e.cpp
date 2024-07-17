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

vector<ll> A(9);
ll sum;
vector<int> G(9, -1);

bool check(int p) {
  bool flag = false;
  rep(i,3) {
    bool f = true;
    rep(j,3) {
      f = f && (G[3*i+j] == p);
    }
    flag = flag || f;
  }
  rep(j,3) {
    bool f = true;
    rep(i,3) {
      f = f && (G[3*i+j] == p);
    }
    flag = flag || f;
  }
  bool f = true;
  rep(i,3) {
    f = f && (G[3*i+i] == p);
  }
  flag = flag || f;
  f = true;
  rep(i,3) {
    f = f && (G[3*i+2-i] == p);
  }
  flag = flag || f;
  return flag;
}

int dfs(int n) {
  if (n == 9) {
    ll p = 0;
    rep(i,9) {
      if (G[i] == 0)
        p += A[i];
    }
    return p <= sum-p;
  }
  bool flag = false;
  rep(i,9) {
    if (G[i] >= 0)
      continue;
    G[i] = n%2;
    if (check(n%2)) {
      flag = true;
      G[i] = -1;
      continue;
    }
    int p = dfs(n+1);
    if (p == n%2)
      flag = true;
    G[i] = -1;
  }
  if (flag)
    return n%2;
  else
    return 1-n%2;
}


int main() {
  rep(i,9) {
    cin >> A[i];
    sum += A[i];
  }
  bool flag = dfs(0);
  print(flag==0 ? "Takahashi" : "Aoki");
  return 0;
}