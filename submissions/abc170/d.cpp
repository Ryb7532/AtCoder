#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, a;
  cin >> N;
  vector<int> A;
  for (int i=0; i<N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  bool c[A[N-1]+1];
  fill(c, c+A[N-1]+1, true);
  for (int i=2*A[0]; i<=A[N-1]; i+=A[0])
    c[i] = false;
  for (int i=1; i<N; i++) {
    if (A[i-1] == A[i])
      c[A[i]] = false;
    else {
      if (!c[A[i]])
        continue;
      for (int j=2*A[i]; j<=A[N-1]; j+=A[i])
        c[j] = false;
    }
  }
  int ans = 0;
  for (int i=0; i<N; i++)
    if (c[A[i]])
      ans++;
  cout << ans << endl;
  return 0;
}
