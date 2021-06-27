#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  char c[6] = "LRUD?";
  int T, cnt[5] = {0, 0, 0, 0, 0}, ans = 0;
  cin >> S >> T;
  int n = S.size();
  for (int i=0; i<n; i++)
    for (int j=0; j<5; j++)
      if (S[i] == c[j])
        cnt[j]++;
  ans = abs(cnt[0]-cnt[1]) + abs(cnt[2]-cnt[3]);
  if (T == 1)
    ans += cnt[4];
  else if (cnt[4]>ans) {
    ans = (cnt[4]-ans)%2;
  } else
    ans -= cnt[4];
  cout << ans << endl;
  return 0;
}
