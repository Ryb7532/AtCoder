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
  ll A, res = 0;
  map<int,int> cnt;
  rep(i,N) {
    cin >> A;
    cnt[A%200]++;
  }
  for (auto &e: cnt) {
    ll a = e.second;
    res += a*(a-1)/2;
  }
  print(res);
  return 0;
}
