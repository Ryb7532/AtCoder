#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,K;
  string S;
  cin >> N >> K >> S;
  vec<int> cnt(26,0);
  rep(i,N) {
    cnt[S[i]-'a']++;
  }
  string res;
  rep(i,N) {
    rep(j,26) {
      if (cnt[j]==0)
        continue;
      cnt[j]--;
      K -= S[i] != 'a'+j;
      vec<int> c(26);
      int num = K;
      rep(k,26)
        c[k] = cnt[k];
      for (int k=i+1; k<N; k++) {
        if (c[S[k]-'a']==0)
          num--;
        else
          c[S[k]-'a']--;
      }
      if (num<0) {
        cnt[j]++;
        K += S[i] != 'a'+j;
      } else {
        res += 'a'+j;
        break;
      }
    }
  }
  print(res);
  return 0;
}
