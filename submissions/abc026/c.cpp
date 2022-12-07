#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();
int N;
ll pay[20];
vector<int> s[20];

void solve(int a) {
  if (s[a].empty()) {
    pay[a] = 1;
    return ;
  }
  ll M = 0, m = 1e9;
  for (auto &e: s[a]) {
    solve(e);
    M = max(M, pay[e]);
    m = min(m, pay[e]);
  }
  pay[a] = M+m+1;
  return ;
}

int main() {
  int b;
  cin >> N;
  rep1(i, N-1) {
    cin >> b;
    b--;
    s[b].push_back(i);
  }
  solve(0);
  print(pay[0]);
  return 0;
}
