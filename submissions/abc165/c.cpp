#include <bits/stdc++.h>
using namespace std;

int N, M, Q, a[50], b[50], c[50], d[50], ans, cnt[10], num[10];

void dfs(int m, int r) {
  if (m == M-1) {
    for (int i=N-r; i<N; i++)
      num[i] = M-1;
    int res = 0;
    for (int i=0; i<Q; i++) {
      if (num[b[i]]-num[a[i]] == c[i])
        res += d[i];
    }
    ans = max(ans, res);
    return ;
  }
  for (int i=0; i<=r; i++) {
    for (int j=N-r; j<N-r+i; j++)
      num[j] = m;
    dfs(m+1, r-i);
  }
  return ;
}
int main() {
  cin >> N >> M >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }
  dfs(0, N);
  cout << ans << endl;
  return 0;
}
