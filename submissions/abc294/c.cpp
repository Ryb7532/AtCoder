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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<pair<int,int>> C(N+M);
  rep(i,N) {
    int A;
    cin >> A;
    C[i] = {A,i};
  }
  rep(j,M) {
    int B;
    cin >> B;
    C[N+j] = {B,N+j};
  }
  sort(all(C));
  vector<int> res(N+M);
  rep(i,N+M) {
    int id = C[i].second;
    res[id] = i+1;
  }
  rep(i,N+M) {
    cout << res[i] << " ";
    if (i == N-1)
      cout << endl;
  }
  cout << endl;
  return 0;
}
