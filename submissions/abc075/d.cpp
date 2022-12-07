#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

//昇順
int acs(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main() {
  int N, K;
  cin >> N >> K;
  int x[N], y[N], sx[N], sy[N], xi, yi;
  for (int i=0; i<N; i++) {
    cin >> xi >> yi;
    x[i] = sx[i] = xi;
    y[i] = sy[i] = yi;
  }
  qsort(sx, N, sizeof(int), acs);
  qsort(sy, N, sizeof(int), acs);
  long ans = LONG_MAX;
  for (int lx=0; lx<N-K+1; lx++) {
    for (int rx=lx+K-1; rx<N; rx++) {
      for (int by=0; by<N-K+1; by++) {
        for (int ty=by+K-1; ty<N; ty++) {
          long Lx = sx[lx], Rx = sx[rx], By = sy[by], Ty = sy[ty];
          int cnt = 0;
          for (int i=0; i<N && cnt<K; i++) {
            if (Lx<=x[i] && x[i]<=Rx && By<=y[i] && y[i]<=Ty)
              cnt++;
          }
          if (cnt==K)
            ans = min(ans, (Rx-Lx)*(Ty-By));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
