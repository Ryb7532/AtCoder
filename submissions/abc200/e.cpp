#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<vector<ll>> cnt(4, vector<ll>(3*N, 0));
  cnt[0][0] = 1;
  rep(i,3) {
    ll sum = 0;
    rep(j,3*N) {
      sum += cnt[i][j];
      if (j >= N) {
        sum -= cnt[i][j-N];
      }
      cnt[i+1][j] = sum;
    }
  }
  rep(sum,3*N) {
    if (cnt[3][sum] < K) {
      K -= cnt[3][sum];
      continue;
    }
    rep(i,N) {
      if (cnt[2][sum-i] < K) {
        K -= cnt[2][sum-i];
        continue;
      }
      cout << i+1 << " ";
      rep(j,N) {
        if (cnt[1][sum-i-j] < K) {
          K -= cnt[1][sum-j-i];
          continue;
        }
        cout << j+1 << " " << sum-i-j+1 << endl;
        break;
      }
      break;
    }
    break;
  }
  return 0;
}
