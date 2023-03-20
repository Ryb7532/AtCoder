#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  vector<int> R(7, 0);
  vector<int> P2R = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
  rep(i,10) {
    if (S[i] == '1') {
      R[P2R[i]]++;
    }
  }
  if (S[0] == '1') {
    print(No);
    return 0;
  }
  vector<int> hasP;
  rep(i,7) {
    if (R[i])
      hasP.push_back(i);
  }
  if (hasP.size() == 0 || hasP.size() == hasP.back() - hasP.front() + 1)
    print(No);
  else
    print(Yes);
  return 0;
}
