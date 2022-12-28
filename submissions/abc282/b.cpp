#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
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
  vector<int> B(N);
  rep(i,N) {
    string S;
    cin >> S;
    rep(j,M) {
      if (S[j] == 'o')
        B[i] += 1<<j;
    }
  }
  int res = 0;
  rep(i,N) {
    rep(j,N-i-1) {
      if ((B[i] | B[j+i+1]) == ((1<<M)-1))
        res++;
    }
  }
  print(res);
  return 0;
}
