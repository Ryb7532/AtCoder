#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size(), mod2019[n+1], dig = 1, cnt[2019] = {};
  mod2019[n] = 0;
  cnt[0]++;
  for (int i=n-1; i>=0; i--) {
    mod2019[i] = (dig * (S[i]-'0') + mod2019[i+1]) % 2019;
    dig *= 10;
    dig %= 2019;
    cnt[mod2019[i]]++;
  }
  long ans = 0;
  for (int i=0; i<2019; i++)
    ans += cnt[i]*(cnt[i]-1)/2;
  cout << ans << endl;
  return 0;
}
