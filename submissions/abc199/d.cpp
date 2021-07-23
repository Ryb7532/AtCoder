#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

vec<vec<int>> E(20);
vec<int> color(20,-1);
vec<int> order(20);
ll p;

void dfs(int id,int last) {
  if (id == last) {
    p++;
    return;
  }
  id++;
  vec<int> cnt(3,0);
  for (int e: E[order[id]]) {
    if (color[e]==-1)
      continue;
    cnt[color[e]]++;
  }
  rep(i,3) {
    if (cnt[i]>0)
      continue;
    color[order[id]] = i;
    dfs(id,last);
    color[order[id]] = -1;
  }
  return;
}


int main() {
  int N,M;
  cin >> N >> M;
  rep(_,M) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  vec<bool> used(N,false);
  vec<pair<int,int>> SandE;
  int n=0;
  rep(i,N) {
    if (used[i])
      continue;
    queue<int> q;
    int start = n;
    order[n++] = i;
    used[i] = true;
    q.push(i);
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      for (int e: E[f]) {
        if (used[e])
          continue;
        order[n++] = e;
        used[e] = true;
        q.push(e);
      }
    }
    SandE.push_back({start,n-1});
  }
  ll res = 1;
  for (auto &e: SandE) {
    p = 0;
    color[order[e.first]] = 0;
    dfs(e.first, e.second);
    p *= 3;
    res *= p;
  }
  print(res);
  return 0;
}
