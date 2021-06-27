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
  int N = S.size(), m = 0;
  rep(i,N) {
    if (m == 0) {
      if (S[i] == 'i' || S[i] == 'I')
        m++;
    } else if (m == 1) {
      if (S[i] == 'c' || S[i] == 'C')
        m++;
    } else if (m == 2) {
      if (S[i] == 't' || S[i] == 'T')
        m++;
    }
  }
  if (m == 3)
    print("YES");
  else
    print("NO");
  return 0;
}
