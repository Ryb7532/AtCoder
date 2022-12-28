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


int main() {
  int N, Q;
  cin >> N;
  int M = 0;
  map<int, pair<int, int>> id2lr;
  map<pair<int, int>, int> lr2id;
  for (int i=1; i<=N; i*=2) {
    for (int j=1; j+i<=N+1; j++) {
      M++;
      id2lr[M] = {j,i};
      lr2id[{j,i}] = M;
    }
  }
  print(M);
  rep(i,M) {
    int l = id2lr[i+1].first;
    int r = l + id2lr[i+1].second;
    print(l << " " << r-1);
  }
  cin >> Q;
  rep(_,Q) {
    int L,R;
    cin >> L >> R;
    R++;
    int length = 1;
    while (R-L >= length) length <<= 1;
    length >>= 1;
    int a,b;
    a = lr2id[{L,length}];
    b = lr2id[{R-length, length}];
    print(a << " " << b);
  }
  return 0;
}
