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
  int L;
  cin >> L;
  vi B(L);
  int x = 0;
  rep(i,L) {
    cin >> B[i];
    x = x^B[i];
  }
  if (x) {
    print(-1);
    return 0;
  }
  vi A(L);
  A[0] = 0;
  rep1(i,L-1) {
    A[i] = B[i-1]^A[i-1];
  }
  rep(i,L) {
    print(A[i]);
  }
  return 0;
}
