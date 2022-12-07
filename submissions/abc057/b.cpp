#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int a[N], b[N], c[M], d[M], ans[N];
  for (int i=0; i<N; i++)
    cin >> a[i] >> b[i];
  for (int i=0; i<M; i++)
    cin >> c[i] >> d[i];
  for (int i=0; i<N; i++) {
    int dis = INT_MAX, x = a[i], y = b[i];
    for (int j=0; j<M; j++) {
      if (dis > abs(x-c[j])+abs(y-d[j])) {
        dis = abs(x-c[j])+abs(y-d[j]);
        ans[i] = j+1;
      }
    }
  }
  for (int i=0; i<N; i++)
    cout << ans[i] << endl;
  return 0;
}
