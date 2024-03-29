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
  vector<vector<int>> bits(N, vector<int>());
  rep(i,N) {
    int A;
    cin >> A;
    A--;
    bits[A].push_back(i);
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    int L,R,X;
    cin >> L >> R >> X;
    L--; X--;
    auto itl = lower_bound(all(bits[X]), L);
    auto itr = lower_bound(all(bits[X]), R);
    print(itr-itl);
  }
  return 0;
}
