#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int T;
  cin >> T;
  rep(_,T) {
    int N;
    cin >> N;
    vector<ll> K(N), L(N), R(N);
    vector<int> id0, id1;
    priority_queue<ll, vector<ll>, greater<ll>> q0, q1;
    rep(i,N) {
      cin >> K[i] >> L[i] >> R[i];
      if (L[i]>=R[i]) {
        id0.push_back(i);
      } else {
        K[i] = N-K[i];
        swap(L[i], R[i]);
        id1.push_back(i);
      }
    }
    auto f = [&](int a, int b) {
      return K[a] < K[b];
    };
    sort(all(id0), f);
    sort(all(id1), f);
    ll res = 0;
    for (int id: id0) {
      res += L[id];
      q0.push(L[id]-R[id]);
      if (q0.size() > K[id]) {
        res -= q0.top();
        q0.pop();
      }
    }
    for (int id: id1) {
      res += L[id];
      q1.push(L[id]-R[id]);
      if (q1.size() > K[id]) {
        res -= q1.top();
        q1.pop();
      }
    }
    print(res);
  }
  return 0;
}