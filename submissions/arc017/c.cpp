#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int n[2];
vector<ll> W(32);
map<ll,int> dp[2];

void dfs(int id, int a, ll w) {
  if (a>=n[id]) {
    dp[id][w]++;
    return ;
  }
  dfs(id,a+1,w);
  dfs(id,a+1,w+W[a]);
  return ;
}

int main() {
  int N;
  ll X;
  cin >> N >> X;
  n[1] = N;
  n[0] = N/2;
  rep(i,N) cin >> W[i];
  dfs(0,0,0);
  dfs(1,n[0],0);
  int ans = 0;
  for (auto &e : dp[0]) {
    ans += e.second*dp[1][X-e.first];
  }
  print(ans);
  return 0;
}
