#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<ll> Ap, Am;
  ll A, res = 0;
  rep(i,N) {
    cin >> A;
    if (A<0)
      Am.push_back(A);
    else
      Ap.push_back(A);
  }
  sort(all(Am));
  sort(all(Ap));
  int np=Ap.size(), nm=Am.size();
  for (int i=0; i<np; i++) {
    res += i*Ap[i];
    res -= (np-1-i)*Ap[i];
    res += nm*Ap[i];
  }
  for (int i=0; i<nm; i++) {
    res += i*Am[i];
    res -= (nm-1-i)*Am[i];
    res -= np*Am[i];
  }
  print(res);
  return 0;
}
