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
  ll a,b;
  cin >> a >> b;
  a--;
  ll ans = b-a;
  int id=19;
  vi A(19,0), B(19,0);
  while (a!=0) {
    A[--id] = a%10;
    a /= 10;
  }
  id=19;
  while (b!=0) {
    B[--id] = b%10;
    b /= 10;
  }
  vector<vector<ll>> dpa(20,vector<ll>(2,0)), dpb(20,vector<ll>(2,0));
  dpa[0][1] = 1;
  dpb[0][1] = 1;
  rep(i,19) {
    dpa[i+1][0] += dpa[i][0]*8;
    dpb[i+1][0] += dpb[i][0]*8;
    if (A[i]<4) {
      dpa[i+1][0] += dpa[i][1]*A[i];
      dpa[i+1][1] = dpa[i][1];
    } else if (A[i]==4) {
      dpa[i+1][0] += dpa[i][1]*4;
      dpa[i+1][1] = 0;
    } else if (A[i]<9) {
      dpa[i+1][0] += dpa[i][1]*(A[i]-1);
      dpa[i+1][1] = dpa[i][1];
    } else {
      dpa[i+1][0] += dpa[i][1]*8;
      dpa[i+1][1] = 0;
    }
    if (B[i]<4) {
      dpb[i+1][0] += dpb[i][1]*B[i];
      dpb[i+1][1] = dpb[i][1];
    } else if (B[i]==4) {
      dpb[i+1][0] += dpb[i][1]*4;
      dpb[i+1][1] = 0;
    } else if (B[i]<9) {
      dpb[i+1][0] += dpb[i][1]*(B[i]-1);
      dpb[i+1][1] = dpb[i][1];
    } else {
      dpb[i+1][0] += dpb[i][1]*8;
      dpb[i+1][1] = 0;
    }
  }
  ans -= dpb[19][0]+dpb[19][1];
  ans += dpa[19][0]+dpa[19][1];
  print(ans);
  return 0;
}
