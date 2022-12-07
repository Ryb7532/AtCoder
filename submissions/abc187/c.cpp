#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  map<string, int> m, mnot;
  rep(i,N) {
    string S;
    cin >> S;
    if (S[0] == '!') {
      S.erase(0,1);
      m[S]++;
    } else {
      mnot[S]++;
    }
  }
  for (auto &e: m) {
    if (mnot[e.first]>0) {
      print(e.first);
      return 0;
    }
  }
  print("satisfiable");
  return 0;
}
