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
  vector<int> X(N), Y(N);
  string S;
  rep(i,N) {
    cin >> X[i] >> Y[i];
  }
  cin >> S;
  bool flag = false;
  map<int, set<int>> right, left;
  rep(i,N) {
    if (S[i] == 'R') {
      right[Y[i]].insert(X[i]);
      if (left[Y[i]].lower_bound(X[i]) != left[Y[i]].end())
        flag = true;
    } else {
      left[Y[i]].insert(X[i]);
      if (right[Y[i]].lower_bound(X[i]) != right[Y[i]].begin())
        flag = true;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
