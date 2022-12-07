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
  string S;
  cin >> S;
  ll res = 0;
  rep(i,10000) {
    vec<int> cnt(10,0);
    int tmp = i;
    bool flag = true;
    rep(_,4) {
      cnt[tmp%10]++;
      tmp /= 10;
    }
    rep(i,10) {
      if ((S[i]=='x' && cnt[i]>0) || (S[i]=='o' && cnt[i]==0))
        flag = false;
    }
    res += flag;
  }
  print(res);
  return 0;
}
