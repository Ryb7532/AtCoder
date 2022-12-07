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


int main() {
  int N, K, M;
  cin >> N >> K;
  M = 2*K;
  vector<vector<int>> b(M+1,vector<int>(M+1,0));
  rep(i,N) {
    int x,y;
    string c;
    cin >> x >> y >> c;
    x %= M; y %= M;
    if (c == "W") {
      x += K;
      x %= M;
    }
    b[x+1][y+1]++;
  }
  rep1(i,M) {
    rep1(j,M) {
      b[i][j] += b[i][j-1];
    }
  }
  rep1(i,M) {
    rep1(j,M) {
      b[i][j] += b[i-1][j];
    }
  }
  int ans = 0;
  rep(i,K) {
    rep(j,K) {
      int tmp;
      tmp = b[i+K][M]+b[M][j+K]-b[i][M]-b[M][j]-2*b[i+K][j+K]+2*b[i][j+K]+2*b[i+K][j]-2*b[i][j];
      ans = max(ans,tmp);
      tmp = b[M][M]-tmp;
      ans = max(ans,tmp);
    }
  }
  print(ans);
  return 0;
}
