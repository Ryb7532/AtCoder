#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


ll GCD(ll a, ll b) {
  while(b != 0) {
    swap(a %= b, b);
  }
  return a;
}

int main() {
  int N;
  cin >> N;
  vec<pair<ll,ll>> City(N);
  rep(i,N) {
    cin >> City[i].first >> City[i].second;
  }
  set<pair<ll,ll>> magic;
  rep(i,N) {
    rep(j,N) {
      if (i == j)
        continue;
      ll dis_x = City[i].first-City[j].first, dis_y = City[i].second - City[j].second;
      ll gcd = GCD(abs(dis_x), abs(dis_y));
      dis_x /= gcd;
      dis_y /= gcd;
      magic.insert({dis_x, dis_y});
    }
  }
  print(magic.size());
  return 0;
}
