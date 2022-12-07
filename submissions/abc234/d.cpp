#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,K;
  cin >> N >> K;
  vector<int> P(N);
  set<int> used;
  rep(i,N) {
    cin >> P[i];
  }
  int mk = N;
  rep(i,K) {
    mk = min(mk, P[i]);
    used.insert(P[i]);
  }
  print(mk);
  for (int i=K; i<N; i++) {
    if (P[i]>mk) {
      used.insert(P[i]);
      used.erase(mk);
      mk = *(used.begin());
    }
    print(mk);
  }
  return 0;
}
