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
  string S;
  ll N;
  cin >> S >> N;
  string T;
  while (N != 0) {
    T.push_back('0'+N%2);
    N /= 2;
  }
  reverse(all(T));
  string padding;
  rep(i,abs((int)T.size()-(int)S.size()))
    padding.push_back('0');
  if (S.size() > T.size())
    T = padding + T;
  else
    S = padding + S;
  int l = S.size();
  int p = -1;
  rep(i,l+1) {
    if (i == l) {
      p = i;
      break;
    }
    if (S[i] == T[i])
      continue;
    if (S[i] == '?') {
      if (T[i] == '1')
        p = i;
      continue;
    }
    if (S[i] == '1') {
      if (p >= 0) {
        S[p] = '0';
      }
    } else {
      p = i;
    }
    break;
  }
  ll res = 0;
  rep(i,l) {
    res *= 2;
    if (i < p) {
      res += T[i]-'0';
    } else {
      res += (S[i]=='?') ? 1 : S[i]-'0';
    }
  }
  if (p < 0)
    res = -1;
  print(res);
  return 0;
}
