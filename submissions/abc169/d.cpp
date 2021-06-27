#include <bits/stdc++.h>
using namespace std;
int cnt[1000001];

int main() {
  long N, M;
  int ans = 0;
  cin >> N;
  M = N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i=2; i<sqrt((double)N)+1; i++) {
    if (N%i)
      continue;
    while (N%i == 0) {
      cnt[i]++;
      N /= i;
    }
  }
  if (N == M) {
    cout << 1 << endl;
    return 0;
  }
  if (N != 1)
    ans++;
  for (int i=2; i<1000001; i++) {
    if (cnt[i] == 0)
      continue;
    int time = 1;
    while (time <= cnt[i]) {
      ans++;
      cnt[i] -= time;
      time++;
    }
  }
  cout << ans << endl;
  return 0;
}
