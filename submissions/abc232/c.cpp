#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int N, M;
vector<vector<bool>> edge0(8, vector<bool>(8, false)), edge1(8, vector<bool>(8, false));
bool can = false;
vector<bool> used(8, false);
vector<int> P(8);

void dfs(int k) {
  if (k == N) {
    rep(i,N) {
      int pi = P[i];
      rep(j,N) {
        if (edge0[i][j] != edge1[pi][P[j]])
          return;
      }
    }
    can = true;
    return;
  }
  rep(i,N) {
    if (used[i])
      continue;
    P[k] = i;
    used[i] = true;
    dfs(k+1);
    used[i] = false;
  }
}

int main() {
  cin >> N >> M;
  rep(_,M) {
    int A,B;
    cin >> A >> B;
    A--;
    B--;
    edge0[A][B] = true;
    edge0[B][A] = true;
  }
  rep(_,M) {
    int A,B;
    cin >> A >> B;
    A--;
    B--;
    edge1[A][B] = true;
    edge1[B][A] = true;
  }
  dfs(0);
  print((can ? Yes : No));
  return 0;
}
