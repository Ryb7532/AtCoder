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
  vec<pair<int,int>> P(N);
  rep(i,N) {
    int p;
    cin >> p;
    P[i] = {p, i+1};
  }
  sort(all(P));
  cout << P[0].second;
  rep(i,N-1) {
    cout << ' ' << P[i+1].second;
  }
  cout << endl;
  return 0;
}
