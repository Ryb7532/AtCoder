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
  ld K;
  string S,T;
  cin >> K >> S >> T;
  vec<int> cnt(9,0), cntS(9,0), cntT(9,0);
  rep(i,4) {
    int s,t;
    s = S[i]-'1';
    t = T[i]-'1';
    cnt[s]++; cnt[t]++;
    cntS[s]++; cntT[t]++;
  }
  ld res = 0;
  rep(s_last,9) {
    if (cnt[s_last] == K)
      continue;
    ll ps = 0;
    cnt[s_last]++;
    cntS[s_last]++;
    rep(n,9) {
      ll tmp = n+1;
      rep(_,cntS[n])
        tmp *= 10;
      ps += tmp;
    }
    rep(t_last,9) {
      if (cnt[t_last] == K)
        continue;
      ll pt = 0;
      cntT[t_last]++;
      rep(n,9) {
        ll tmp = n+1;
        rep(_,cntT[n])
          tmp *= 10;
        pt += tmp;
      }
      if (ps>pt)
        res += (K-cnt[s_last]+1)/(9*K-8) * (K-cnt[t_last])/(9*K-9);
      cntT[t_last]--;
    }
    cntS[s_last]--;
    cnt[s_last]--;
  }
  print(fix(10) << res);
  return 0;
}
