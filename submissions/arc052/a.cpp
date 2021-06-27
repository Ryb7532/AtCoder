#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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
  int n = S.size(), ans = 0;
  rep(i,n)  {
    int s = S[i]-'0';
    if (s>=0 && s<=9) {
      ans *= 10;
      ans += s;
    }
  }
  print(ans);
  return 0;
}
