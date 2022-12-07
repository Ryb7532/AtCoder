#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S;
  cin >> S;
  int L = S.size();
  if (L == 1) {
    print(S);
    return 0;
  }
  bool nines = true;
  rep(i,L-1) {
    if (S[i+1]!='9')
      nines = false;
  }
  int res = (L-1)*9 + S[0]-'0';
  if (!nines) {
    res--;
  }
  print(res);
  return 0;
}
