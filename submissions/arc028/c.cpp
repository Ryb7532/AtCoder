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
int N;
vector<int> edge[100000];
vector<vector<int>> dp(100000,vector<int>(2));

void dfs(int n,int p) {
  int sum=1,m=0;
  for (auto &e : edge[n]) {
    if (e == p)
      continue;
    dfs(e,n);
    sum += dp[e][1];
    m = max(m,dp[e][1]);
  }
  dp[n][0] = max(m,N-sum);
  dp[n][1] = sum;
  return ;
}

int main() {
  cin >> N;
  rep1(i,N-1) {
    int p;
    cin >> p;
    edge[i].push_back(p);
    edge[p].push_back(i);
  }
  dfs(0,-1);
  rep(i,N) {
    print(dp[i][0]);
  }
  return 0;
}
