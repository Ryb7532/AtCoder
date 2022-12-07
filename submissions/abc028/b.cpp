#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  string S;
  int n, cnt[6];
  cin >> S;
  n = S.size();
  fill(cnt, cnt+6, 0);
  for (int i=0; i<n; i++)
    cnt[S[i]-'A']++;
  rep(i, 6) {
    cout << cnt[i];
    if (i<5)
      cout << " ";
  }
  cout << endl;
  return 0;
}
