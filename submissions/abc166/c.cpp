#include <bits/stdc++.h>
using namespace std;
bool good[100000];

int main() {
  int N, M;
  cin >> N >> M;
  fill(good, good+N, true);
  int H[N], A, B;
  for (int i=0; i<N; i++)
    cin >> H[i];
  for (int i=0; i<M; i++) {
    cin >> A >> B;
    A--;
    B--;
    if (H[A] <= H[B])
      good[A] = false;
    if (H[B] <= H[A])
      good[B] = false;
  }
  int ans = 0;
  for (int i=0; i<N; i++)
    if (good[i])
      ans++;
  cout << ans << endl;
  return 0;
}
