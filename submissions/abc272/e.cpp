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
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vector<vector<int>> B(M,vector<int>());
  rep(i,N) {
    int m = 1;
    if (A[i]<0) {
      m = (-A[i]+i)/(i+1);
    }
    while (m <= M && A[i]+m*(i+1) <= N) {
      B[m-1].push_back(A[i]+m*(i+1));
      m++;
    }
  }
  rep(i,M) {
    int size = B[i].size();
    vector<bool> f(size, false);
    for (int e: B[i]) {
      if (e < size)
        f[e] = true;
    }
    int res = 0;
    while (res < size && f[res]) {
      res++;
    }
    print(res);
  }
  return 0;
}
