#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


const int MN = 2e5; //size
const ll INF = 1e9;

int N;
vector<ll> A(MN);
vector<ll> dp(MN,INF);
vector<int> ans(MN);
int res;

void LIS() {
  rep(i,N) {
    auto it = lower_bound(all(dp),A[i]);
    if (*it == INF)
      res++;
    ans[i] = res;
    *it = A[i];
  }
  return ;
}


int main() {
  int M;
  cin >> M >> N;
  vector<pair<int,int>> L(N);
  rep(i,N) {
    int a,b;
    cin >> a >> b;
    L[i] = {a,-b};
  }
  sort(all(L));
  rep(i,N) {
    A[i] = -L[i].second;
  }
  LIS();
  print(res);
  return 0;
}
