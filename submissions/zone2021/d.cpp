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

int main() {
  string S;
  cin >> S;
  int ord = 0;
  vector<string> T(2);
  for (char c: S) {
    if (c == 'R') {
      ord = 1-ord;
      continue;
    }
    if (!T[ord].empty() && T[ord].back() == c) {
      T[ord].pop_back();
    } else {
      T[ord].push_back(c);
    }
  }
  reverse(all(T[0]));
  reverse(all(T[1]));
  while (!T[0].empty() && !T[1].empty() && T[0].back() == T[1].back()) {
    T[0].pop_back();
    T[1].pop_back();
  }
  reverse(all(T[0]));
  string res = T[1] + T[0];
  if (ord)
    reverse(all(res));
  print(res);
  return 0;
}