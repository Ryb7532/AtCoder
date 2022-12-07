#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int n;
  cin >> n;
  int a, b, cnt[1000002], ans;
  fill(cnt, cnt+1000002, 0);
  rep(i, n) {
    cin >> a >> b;
    cnt[a]++;
    cnt[b+1]--;
  }
  ans = cnt[0];
  rep1(i, 1000001) {
    cnt[i] += cnt[i-1];
    ans = max(ans, cnt[i]);
  }
  print(ans);
  return 0;
}
