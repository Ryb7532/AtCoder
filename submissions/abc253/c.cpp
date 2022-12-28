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
  int Q;
  cin >> Q;
  map<int,int> S;
  rep(_,Q) {
    int k;
    cin >> k;
    if (k==1) {
      int x;
      cin >> x;
      S[x]++;
    } else if (k==2) {
      int x,c;
      cin >> x >> c;
      S[x] -= c;
      if (S[x] <= 0) {
        S.erase(S.find(x));
      }
    } else {
      int minS = S.begin()->first, maxS = (S.rbegin())->first;
      print(maxS-minS);
    }
  }
  return 0;
}
