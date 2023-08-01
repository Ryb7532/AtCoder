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
  int N;
  cin >> N;
  vector<int> A(N), total(4,0);
  rep(i,N) {
    cin >> A[i];
    total[--A[i]]++;
  }
  int id = 0;
  vector<vector<int>> state(4, vector<int>(4, 0));
  rep(i,4) {
    rep(j,total[i]) {
      state[i][A[id++]]++;
    }
  }
  int res = 1e9;
  rep(i,4) {
    int tmp = 0;
    vector<vector<int>> nstate(4, vector<int>(4, 0));
    rep(j,4) {
      rep(k,4) {
        if (j==k)
          continue;
        nstate[j][k] = state[j][k];
      }
    }
    rep(j,4) {
      tmp += nstate[i][j];
      nstate[i][j] -= nstate[j][i];
      nstate[j][i] = 0;
    }
    rep(j,4) {
      rep(k,4) {
        if (nstate[i][j] < 0 && nstate[i][k] > 0) {
          int minjk = min(-nstate[i][j], nstate[i][k]);
          nstate[j][k] += minjk;
          nstate[i][j] += minjk;
          nstate[i][k] -= minjk;
        }
      }
    }
    rep(j,4) {
      rep(k,4) {
        int minjk = min(nstate[j][k], nstate[k][j]);
        tmp += minjk;
        nstate[j][k] -= minjk;
        nstate[k][j] -= minjk;
      }
    }
    int non0 = 0, cntnon0 = 0;
    rep(j,4) {
      rep(k,4) {
        if (nstate[j][k] != 0) {
          if (cntnon0 != 0)
            assert(non0 == nstate[j][k]);
          cntnon0++;
          non0 = nstate[j][k];
        }
      }
    }
    if (cntnon0 > 0)
      cntnon0--;
    tmp += non0 * cntnon0;
    res = min(res, tmp);
  }
  print(res);
  return 0;
}
