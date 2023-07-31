#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

ll GCD(ll a, ll b) {
  if (b==0) {
    return a;
  }
  return GCD(b, a%b);
}

int main() {
  int N;
  cin >> N;
  vector<pair<ll,ll>> AB(N);
  vector<int> res(N);
  rep(i,N) {
    ll A,B;
    cin >> A >> B;
    ll g = GCD(A,B);
    A /= g; B /= g;
    AB[i] = {A,B};
    res[i] = i;
  }
  auto f = [&](int a, int b) {
    ll v = AB[a].first * AB[b].second - AB[a].second * AB[b].first;
    if (v != 0)
      return v > 0;
    return a < b;
  };
  sort(all(res), f);
  rep(i,N) {
    cout << res[i]+1 << " ";
  }
  cout << endl;
  return 0;
}
