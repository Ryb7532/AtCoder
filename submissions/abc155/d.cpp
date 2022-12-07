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

ll N, K;
vector<ll> P, M;
ll p, m, z;

bool jugde_m(ll x) {
  ll cnt = 0;
  int ip = p, im = 0;
  while (im<m) {
    while (ip>0 && M[im]*P[ip-1]>x) {
      ip--;
    }
    cnt += ip;
    im++;
  }
  return cnt>=K;
}

bool jugde_p(ll x) {
  ll cnt = 0;
  int a, b;
  a = 0; b = p-1;
  while (a<b) {
    while (a<b && P[a]*P[b]<=x) {
      b--;
    }
    cnt += b-a;
    a++;
  }
  a = 0; b = m-1;
  while (a<b) {
    while (a<b && M[a]*M[b]<=x) {
      b--;
    }
    cnt += b-a;
    a++;
  }
  return cnt<=p*(p-1)/2+m*(m-1)/2-K;
}


int main() {
  cin >> N >> K;
  rep(i,N) {
    ll a;
    cin >> a;
    if (a>0) {
      P.push_back(a);
      p++;
    } else if (a==0) {
      z++;
    } else {
      M.push_back(a);
      m++;
    }
  }
  sort(all(M)); rsort(P);
  if (p*m>=K) {
    ll l = -1e18-1, u = -1;
    while (u-l>1) {
      ll mid = (l+u)/2;
      if (jugde_m(mid)) {
        u = mid;
      } else {
        l = mid;
      }
    }
    print(u);
  } else if (z*(z-1)/2+p*m+m*z+z*p>=K) {
    print(0);
  } else {
    K -= z*(z-1)/2+p*m+m*z+z*p;
    ll l = 0, u = 1e18;
    while (u-l>1) {
      ll mid = (l+u)/2;
      if (jugde_p(mid)) {
        u = mid;
      } else {
        l = mid;
      }
    }
    print(u);
  }
  return 0;
}
