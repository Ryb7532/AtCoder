#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int L,R;
  cin >> L >> R;
  vi l(L),r(R);
  rep(i,L) {
    cin >> l[i];
  }
  rep(i,R) {
    cin >> r[i];
  }
  sort(all(l)); sort(all(r));
  int li=0,ri=0,ans=0;
  while (li<L && ri<R) {
    if (l[li] == r[ri]) {
      ans++;
      li++;
      ri++;
    } else if (l[li] > r[ri]) {
      ri++;
    } else {
      li++;
    }
  }
  print(ans);
  return 0;
}
