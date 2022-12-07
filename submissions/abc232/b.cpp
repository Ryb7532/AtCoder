#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  string S,T;
  cin >> S >> T;
  int N = S.size();
  vector<int> s(N), t(N);
  rep(i,N) {
    t[i] = T[i]-'a';
    s[i] = S[i]-'a';
  }
  int k = t[0]-s[0];
  k += 26;
  rep(i,N) {
    if (t[i] != (s[i]+k)%26) {
      print(No);
      return 0;
    }
  }
  print(Yes);
  return 0;
}
