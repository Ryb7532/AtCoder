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
  int N,M;
  cin >> N >> M;
  vector<int> d(N,0);
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    d[--a]++;
    d[--b]++;
  }
  bool flag = true;
  rep(i,N) {
    if (d[i]%2 == 1)
      flag = false;
  }
  print((flag ? YES : NO));
  return 0;
}
