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
  int best = -1, score = -1;
  set<string> used;
  rep(i,N) {
    string S;
    int T;
    cin >> S >> T;
    if (used.find(S) == used.end()) {
      used.insert(S);
      if (score < T) {
        best = i+1;
        score = T;
      }
    }
  }
  print(best);
  return 0;
}
