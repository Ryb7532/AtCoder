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
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  map<string,int> cnt;
  rep(i,N) {
    if (cnt.find(S[i]) == cnt.end()) {
      print(S[i]);
      cnt[S[i]] = 0;
    } else {
      print(S[i] << "(" << cnt[S[i]] << ")");
    }
    cnt[S[i]]++;
  }
  return 0;
}
