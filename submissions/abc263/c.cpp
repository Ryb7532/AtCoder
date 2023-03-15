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

int N, M;
vector<int> arr(10);

void dfs(int l, int m) {
  if (l == N) {
    rep(i,N) {
      cout << arr[i] << ' ';
    }
    cout << endl;
    return ;
  }
  for (int i=m; i<=M; i++) {
    arr[l] = i;
    dfs(l+1, i+1);
  }
  return ;
}

int main() {
  cin >> N >> M;
  dfs(0,1);
  return 0;
}
