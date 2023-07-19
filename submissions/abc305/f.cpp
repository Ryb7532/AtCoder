#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N,M;
  cin >> N >> M;
  vector<bool> visited(N+1, false);
  visited[1] = true;
  vector<int> path;
  int n = 1;
  while (true) {
    int k;
    cin >> k;
    if (k == -1)
      return 0;
    int next = n;
    rep(_,k) {
      int v;
      cin >> v;
      if (!visited[v])
        next = v;
    }
    if (next == N) {
      print(N);
      break;
    }
    if (next != n) {
      path.push_back(n);
      n = next;
      visited[n] = true;
      print(n);
    } else {
      n = path.back();
      path.pop_back();
      print(n);
    }
  }
  string s;
  cin >> s;
  return 0;
}
