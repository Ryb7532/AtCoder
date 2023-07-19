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
  int N,M,K;
  cin >> N >> M >> K;
  vector<vector<int>> E(N);
  rep(i,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> maxH(N,-1);
  using pii = pair<int,int>;
  priority_queue<pii> q;
  rep(_,K) {
    int p,h;
    cin >> p >> h;
    p--;
    maxH[p] = h;
    q.push({h,p});
  }
  while (!q.empty()) {
    auto [h,n] = q.top();
    q.pop();
    if (maxH[n] > h)
      continue;
    if (h == 0)
      continue;
    for (int e: E[n]) {
      if (maxH[e] >= h-1)
        continue;
      maxH[e] = h-1;
      q.push({h-1,e});
    }
  }
  vector<int> res;
  rep(i,N) {
    if (maxH[i] >= 0)
      res.push_back(i+1);
  }
  print((int)res.size());
  for (int n: res) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
