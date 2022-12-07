#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int T[N], sum = 0;
  for (int i=0; i<N; i++) {
    cin >> T[i];
    sum += T[i];
  }
  int M;
  cin >> M;
  int P[M], X[M];
  for (int i=0; i<M; i++)
    cin >> P[i] >> X[i];
  for (int i=0; i<M; i++)
    cout << sum - T[P[i]-1] + X[i] << endl;;
  return 0;
}
