#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n) { par.assign(n, -1); }

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
    if (par[a]>par[b])
      swap(a, b);
    par[ra] += par[rb];
    par[rb] = ra;
    return;
  }
  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
};
UnionFind uft(26);



int main() {
  int N;
  string s1, s2;
  cin >> N >> s1 >> s2;
  rep(i,N) {
    int c1,c2;
    c1 = s1[i]-'A';
    c2 = s2[i]-'A';
    if (c1 != c2) {
      if (c1>=0 && c1<26 && c2>=0 && c2<26) {
        uft.unite(c1,c2);
      }
    }
  }
  vector<int> p(26,11);
  rep(i,N) {
    int c1,c2,n1,n2;
    c1 = s1[i]-'A';
    c2 = s2[i]-'A';
    n1 = s1[i]-'0';
    n2 = s2[i]-'0';
    if (c1>=0 && c1<26) {
      if (n2>=0 && n2<10) {
        p[uft.root(c1)] = 1;
      } else {
        p[uft.root(c1)] = min(p[uft.root(c1)], (i!=0)?10:9);
      }
    } else if (c2>=0 && c2<26) {
      if (n1>=0 && n1<10) {
        p[uft.root(c2)] = 1;
      }
    }
  }
  ll ans = 1;
  rep(i,26) {
    if (p[i]<11)
      ans *= p[i];
  }
  print(ans);
  return 0;
}
