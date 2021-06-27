#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string A[N], B[M];
  for (int i=0; i<N; i++)
    cin >> A[i];
  for (int i=0; i<M; i++)
    cin >> B[i];
  for (int i=0; i<=N-M; i++) {
    for (int j=0; j<=N-M; j++) {
      bool check = true;
      for (int k=0; k<M; k++)
        for (int l=0; l<M; l++)
          if (B[k][l] != A[i+k][j+l])
            check = false;
      if (check) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
