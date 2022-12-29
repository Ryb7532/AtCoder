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


int N;
const int M = 2e5+5;
vector<int> P(M), I(M);
map<int,int> Iid;
vector<int> L(M, 0), R(M, 0);
bool flag = true;
int n = 0;


void solve(int l, int r) {
  if (n == N) return ;
  int p = P[n];
  int i = Iid[p];
  if (i < l || r <= i) {
    flag = false;
    return ;
  }
  n++;
  if (n == N) return ;
  int np = P[n];
  int ni = Iid[np];
  if (r <= ni) return ;
  if (ni < i) {
    L[p] = np;
    solve(l, i);
  }
  if (n == N) return ;
  np = P[n];
  ni = Iid[np];
  if (r <= ni) return ;
  R[p] = np;
  solve(i+1, r);
}


int main() {
  cin >> N;
  rep(i,N) {
    cin >> P[i];
  }
  rep(i,N) {
    cin >> I[i];
    Iid[I[i]] = i;
  }
  if (P[0] != 1)
    flag = false;
  solve(0, N);
  if (!flag) {
    print(-1);
  } else {
    rep(i,N) {
      print(L[i+1] << " " << R[i+1]);
    }
  }
  return 0;
}
