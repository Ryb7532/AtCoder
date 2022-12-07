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
  ll N,K;
  cin >> N >> K;
  vec<pair<ll,ll>> F(N);
  rep(i,N) {
    cin >> F[i].first >> F[i].second;
  }
  sort(all(F));
  int i=0;
  while (i<N && F[i].first<=K) {
    K += F[i].second;
    i++;
  }
  print(K);
  return 0;
}
