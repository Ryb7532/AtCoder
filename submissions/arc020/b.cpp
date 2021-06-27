#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N,C;
  cin >> N >> C;
  vi A(N);
  rep(i,N) cin >> A[i];
  int ans = 1e9;
  rep1(i,10) {
    rep1(j,10) {
      if (i == j)
        continue;
      int cost=0;
      rep(n,N) {
        if (n%2) {
          if (A[n] != i)
            cost += C;
        } else {
          if (A[n] != j)
            cost += C;
        }
      }
      ans = min(ans,cost);
    }
  }
  print(ans);
  return 0;
}
