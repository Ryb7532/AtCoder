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




int main() {
  int N;
  cin >> N;
  int res = -1;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,N) {
    int v = 0;
    vector<int> used(N,-1);
    used[i] = 0;
    set<int> V;
    V.insert(i);
    while (!V.empty()) {
      v++;
      set<int> next;
      bool flag = true;
      for (int e: V) {
        rep(j,N) {
          if (S[e][j]=='1') {
            if (used[e]==used[j])
              flag = false;
            if (used[j]<0) {
              used[j] = v;
              next.insert(j);
            }
          }
        }
      }
      if (!flag) {
        v = -1;
        break;
      }
      V = next;
    }
    res = max(res,v);
  }
  print(res);
  return 0;
}
