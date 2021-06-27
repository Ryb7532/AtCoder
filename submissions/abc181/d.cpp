#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
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
  int n = S.length();
  vec<int> cnt(10,0);
  rep(i,n)
    cnt[S[i]-'0']++;
  int ul=1;
  n = min(3,n);
  rep(i,n)
    ul*=10;
  for (int i=0; i<ul; i+=8) {
    vec<int> d(n);
    int tmp = i;
    bool is = true;
    rep(j,n) {
      d[j]=tmp%10;
      tmp/=10;
      cnt[d[j]]--;
      if (cnt[d[j]]<0)
        is = false;
    }
    if (is) {
      print(Yes);
      return 0;
    }
    rep(j,n)
      cnt[d[j]]++;
  }
  print(No);
  return 0;
}
