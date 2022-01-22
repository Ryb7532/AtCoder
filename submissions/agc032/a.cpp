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
  vector<int> B(N);
  rep(i,N) {
    cin >> B[i];
  }
  vector<int> res;
  vector<bool> used(N, false);
  rep(i,N) {
    int cnt_used = i;
    int j = N-1;
    while (j>=0) {
      if (used[j]) {
        cnt_used--;
      } else if (B[j] == j-cnt_used+1) {
        res.push_back(B[j]);
        used[j] = true;
        break;
      }
      j--;
    }
    if (j<0)
      break;
  }
  if (res.size() != N) {
    print(-1);
  } else {
    for (int i=N-1; i>=0; i--) {
      print(res[i]);
    }
  }
  return 0;
}
