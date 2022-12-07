#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
vector<int> edge[100];
vector<bool> H(100);
int cnt;

bool dfs(int a, int p) {
  bool res = H[a];
  for (auto &e: edge[a]) {
    if (e == p)
      continue;
    if (dfs(e,a)) {
      res = true;
      cnt++;
    }
  }
  return res;
}


int main() {
  int N,X;
  cin >> N >> X;
  X--;
  rep(i,N) {
    int h;
    cin >> h;
    H[i] = h;
  }
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(X,-1);
  print(2*cnt);
  return 0;
}
