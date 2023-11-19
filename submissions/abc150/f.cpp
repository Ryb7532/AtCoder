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


// Task: Maximum Common Length between prefix and suffix of S[0:i] (0<=i<|S|)
// KMP Algorithm (O(|S|))
class KMP {
  int N;
  vector<int> S;
  vector<int> res, path;

  void solve() {
    int j = -1;
    rep(i,N) {
      while (j >= 0 && S[i] != S[j]) {
        j = path[j];
      }
      j++;
      res[i+1] = path[i+1] = j;
      if (S[i+1] == S[j])
        path[i+1] = path[j];
    }
  }

public:
  KMP(const string &s) : N(s.size()), S(N), res(N+1,-1), path(N+1,-1) {
    rep(i,N) {
      S[i] = (int)s[i];
    }
    solve();
  }
  KMP(const vector<int> &v) : N(v.size()), S(v), res(N+1,-1), path(N+1,-1) {
    solve();
  }
  int operator[](const int &i) const { return res[i+1]; }
};


int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    cin >> B[i];
  }
  vector<int> V(3*N+1);
  rep(i,N) {
    V[i] = B[i]^B[(i+1)%N];
  }
  V[N] = -1;
  rep(i,2*N) {
    V[N+1+i] = A[i%N]^A[(i+1)%N];
  }
  KMP kmp(V);
  rep(i,N) {
    if (kmp[2*N+i] >= N) {
      print(i << " " << (A[i]^B[0]));
    }
  }
  return 0;
}