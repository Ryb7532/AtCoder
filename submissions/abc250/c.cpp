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
  cin >> N >> Q;
  vector<int> Num(N), Pos(N);
  rep(i,N) {
    Num[i] = i;
    Pos[i] = i;
  }
  rep(_,Q) {
    int x;
    cin >> x;
    x--;
    if (Pos[x] == N-1) {
      swap(Num[Pos[x]], Num[Pos[x] - 1]);
    } else {
      swap(Num[Pos[x]], Num[Pos[x] + 1]);
    }
    swap(Pos[x], Pos[Num[Pos[x]]]);
  }
  rep(i,N-1) {
    cout << Num[i]+1 << " ";
  }
  cout << Num[N-1]+1 << endl;
  return 0;
}
