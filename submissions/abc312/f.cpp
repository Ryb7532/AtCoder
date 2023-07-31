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
  int N,M;
  cin >> N >> M;
  vector<ll> A,B,C;
  rep(i,N) {
    int t;
    ll x;
    cin >> t >> x;
    if (t == 0)
      A.push_back(x);
    if (t == 1)
      B.push_back(x);
    if (t == 2)
      C.push_back(x);
  }
  sort(rall(A));
  sort(rall(B));
  sort(rall(C));
  int sa = A.size(), sb = B.size(), sc = C.size();
  vector<ll> sumA(sa+1, 0), sumB(sb+1, 0);
  rep(i,sa) {
    sumA[i+1] = sumA[i]+A[i];
  }
  rep(i,sb) {
    sumB[i+1] = sumB[i]+B[i];
  }
  ll res = 0;
  int ic = 0;
  int cnt = 0;
  rep(i,sb+1) {
    ll tmp = 0;
    while (ic < sc && cnt < i) {
      cnt += C[ic++];
    }
    if (cnt < i || M-ic < i)
      break;
    tmp += sumB[i];
    tmp += sumA[min(sa, max(M-i-ic,0))];
    res = max(res, tmp);
  }
  print(res);
  return 0;
}
