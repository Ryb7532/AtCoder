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
  vector<int> A(N),B(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    cin >> B[i];
  }
  set<int> res;
  rep(i,N) {
    multiset<int> unused;
    rep(j,N) {
      unused.insert(B[j]);
    }
    int x = A[0]^B[i];
    rep(j,N) {
      if (unused.find(x^A[j]) == unused.end()) {
        break;
      }
      unused.erase(unused.find(x^A[j]));
    }
    if (unused.empty()) {
      res.insert(x);
    }
  }
  print(res.size());
  for (int e: res) {
    print(e);
  }
  return 0;
}
