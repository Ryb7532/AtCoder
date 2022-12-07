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

map<char,pair<int,int>> m = {{'A',{1,0}}, {'T',{-1,0}}, {'C',{0,1}}, {'G',{0,-1}}};

int main() {
  int N;
  string S;
  cin >> N >> S;
  vec<pair<int,int>> sum(N+1);
  sum[0] = {0,0};
  rep(i,N) {
    sum[i+1] = sum[i];
    sum[i+1].first += m[S[i]].first;
    sum[i+1].second += m[S[i]].second;
  }
  map<pair<int,int>,ll> cnt;
  rep(i,N+1) {
    cnt[sum[i]]++;
  }
  ll res = 0;
  for (auto &e: cnt) {
    if (e.second <= 1)
      continue;
    res += e.second*(e.second-1);
  }
  print(res/2);
  return 0;
}
