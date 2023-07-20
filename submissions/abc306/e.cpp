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

int main() {
  int N,K,Q;
  cin >> N >> K >> Q;
  vector<ll> A(N, 0);
  multiset<ll> inK;
  multiset<ll, greater<ll>> outofK;
  ll sumK = 0;
  rep(i,K) {
    inK.insert(0);
  }
  rep(i,N-K) {
    outofK.insert(0);
  }
  auto sort = [&](){
    if (outofK.size() == 0)
      return ;
    while (true) {
      auto it_min = inK.begin(), it_max = outofK.begin();
      if (*it_max <= *it_min)
        break;
      sumK += *it_max-*it_min;
      inK.insert(*it_max);
      outofK.insert(*it_min);
      inK.erase(it_min);
      outofK.erase(it_max);
    }
  };
  auto update = [&](int x, ll y){
    ll a = A[x];
    if (inK.find(a) != inK.end()) {
      inK.insert(y);
      sumK += y;
      inK.erase(inK.find(a));
      sumK -= a;
    } else {
      outofK.insert(y);
      outofK.erase(outofK.find(a));
    }
    A[x] = y;
    sort();
  };
  rep(_,Q) {
    int X;
    ll Y;
    cin >> X >> Y;
    X--;
    update(X,Y);
    print(sumK);
  }
  return 0;
}
