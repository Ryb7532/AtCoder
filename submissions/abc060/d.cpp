#include <bits/stdc++.h>
using namespace std;

//降順
int des(const void *a, const void *b)
{
  return *(long *)b - *(long *)a;
}

int main() {
  int N, W;
  cin >> N >> W;
  long vl[4][N], w_s, w, v, csum[4][N+1], ans = 0, sumv = 0, sumw = 0;
  int cnt[4] = {1, 0, 0, 0};
  cin >> w_s >> vl[0][0];
  for (int i=1; i<N; i++) {
    cin >> w >> v;
    vl[w-w_s][cnt[w-w_s]] = v;
    cnt[w-w_s]++;
  }
  for (int i=0; i<4; i++) {
    if (cnt[i] == 0)
      continue;
    qsort(vl[i], cnt[i], sizeof(long), des);
  }
  for (int i=0; i<4; i++) {
    csum[i][0] = 0;
    for (int j=0; j<cnt[i]; j++)
      csum[i][j+1] = csum[i][j] + vl[i][j];
  }
  for (int i0=0; i0<=cnt[0]; i0++) {
    sumv = 0;
    for (int i1=0; i1<=cnt[1]; i1++) {
      for (int i2=0; i2<=cnt[2]; i2++) {
        for (int i3=0; i3<=cnt[3]; i3++) {
          sumw = w_s*i0 + (w_s+1)*i1 + (w_s+2)*i2 + (w_s+3)*i3;
          if (sumw > W)
            break;
          sumv = csum[0][i0] + csum[1][i1] + csum[2][i2] + csum[3][i3];
          ans = max(ans, sumv);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}