#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

int main() {
  int H,W,M;
  cin >> H >> W >> M;
  vector<pii> B(M);
  vi cntH(H, 0), cntW(W,0);
  vector<bool> canH(H,false), canW(W,false);
  rep(i,M) {
    int h,w;
    cin >> h >> w;
    h--; w--;
    B[i] = {h,w};
    cntH[h]++;
    cntW[w]++;
  }
  int mh = 0, mw = 0;
  ll cnth = 0, cntw = 0;
  rep(i,H) {
    mh = max(mh, cntH[i]);
  }
  rep(i,W) {
    mw = max(mw, cntW[i]);
  }
  rep(i,H) {
    if (mh == cntH[i]) {
      canH[i] = true;
      cnth++;
    }
  }
  rep(i,W) {
    if (mw == cntW[i]) {
      canW[i] = true;
      cntw++;
    }
  }
  ll c = cnth * cntw;
  rep(i,M) {
    int h,w;
    h = B[i].first;
    w = B[i].second;
    if (canH[h] && canW[w])
      c--;
  }
  print((c<=0)?mh+mw-1:mh+mw);
  return 0;
}
