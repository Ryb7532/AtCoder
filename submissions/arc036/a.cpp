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
  int N,K;
  cin >> N >> K;
  vector<int> t(N);
  rep(i,N) {
    cin >> t[i];
  }
  int ans = -1;
  reps(i,2,N) {
    if (t[i]+t[i-1]+t[i-2]<K) {
      ans = i+1;
      break;
    }
  }
  print(ans);
  return 0;
}
