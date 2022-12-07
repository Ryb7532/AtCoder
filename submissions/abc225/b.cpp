#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  cin >> N;
  vec<int> edge(N,0);
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    edge[--a]++;
    edge[--b]++;
  }
  int M = 0;
  rep(i,N) {
    M = max(M, edge[i]);
  }
  print((M==N-1 ? Yes : No));
  return 0;
}
