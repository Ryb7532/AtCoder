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
  int N,M;
  cin >> N >> M;
  vector<int> ones(N,0);
  ll odd = 0;
  rep(i,N) {
    string S;
    cin >> S;
    rep(j,M) {
      ones[i] += (S[j]=='1');
    }
    odd += (ones[i]%2);
  }
  print(odd*(N-odd));
  return 0;
}
