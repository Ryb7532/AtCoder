#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
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
  string X;
  cin >> X;
  int N = X.size();
  vector<int> Xnum(N);
  vector<ll> sum(N,0);
  rep(i,N) {
    Xnum[i] = X[i]-'0';
  }
  sum[0] = Xnum[0];
  rep(i,N-1) {
    sum[i+1] = sum[i]+Xnum[i+1];
  }
  string res;
  for (int i=N-1; i>0; i--) {
    res.push_back(sum[i]%10 + '0');
    sum[i-1] += sum[i]/10;
  }
  reverse(all(res));
  print(sum[0] << res);
  return 0;
}
