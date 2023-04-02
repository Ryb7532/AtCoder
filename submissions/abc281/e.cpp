#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M,K;
  cin >> N >> M >> K;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  multiset<ll, greater<ll>> topk;
  multiset<ll> rest;
  ll sum = 0;
  rep(i,K) {
    topk.insert(A[i]);
    sum += A[i];
  }
  rep(i,M-K) {
    rest.insert(A[i+K]);
  }
  while (!rest.empty() && *rest.begin() < *topk.begin()) {
    ll rmin = *rest.begin();
    sum += rmin;
    ll tmax = *topk.begin();
    sum -= tmax;
    rest.insert(tmax);
    rest.erase(rest.find(rmin));
    topk.insert(rmin);
    topk.erase(topk.find(tmax));
  }
  cout << sum;
  rep(i,N-M) {
    if (topk.find(A[i]) != topk.end()) {
      topk.insert(A[i+M]);
      topk.erase(topk.find(A[i]));
      sum += A[i+M]-A[i];
    } else {
      rest.insert(A[i+M]);
      rest.erase(rest.find(A[i]));
    }
    while (!rest.empty() && *rest.begin() < *topk.begin()) {
      ll rmin = *rest.begin();
      sum += rmin;
      ll tmax = *topk.begin();
      sum -= tmax;
      rest.insert(tmax);
      rest.erase(rest.find(rmin));
      topk.insert(rmin);
      topk.erase(topk.find(tmax));
    }
    cout << " " << sum;
  }
  cout << endl;
  return 0;
}
