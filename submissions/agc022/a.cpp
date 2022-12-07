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
  int N = S.size();
  vector<int> T(N);
  vector<bool> used(26, false);
  string res;
  rep(i,N) {
    T[i] = S[i]-'a';
    used[T[i]] = true;
  }
  if (N == 26) {
    for (int i=N-1; i>=0; i--) {
      int j;
      for (j=T[i]+1; j<26; j++) {
        if (!used[j])
          break;
      }
      if (j<26) {
        res = S.substr(0,i);
        res.push_back('a'+j);
        break;
      }
      used[T[i]] = false;
    }
  } else {
    res = S;
    rep(i,26) {
      if (!used[i]) {
        res.push_back('a'+i);
        break;
      }
    }
  }
  if (res.empty()) {
    print(-1);
  } else {
    print(res);
  }
  return 0;
}
