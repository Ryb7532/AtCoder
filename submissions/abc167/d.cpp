#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long K;
  cin >> N >> K;
  int A[N];
  for (int i=0; i<N; i++) {
    cin >> A[i];
    A[i]--;
  }
  int cnt[N], n = A[0], time = 0, ans;
  for (int i=0; i<N; i++)
    cnt[i] = -1;
  cnt[0] = 0;
  while (cnt[n] == -1) {
    time++;
    cnt[n] = time;
    n = A[n];
  }
  if (K<=time) {
    for (int i=0; i<N; i++)
      if (cnt[i]==K)
        ans = i+1;
  } else {
    K -= cnt[n];
    time -= cnt[n]-1;
    int m = K%time;
    for (int i=0; i<N; i++)
      if (cnt[i]==m+cnt[n])
        ans = i+1;
  }
  cout << ans << endl;
  return 0;
}
