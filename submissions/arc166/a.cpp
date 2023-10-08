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
  int T;
  cin >> T;
  rep(_,T) {
    int N;
    string X,Y;
    cin >> N >> X >> Y;
    X.push_back('C');
    Y.push_back('C');
    N++;
    bool flag = true;
    int s = 0;
    rep(i,N) {
      if (Y[i] == 'C') {
        if (X[i] != 'C') {
          flag = false;
          break;
        }
        int cntA = 0, cntC = 0;
        rep(j,s,i) {
          if (X[j] == 'A')
            cntA++;
          if (X[j] == 'C')
            cntC++;
          if (Y[j] == 'A') {
            if (cntA+cntC == 0)
              flag = false;
            if (cntA > 0)
              cntA--;
            else
              cntC--;
          }
        }
        if (cntA != 0)
          flag = false;
        s = i+1;
      }
    }
    printyesno(flag);
  }
  return 0;
}