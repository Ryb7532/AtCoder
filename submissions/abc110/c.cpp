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
  string S,T;
  cin >> S >> T;
  vector<int> mp(26,-1);
  vector<bool> used(26,false);
  int N = S.size();
  rep(i,N) {
    int s,t;
    s = S[i]-'a';
    t = T[i]-'a';
    if (mp[s]==t)
      continue;
    if (mp[s]==-1 && !used[t]) {
      mp[s] = t;
      used[t]=true;
    } else {
      print(No);
      return 0;
    }
  }
  print(Yes);
  return 0;
}
