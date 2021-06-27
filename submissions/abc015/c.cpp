#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()
int N, K, T[5][5];
bool check = true;

void dfs(int n, int v) {
  if (n == N) {
    if (v == 0)
      check = false;
    return;
  }
  rep(i, K) {
    dfs(n+1, v^(T[n][i]));
  }
  return;
}

int main() {
  cin >> N >> K;
  rep(i, N) {
    rep(j, K) {
      cin >> T[i][j];
    }
  }
  dfs(0, 0);
  if (check) {
    print("Nothing");
  } else {
    print("Found");
  }
  return 0;
}
