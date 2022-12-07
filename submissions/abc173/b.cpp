#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N;
  cin >> N;
  string S, R[4] = {"AC", "WA", "TLE", "RE"};
  int cnt[4];
  fill(cnt, cnt+4, 0);
  rep(i, N) {
    cin >> S;
    rep(j, 4) {
      if (S.compare(R[j]) == 0)
        cnt[j]++;
    }
  }
  rep(i, 4) {
    cout << R[i] << " x " << cnt[i] << endl;
  }
  return 0;
}
