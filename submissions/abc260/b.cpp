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
  int N;
  vector<int> X(3);
  cin >> N;
  rep(i,3) {
    cin >> X[i];
  }
  vector<vector<pair<int,int>>> A(3, vector<pair<int,int>>(N));
  vector<bool> pass(N, false);
  rep(j,2) {
    rep(i,N) {
      int a;
      cin >> a;
      A[j][i] = {-a,i};
    }
  }
  rep(i,N) {
    A[2][i] = {A[0][i].first+A[1][i].first, i};
  }
  rep(i,3) {
    sort(all(A[i]));
  }
  rep(i,3) {
    int j = 0;
    while (X[i] > 0) {
      int id = A[i][j].second;
      if (!pass[id]) {
        pass[id] = true;
        X[i]--;
      }
      j++;
    }
  }
  rep(i,N) {
    if (pass[i])
      print(i+1);
  }
  return 0;
}
