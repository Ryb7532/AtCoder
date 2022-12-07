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
  int N, R;
  string S;
  cin >> N >> R >> S;
  int ans=0;
  repr(i,N,0) {
    if (S[i] == '.') {
      if (ans == 0) {
        ans += max(0,i-R+1);
      }
      ans++;
      i = max(0,i-R+1);
    }
  }
  print(ans);
  return 0;
}
