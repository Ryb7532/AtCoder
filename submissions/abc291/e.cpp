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
  int N,M;
  cin >> N >> M;
  vector<set<int>> Edge(N);
  rep(i,M) {
    int X,Y;
    cin >> X >> Y;
    X--; Y--;
    Edge[X].insert(Y);
  }
  vector<int> ind(N, 0);
  rep(i,N) {
    for (int j: Edge[i]) {
      ind[j]++;
    }
  }
  queue<int> zeroin;
  rep(i,N) {
    if (ind[i] == 0)
      zeroin.push(i);
  }
  bool flag = true;
  vector<int> order;
  while (!zeroin.empty()) {
    if (zeroin.size()>1)
      flag = false;
    int n = zeroin.front();
    order.push_back(n);
    zeroin.pop();
    for (int d: Edge[n]) {
      ind[d]--;
      if (ind[d] == 0)
        zeroin.push(d);
    }
  }
  if (flag && order.size() == N) {
    printyesno(true);
    vector<int> res(N);
    rep(i,N) {
      res[order[i]] = i+1;
    }
    rep(i,N) {
      cout << res[i] << " ";
    }
    cout << endl;
  } else
    printyesno(false);
  return 0;
}
