#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  ll A[N], B[M], sumA[N+1], sumB[M+1];
  sumA[0] = 0;
  sumB[0] = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    sumA[i+1] = sumA[i] + A[i];
  }
  for (int i=0; i<M; i++) {
    cin >> B[i];
    sumB[i+1] = sumB[i] + B[i];
  }
  int ans = 0, a = 0, b = M;
  while (a <= N) {
    while (b != 0 && sumB[b] > K-sumA[a])
      b--;
    if (sumA[a]+sumB[b] <= K)
      ans = max(ans, a+b);
    a++;
  }
  cout << ans << endl;
  return 0;
}
