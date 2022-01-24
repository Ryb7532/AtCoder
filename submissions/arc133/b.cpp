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


const int MN = 4e6; //size
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
  cin >> M;
  vector<int> id_P(M),id_Q(M);
  rep(i,M) {
    int P;
    cin >> P;
    id_P[--P] = i;
  }
  rep(i,M) {
    int Q;
    cin >> Q;
    id_Q[--Q] = i;
  }
  vector<pair<int,int>> B;
  rep(i,M) {
    for (int j=i; j<M; j+=i+1) {
      B.push_back({id_P[i], -id_Q[j]});
    }
  }
  sort(all(B));
  N = B.size();
  rep(i,N) {
    A[i] = -B[i].second;
  }
  LIS();
  print(res);
  return 0;
}
