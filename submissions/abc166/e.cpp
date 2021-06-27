#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long A, cnt[200000][2] = {}, ans = 0;
  for (int i=0; i<N; i++) {
    cin >> A;
    if (A+i<N-1)
      cnt[A+i][0]++;
    if (i-A>0)
      cnt[i-A][1]++;
  }
  for (int i=1; i<N-1; i++)
    ans += cnt[i][0]*cnt[i][1];
  cout << ans << endl;
  return 0;
}
