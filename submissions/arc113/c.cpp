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
  int N = S.size();
  vector<int> cnt(26, 0);
  cnt[S[N-1]-'a']++;
  ll res = 0;
  for (int i=1; i<N-1; i++) {
    int c = S[N-i-1]-'a';
    if (S[N-i-1] == S[N-i-2]) {
      res += i - cnt[c];
      rep(i,26) {
        cnt[i] = 0;
      }
      cnt[c] = i+1;
      i++;
    }
    cnt[c]++;
  }
  print(res);
  return 0;
}
