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
  string S;
  cin >> S;
  int N = S.size();
  int cnt = 0;
  ll ans = 0;
  rep(i,N) {
  if (S[i] != S[N-1-i])
      cnt++;
  }
  cnt /= 2;
  if (cnt == 0) {
    ans = 25*N - (N%2?25:0);
  } else if (cnt == 1) {
    rep(i,N) {
      if (S[i] == S[N-1-i])
        ans += 25;
      else
        ans += 24;
    }
  } else {
    ans = 25*N;
  }
  print(ans);
  return 0;
}
