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

vector<char> dir = {'L','R','U','D'};
vector<int> dhs = {0,0,-1,1}, dws = {-1,1,0,0};


int main() {
  int H,W,N,x,y;
  string S,T;
  cin >> H >> W >> N >> x >> y >> S >> T;
  vector<tuple<int,int,int,int>> cap(N+1);
  bool remain = true;
  cap[N] = {1,H,1,W};
  for (int i=N-1; i>=0; i--) {
    int hmin,hmax,wmin,wmax;
    tie(hmin,hmax,wmin,wmax) = cap[i+1];
    int dh,dw;
    rep(j,4) {
      if (S[i] == dir[j]) {
        dh = dhs[j];
        dw = dws[j];
      }
    }
    hmin = max(hmin, hmin-dh);
    hmax = min(hmax, hmax-dh);
    wmin = max(wmin, wmin-dw);
    wmax = min(wmax, wmax-dw);
    if (hmin>H || hmax<1 || wmin>W || wmax<1) {
      remain = false;
    }
    if (i==0) {
      cap[i] = {hmin,hmax,wmin,wmax};
      continue;
    }
    rep(j,4) {
      if (T[i-1] == dir[j]) {
        dh = dhs[j];
        dw = dws[j];
      }
    }
    hmin = max(min(hmin, hmin-dh),1);
    hmax = min(max(hmax, hmax-dh),H);
    wmin = max(min(wmin, wmin-dw),1);
    wmax = min(max(wmax, wmax-dw),W);
    cap[i] = {hmin,hmax,wmin,wmax};
  }
  int hmin,hmax,wmin,wmax;
  tie(hmin,hmax,wmin,wmax) = cap[0];
  if (x<hmin || x>hmax || y<wmin || y>wmax)
    remain = false;
  print((remain ? YES : NO));
  return 0;
}
