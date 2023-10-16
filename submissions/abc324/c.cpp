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
  int N;
  string T;
  cin >> N >> T;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  int st = T.size();
  vector<int> res;
  rep(i,N) {
    int ss = S[i].size();
    if (abs(ss-st) >= 2)
      continue;
    bool flag = true;
    if (ss == st) {
      int cnt = 0;
      rep(j,ss) {
        if (S[i][j] != T[j])
          cnt++;
      }
      flag = cnt <= 1;
    } else if (ss > st) {
      int k = 0;
      rep(j,st) {
        while (k < ss && S[i][k] != T[j])
          k++;
        if (k >= ss) {
          flag = false;
          break;
        }
        k++;
      }
    } else {
      int k = 0;
      rep(j,ss) {
        while (k < st && S[i][j] != T[k])
          k++;
        if (k >= st) {
          flag = false;
          break;
        }
        k++;
      }
    }
    if (flag)
      res.push_back(i+1);
  }
  print(res.size());
  printall(res);
  return 0;
}