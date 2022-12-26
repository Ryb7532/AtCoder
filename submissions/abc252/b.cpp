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
  int N,K;
  cin >> N >> K;
  vector<int> Mid;
  int M = 0;
  rep(i,N) {
    int A;
    cin >> A;
    if (A>M) {
      Mid.clear();
      M = A;
      Mid.push_back(i);
    } else if (A==M) {
      Mid.push_back(i);
    }
  }
  bool flag = false;
  rep(i,K) {
    int B;
    cin >> B;
    B--;
    rep(j,Mid.size()) {
      if (Mid[j] == B)
        flag = true;
    }
  }
  print((flag ? Yes : No));
  return 0;
}
