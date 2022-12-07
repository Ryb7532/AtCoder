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


const int maxN = 1e5;
int N;
vector<int> X(maxN);
vector<vector<int>> Edge(maxN);
vector<vector<int>> top(maxN, vector<int>(20,-1));


void dfs(int n, int p) {
  int cnt = 1;
  multiset<int> n_top;
  n_top.insert(X[n]);
  for (int e: Edge[n]) {
    if (e == p)
      continue;
    dfs(e, n);
    for (int v: top[e]) {
      if (cnt<20) {
        n_top.insert(v);
        cnt++;
      } else if (*(n_top.begin()) < v) {
        n_top.erase(n_top.begin());
        n_top.insert(v);
      }
    }
  }
  for (int v: n_top) {
    top[n][--cnt] = v;
  }
}

int main() {
  int Q;
  cin >> N >> Q;
  rep(i,N) {
    cin >> X[i];
  }
  rep(i,N-1) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    Edge[A].push_back(B);
    Edge[B].push_back(A);
  }
  dfs(0, -1);
  rep(_,Q) {
    int V,K;
    cin >> V >> K;
    print(top[--V][--K]);
  }
  return 0;
}
