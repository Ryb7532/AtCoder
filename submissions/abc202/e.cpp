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

vec<vec<int>> E(200000);
int step = 0;
vec<pair<int,int>> S(200000);
vec<int> D(200000);

void dfs(int n, int d) {
  D[n] = d;
  S[n].first = step++;
  for (int e: E[n]) {
    dfs(e,d+1);
  }
  S[n].second = step++;
  return;
}

int main() {
  int N,Q;
  cin >> N;
  rep(i,N-1) {
    int P;
    cin >> P;
    P--;
    E[P].push_back(i+1);
  }
  dfs(0,0);
  vec<vec<pair<int,int>>> D2S(N);
  rep(i,N) {
    D2S[D[i]].push_back(S[i]);
  }
  rep(i,N) {
    sort(all(D2S[i]));
  }
  cin >> Q;
  rep(_,Q) {
    int u,d;
    cin >> u >> d;
    u--;
    pair<int,int> in,out;
    in = {S[u].first,S[u].first};
    out = {S[u].second,S[u].second};
    auto it0 = lower_bound(all(D2S[d]),in);
    auto it1 = lower_bound(all(D2S[d]), out);
    print(it1-it0);
  }
  return 0;
}
