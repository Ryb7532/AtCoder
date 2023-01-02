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
#define YES "YES"
#define No "No"
#define NO "NO"


vector<int> H(3),W(3);
vector<vector<int>> B(3, vector<int>(3));
int res = 0;

void dfs(int h, int w) {
  if (h == 3) {
    rep(i,3) {
      if (W[i] != 0)
        return;
    }
    res++;
  }
  if (w == 3) {
    int sum = 0;
    rep(i,3) {
      sum += B[h][i];
    }
    if (H[h] == 0)
      dfs(h+1, 0);
    return;
  }
  for (int n = 1; n <= min(H[h], W[w]); n++) {
    B[h][w] = n;
    H[h] -= n;
    W[w] -= n;
    dfs(h, w+1);
    B[h][w] = 0;
    H[h] += n;
    W[w] += n;
  }
  return;
}

int main() {
  rep(i,3) {
    cin >> H[i];
  }
  rep(i,3) {
    cin >> W[i];
  }
  dfs(0,0);
  print(res);
  return 0;
}
