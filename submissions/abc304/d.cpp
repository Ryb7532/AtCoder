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
  int W,H,N;
  cin >> W >> H >> N;
  vector<int> P(N), Q(N);
  rep(i,N) {
    cin >> P[i] >> Q[i];
  }
  int Na,Nb;
  cin >> Na;
  vector<int> A(Na+1);
  A[Na] = W;
  rep(i,Na) {
    cin >> A[i];
  }
  cin >> Nb;
  vector<int> B(Nb+1);
  B[Nb] = H;
  rep(i,Nb) {
    cin >> B[i];
  }
  int nmin = N, nmax = 0;
  map<pair<int,int>,int> cnt;
  rep(i,N) {
    int newp = *lower_bound(all(A), P[i]), newq = *lower_bound(all(B), Q[i]);
    nmax = max(nmax, ++cnt[{newp, newq}]);
  }
  if (((ll)Na+1)*(Nb+1) > N) {
    nmin = 0;
  } else {
    for (int a: A) {
      for (int b: B) {
        nmin = min(nmin, cnt[{a,b}]);
      }
    }
  }
  print(nmin << " " << nmax);
  return 0;
}
