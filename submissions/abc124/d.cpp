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
  int N,K;
  string S;
  cin >> N >> K >> S;
  vector<pair<int,int>> zeros;
  int i=0, j, res;
  while (i<N) {
    while (i<N && S[i]=='1') {
      i++;
    }
    j=i;
    while (j<N && S[j]=='0') {
      j++;
    }
    zeros.push_back({i,j});
    i = j;
  }
  zeros.push_back({N,N});
  int z = zeros.size();
  i=0;
  j=min(z-1, K);
  res = zeros[j].first;
  while (++j<z) {
    res = max(res, zeros[j].first-zeros[i].second);
    i++;
  }
  print(res);
  return 0;
}
