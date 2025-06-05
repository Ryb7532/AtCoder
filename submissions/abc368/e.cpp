#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep1(n) rep2(_,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define fore(e,v) for (auto &e: v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define printyn(f) cout << ((f) ? "Yes" : "No") << endl
#define printall(a) {for (auto e: a) cout << e << " "; cout << endl;}
void print() {cout << endl;}
template<typename Arg, typename... Args> void print(const Arg a, const Args... b) {
  cout << a;
  (cout << ... << (cout << ' ', b)) << endl;
}
template<class... T> void scan(T&... a) {(cin >> ... >> a);}

int main() {
  int N,M;
  scan(N,M);
  vector<int> A(M), B(M), id(M);
  vector<ll> S(M), T(M), X(M,0);
  vector<ll> D(N,0);
  vector<priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>> Qs(N);
  scan(X[0]);
  rep(i,M) {
    scan(A[i], B[i], S[i], T[i]);
    A[i]--;
    B[i]--;
    id[i] = i;
  }
  sort(all(id), [&](int a, int b) {return S[a] < S[b];});
  fore(i,id) {
    int a = A[i], b = B[i];
    ll s = S[i], t = T[i];
    auto &q = Qs[a];
    while (q.size() > 0 && q.top().first <= s) {
      auto [tj, j] = q.top();
      q.pop();
      chmax(D[a], tj+X[j]);
    }
    if (i != 0)
      X[i] = max((ll)0, D[a]-s);
    Qs[b].push({t, i});
  }
  rep(i,1,M) {
    cout << X[i] << " ";
  }
  print();
  return 0;
}