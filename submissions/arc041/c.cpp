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
  ll N,L;
  cin >> N >> L;
  int x[N+2]; string d[N+2];
  rep1(i,N) {
    cin >> x[i] >> d[i];
  }
  x[0] = 0; d[0] = "L";
  x[N+1] = L+1; d[N+1] = "R";
  ll ans = 0, r = 0, l = 0, dis = 0;
  rep1(i,N+1) {
    if (d[i-1] == "L" && d[i] == "L") {
      ans += x[i]-x[i-1]-1;
      x[i] = x[i-1]+1;
      l++;
    } else if (d[i-1] == "R" && d[i] == "R") {
      ans += r*(x[i]-x[i-1]-1);
      r++;
    } else if (d[i-1] == "R" && d[i] == "L") {
      dis = x[i]-x[i-1]-1;
      l++;
    } else {
      ans += max(r,l)*dis;
      r = 1;
      l = 0;
    }
  }
  print(ans);
  return 0;
}
