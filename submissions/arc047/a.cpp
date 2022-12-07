#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, L;
  cin >> N >> L;
  string S;
  cin >> S;
  int ans = 0, b = 0;
  rep(i,N) {
    if (S[i] == '+')
      b++;
    else
      b--;
    if (b >= L) {
      b = 0;
      ans++;
    }
  }
  print(ans);
  return 0;
}
