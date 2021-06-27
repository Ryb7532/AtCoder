#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long A[N][N], B[N][N], ans = 0;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
      B[i][j] = A[i][j];
    }
  for (int k=0; k<N; k++)
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++)
        B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (A[i][j] > B[i][j]) {
        cout << -1 << endl;
        return 0;
      }
      if (i == j)
        continue;
      bool need = true;
      for (int k=0; k<N; k++) {
        if (k == i || k == j)
          continue;
        if (A[i][j] == A[i][k]+A[k][j])
          need = false;
      }
      if (need)
        ans += A[i][j];
    }
  }
  cout << ans/2 << endl;
  return 0;
}
