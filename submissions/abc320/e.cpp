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
  int N,M;
  cin >> N >> M;
  vector<ll> T(M);
  vector<int> W(M), S(M);
  rep(i,M) {
    cin >> T[i] >> W[i] >> S[i];
  }
  vector<ll> res(N, 0);
  set<int> R;
  using pli = pair<ll,int>;
  priority_queue<pli, vector<pli>, greater<pli>> return_time;
  rep(i,N) {
    R.insert(i);
  }
  rep(i,M) {
    while (!return_time.empty()) {
      if (return_time.top().first > T[i])
        break;
      auto [_, id] = return_time.top();
      return_time.pop();
      R.insert(id);
    }
    if (R.empty())
      continue;
    int id = *R.begin();
    R.erase(id);
    res[id] += W[i];
    return_time.push({T[i]+S[i], id});
  }
  rep(i,N) {
    print(res[i]);
  }
  return 0;
}