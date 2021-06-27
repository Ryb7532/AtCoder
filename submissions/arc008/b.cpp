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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int N,M;
  cin >> N >> M;
  string name,kit;
  cin >> name >> kit;
  vec<int> ncnt(26,0),kcnt(26,0);
  rep(i,N) {
    ncnt[name[i]-'A']++;
  }
  rep(i,M) {
    kcnt[kit[i]-'A']++;
  }
  int ans = 0;
  rep(i,26) {
    if (kcnt[i] == 0) {
      if (ncnt[i] > 0) {
        print(-1);
        return 0;
      } else {
        continue;
      }
    }
    ans = max(ans,(ncnt[i]-1+kcnt[i])/kcnt[i]);
  }
  print(ans);
  return 0;
}
