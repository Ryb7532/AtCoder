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
  vector<pair<int,int>> A(N);
  rep(i,N) {
    cin >> A[i].first >> A[i].second;
  }
  sort(all(A));
  vector<int> res(M+5, 0);
  int l = 1, r = A[N-1].first;
  int minr = M;
  int id = 0;
  while (l <= minr) {
    res[r-l+1]++;
    res[M-l+2]--;
    while (id < N && A[id].first == l) {
      minr = min(minr, A[id].second);
      r = max(r, A[id].second);
      id++;
    }
    l++;
  }
  rep(i,M) {
    res[i+1] += res[i];
    cout << res[i+1] << ' ';
  }
  cout << endl;
  return 0;
}
