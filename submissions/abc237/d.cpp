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
  string S;
  cin >> N >> S;
  vector<int> L,R;
  rep(i,N) {
    if (S[i]=='L') {
      R.push_back(i);
    } else {
      L.push_back(i);
    }
  }
  int l = L.size(), r = R.size();
  stringstream ss;
  rep(i,l) {
    ss << L[i] << ' ';
  }
  ss << N << ' ';
  rep(i,r) {
    ss << R[r-1-i] << ' ';
  }
  print(ss.str());
  return 0;
}
