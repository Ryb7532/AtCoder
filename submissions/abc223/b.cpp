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
  string S;
  cin >> S;
  int n = S.size();
  vec<string> pattern;
  rep(i,n) {
    string T;
    T = S.substr(i);
    T += S.substr(0,i);
    pattern.push_back(T);
  }
  sort(all(pattern));
  print(pattern[0]);
  print(pattern[n-1]);
  return 0;
}
