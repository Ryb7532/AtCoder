#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, d, a;
  cin >> N >> K;
  int have[100] = {};
  for (int i=0; i<K; i++) {
    cin >> d;
    for (int j=0; j<d; j++) {
      cin >> a;
      a--;
      have[a]++;
    }
  }
  int ans = 0;
  for (int i=0; i<N; i++)
    if (have[i] == 0)
      ans++;
  cout << ans << endl;
  return 0;
}
