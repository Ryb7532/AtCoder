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
  string S, ans;
  cin >> S;
  int A[4], n = S.size(), a = 0;
  rep(i,4) {
    cin >> A[i];
  }
  rep(i,n) {
    if (a<4 && A[a] == i) {
      ans.push_back('"');
      a++;
    }
    ans.push_back(S[i]);
  }
  while (a != 4) {
    ans.push_back('"');
    a++;
  }
  print(ans);
  return 0;
}
