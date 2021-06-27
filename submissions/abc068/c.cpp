#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, a, b;
  cin >> N >> M;
  vector<bool> from1(N, false), toN(N, false);
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    a--;
    b--;
    if (a == 0)
      from1[b] = true;
    if (b == N-1)
      toN[a] = true;
  }
  for (int i=0; i<N; i++)
    if (from1[i] && toN[i]) {
      cout << "POSSIBLE\n";
      return 0;
    }
  cout << "IMPOSSIBLE\n";
  return 0;
}