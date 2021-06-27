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
  int N;
  cin >> N;
  vector<ll> A;
  ll a;
  rep(i, N) {
    cin >> a;
    A.push_back(a);
  }
  sort(all(A));
  reverse(all(A));
  ll ans = 0;
  rep1(i, N-1) {
    ans += A[i/2];
  }
  print(ans);
  return 0;
}
