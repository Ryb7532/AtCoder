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
  string C;
  cin >> N >> C;
  vec<int> cnt(4,0);
  rep(i,N) {
    cnt[C[i]-'1']++;
  }
  int m=N, M=0;
  rep(i,4) {
    m = min(m,cnt[i]);
    M = max(M,cnt[i]);
  }
  print(M << ' ' << m);
  return 0;
}
