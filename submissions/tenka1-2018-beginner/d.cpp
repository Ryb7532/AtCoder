#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  int k = 2;
  ll kc2 = 1;
  while (kc2 < N) {
    kc2 += k;
    k++;
  }
  printyesno(kc2==N);
  if (kc2 == N) {
    print(k);
    vector<vector<int>> res(k);
    int l = 0, r = 1;
    while (N > 0) {
      res[l].push_back(N);
      res[r].push_back(N);
      r++;
      if (r == k)
        l++, r = l+1;
      N--;
    }
    rep(i,k) {
      cout << res[i].size();
      for (int j: res[i])
        cout << " " << j;
      cout << endl;
    }
  }
  return 0;
}
