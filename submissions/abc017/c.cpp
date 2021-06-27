#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, M, l, r, s;
  cin >> N >> M;
  ll sum = 0, v[M+1], m = 1e9;
  fill(v, v+M+1, 0);
  rep(i,N) {
    cin >> l >> r >> s;
    l--;
    sum += s;
    v[l] += s;
    v[r] -= s;
  }
  rep1(j,M) {
    v[j] += v[j-1];
    m = min(m, v[j-1]);
  }
  print(sum-m);
  return 0;
}
