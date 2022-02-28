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


struct UnionFind {
  vector<int> par;
  vector<int> cap;
  UnionFind(int n) : par(n, -1), cap(n) {}

  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) { return -par[root(a)]; }
  void unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb)
      return;
    if (par[ra]>par[rb])
      swap(ra, rb);
    par[ra] += par[rb];
    cap[ra] += cap[rb];
    par[rb] = ra;
    return;
  }
  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
  int &operator[](const int i) { return par[i]; }
};


int main() {
  int N,M;
  cin >> N >> M;
  vector<int> D(N);
  ll sum = 0;
  rep(i,N) {
    cin >> D[i];
    sum += D[i];
  }
  bool flag = true;
  if (sum != 2*(N-1)) {
    flag = false;
  }
  vector<pair<int,int>> highway(M);
  UnionFind uft(N);
  rep(i,M) {
    int A,B;
    cin >> A >> B;
    D[--A]--;
    D[--B]--;
    highway[i] = {A,B};
  }
  rep(i,N) {
    uft.cap[i] = D[i];
    if (D[i]<0)
      flag = false;
  }
  rep(i,M) {
    int a = highway[i].first, b = highway[i].second;
    if (uft.same(a,b))
      flag = false;
    uft.unite(a,b);
  }

  vector<pair<int,int>> cap_and_root;
  map<int,int> root_to_idx;
  vector<set<int>> groups;
  int idx = 0;
  rep(i,N) {
    if (uft.root(i) != i)
      continue;
    cap_and_root.push_back({uft.cap[i], i});
    root_to_idx[i] = idx++;
    if (uft.cap[i] == 0)
      flag = false;
  }
  if (!flag) {
    print(-1);
    return 0;
  }
  groups.resize(idx);
  rep(i,N) {
    if (D[i] > 0)
      groups[root_to_idx[uft.root(i)]].insert(i);
  }
  sort(all(cap_and_root));
  int G = idx;
  int l=0, r=1;
  while (l < G-1) {
    while (r < G-1 && uft.cap[cap_and_root[r].second] == 1) {
      r++;
    }
    uft.cap[cap_and_root[l].second]--;
    uft.cap[cap_and_root[r].second]--;
    int s,t;
    s = *(groups[root_to_idx[cap_and_root[l].second]].begin());
    D[s]--;
    if (D[s]==0)
      groups[root_to_idx[cap_and_root[l].second]].erase(s);
    t = *(groups[root_to_idx[cap_and_root[r].second]].begin());
    D[t]--;
    if (D[t]==0)
      groups[root_to_idx[cap_and_root[r].second]].erase(t);
    print(s+1 << ' ' << t+1);
    l++;
  }
  return 0;
}
