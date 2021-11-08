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


int main() {
  int N;
  cin >> N;
  vec<ll> T(N);
  vec<vec<int>> A(N);
  rep(i,N) {
    int K;
    cin >> T[i] >> K;
    vec<int> a(K);
    rep(j,K) {
      cin >> a[j];
      a[j]--;
    }
    A[i] = a;
  }
  ll res = 0;
  set<int> require;
  queue<int> q;
  q.push(N-1);
  require.insert(N-1);
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for (int e: A[top]) {
      if (require.find(e) != require.end())
        continue;
      require.insert(e);
      q.push(e);
    }
  }
  while(!require.empty()) {
    int top = *(require.begin());
    require.erase(top);
    res += T[top];
  }
  print(res);
  return 0;
}
