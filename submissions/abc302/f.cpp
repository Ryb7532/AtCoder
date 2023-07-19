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

const int INF = 1e9;

int main() {
  int N,M;
  cin >> N >> M;
  vector<set<int>> S(N), hasA(M);
  rep(i,N) {
    int A;
    cin >> A;
    rep(j,A) {
      int A;
      cin >> A;
      A--;
      S[i].insert(A);
      hasA[A].insert(i);
    }
  }
  vector<int> dist(N, INF);
  vector<bool> seenA(M,false);
  seenA[0] = true;
  queue<int> q;
  for (auto n: hasA[0]) {
    q.push(n);
    dist[n] = 0;
  }
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int s: S[n]) {
      if (seenA[s])
        continue;
      for (int e: hasA[s]) {
        if (dist[e] != INF)
          continue;
        q.push(e);
        dist[e] = dist[n]+1;
      }
      seenA[s] = true;
    }
  }
  int res = INF;
  for (int n: hasA[M-1]) {
    res = min(res, dist[n]);
  }
  if (res == INF)
    res = -1;
  print(res);
  return 0;
}
