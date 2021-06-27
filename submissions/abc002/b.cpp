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
  string W;
  cin >> W;
  int n = W.size();
  rep(i, n) {
    if (W[i] == 'a' || W[i] == 'i' || W[i] == 'u' || W[i] == 'e' || W[i] == 'o')
      continue;
    cout << W[i];
  }
  cout << endl;
  return 0;
}
