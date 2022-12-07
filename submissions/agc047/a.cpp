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
  vector<pair<int,int>> A(N);
  ll res = 0;
  rep(i,N) {
    string S;
    cin >> S;
    int L = S.size();
    ll a = 0;
    int j=0;
    while (j<L && S[j]!='.') {
      a *= 10;
      a += S[j]-'0';
      j++;
    }
    int p=1;
    while (p<=9) {
      a *= 10;
      if (j+p<L) {
        a += S[j+p]-'0';
      }
      p++;
    }
    int cnt = 0;
    while (a%2 == 0) {
      cnt++;
      a /= 2;
    }
    A[i].first = cnt;
    cnt = 0;
    while (a%5 == 0) {
      cnt++;
      a /= 5;
    }
    A[i].second = cnt;
  }
  vector<vector<int>> dp(19, vector<int>(19,0));
  rep(i,N) {
    int two = A[i].first, five = A[i].second;
    two = min(two, 18);
    five = min(five, 18);
    for (int j=18-two; j<19; j++) {
      res += dp[j][18-five];
    }
    rep(j,five+1) {
      dp[two][j]++;
    }
  }
  print(res);
  return 0;
}
