#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, M;
  cin >> N >> M;
  int s[M],t[M],cls[N+1];
  fill(cls,cls+N+1,0);
  set<int> one;
  rep(i,M) {
    cin >> s[i] >> t[i];
    s[i]--; t[i]--;
    cls[s[i]]++;
    cls[t[i]+1]--;
  }
  if (cls[0] == 1)
    one.insert(0);
  rep1(i,N) {
    cls[i] += cls[i-1];
    if (cls[i] == 1)
      one.insert(i);
  }
  int cnt = 0;
  vector<int> ans;
  rep(i,M) {
    auto it = one.lower_bound(s[i]);
    if (it == one.end() || *it>t[i]) {
      cnt++;
      ans.push_back(i+1);
    }
  }
  print(cnt);
  rep(i,cnt) {
    print(ans[i]);
  }
  return 0;
}
