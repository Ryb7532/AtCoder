#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

int main() {
  int N;
  cin >> N;
  vector<ll> T(N), D(N);
  vector<int> I(N);
  priority_queue<ll,vector<ll>,greater<ll>> Q;
  rep(i,N) {
    cin >> T[i] >> D[i];
    I[i] = i;
  }
  auto f = [&](int a, int b) {
    return T[a] < T[b];
  };
  sort(all(I), f);
  int i = 0, res = 0;
  ll t = T[I[0]];
  while (true) {
    while (i < N && T[I[i]] <= t) {
      int id = I[i++];
      Q.push(T[id]+D[id]);
    }
    while (!Q.empty() && Q.top() < t)
      Q.pop();
    if (!Q.empty()) {
      Q.pop();
      t++;
      res++;
    } else if (i < N)
      t = T[I[i]];
    else
      break;
  }
  print(res);
  return 0;
}