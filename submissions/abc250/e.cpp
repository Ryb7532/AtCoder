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
  int N,Q;
  cin >> N;
  vector<int> A(N),B(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    cin >> B[i];
  }
  cin >> Q;
  set<int> subA,subB,Xor;
  vector<pair<int,int>> dp(N,{-1,-1});
  int j = -1, k = 0;
  rep(i,N) {
    int a = A[i];
    if (subA.find(a) == subA.end()) {
      subA.insert(a);
      if (Xor.find(a) != Xor.end())
        Xor.erase(a);
      if (subB.find(a) == subB.end()) {
        while (++j < N && B[j] != a) {
          int b = B[j];
          subB.insert(b);
          if (subA.find(b) == subA.end()) {
            Xor.insert(b);
          } else if (Xor.find(b) != Xor.end()) {
            Xor.erase(b);
          }
        }
        if (j != N) {
          subB.insert(a);
        }
      }
      if (j == N)
        break;
      if (Xor.empty()) {
        while (k < N) {
          if (subB.find(B[k]) == subB.end())
           break;
          k++;
        }
        dp[i] = {j, k};
      }
    } else {
      dp[i] = dp[i-1];
    }
  }
  rep(_,Q) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    print((dp[x].first<=y && dp[x].second>y ? Yes : No));
  }
  return 0;
}
