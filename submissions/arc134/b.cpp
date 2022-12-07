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
  int N;
  string S;
  cin >> N >> S;
  vector<int> cnt(26,0);
  rep(i,N) {
    cnt[S[i]-'a']++;
  }
  int l=0, r=N-1;
  while (l<r) {
    int min_c = -1;
    rep(i,26) {
      if (cnt[i]>0) {
        min_c = i;
        break;
      }
    }
    if (min_c < S[l]-'a') {
      while (r>l && S[r]-'a'!=min_c) {
        cnt[S[r--]-'a']--;
      }
      swap(S[l], S[r]);
      cnt[S[r--]-'a']--;
    }
    cnt[S[l++]-'a']--;
  }
  print(S);
  return 0;
}
