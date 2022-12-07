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


int main() {
  int N;
  cin >> N;
  vector<pair<ll,int>> X(N),Y(N);
  rep(i,N) {
    ll x,y;
    cin >> x >> y;
    X[i] = {x,i};
    Y[i] = {y,i};
  }
  sort(all(X));
  sort(all(Y));
  vector<pair<ll,pair<int,int>>> candidate;
  vector<pair<int,int>> ids = {{0,N-1}, {0,N-2}, {1,N-1}};
  rep(i,3) {
    auto X1 = X[ids[i].first], X2 = X[ids[i].second];
    int id1, id2;
    ll d = X2.first - X1.first;
    id1 = X1.second;
    id2 = X2.second;
    if (id1 > id2) {
      swap(id1,id2);
    }
    candidate.push_back({d, {id1,id2}});
    auto Y1 = Y[ids[i].first], Y2 = Y[ids[i].second];
    d = Y2.first - Y1.first;
    id1 = Y1.second;
    id2 = Y2.second;
    if (id1 > id2) {
      swap(id1,id2);
    }
    candidate.push_back({d, {id1,id2}});
  }
  sort(rall(candidate));
  auto maxpair = candidate[0].second;
  rep(i,6) {
    if (candidate[i].second == maxpair)
      continue;
    print(candidate[i].first);
    break;
  }
  return 0;
}
