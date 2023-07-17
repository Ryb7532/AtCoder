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


// Union Find Tree
struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n, -1) {}

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
  int N,Q;
  cin >> N >> Q;
  UnionFind uft(N+Q+1);
  vector<int> box(N+Q+1);
  vector<int> represent(N+1, 0);
  int total = N;
  rep(i,N) {
    box[i+1] = i+1;
    represent[i+1] = i+1;
  }
  rep(_,Q) {
    int t,X;
    cin >> t >> X;
    if (t == 1) {
      int Y;
      cin >> Y;
      int rx = represent[X], ry = represent[Y];
      int root;
      if (rx != 0 && ry != 0)
        uft.unite(rx,ry);
      if (rx != 0)
        root = uft.root(rx);
      else if (ry != 0)
        root = uft.root(ry);
      else
        continue;
      represent[X] = root;
      represent[Y] = 0;
      box[root] = X;
    } else if (t == 2) {
      total++;
      if (represent[X] == 0) {
        represent[X] = total;
        box[total] = X;
      } else {
        int rx = represent[X];
        uft.unite(rx, total);
        int root = uft.root(rx);
        represent[X] = root;
        box[root] = X;
      }
    } else {
      int root = uft.root(X);
      print(box[root]);
    }
  }
  return 0;
}
