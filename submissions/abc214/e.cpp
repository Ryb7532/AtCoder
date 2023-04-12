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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int T;
  cin >> T;
  rep(_,T) {
    int N;
    cin >> N;
    vector<pair<ll,ll>> I(N);
    rep(i,N) {
      cin >> I[i].first >> I[i].second;
    }
    sort(all(I));
    int id = 0;
    int l;
    multiset<ll> R;
    bool flag = true;
    while (id < N || !R.empty()) {
      if (R.empty()) {
        l = I[id].first;
      }
      while (id < N && I[id].first <= l) {
        R.insert(I[id].second);
        id++;
      }
      auto top = R.begin();
      if (*top < l) {
        flag = false;
      }
      R.erase(top);
      l++;
    }
    printyesno(flag);
  }
  return 0;
}
