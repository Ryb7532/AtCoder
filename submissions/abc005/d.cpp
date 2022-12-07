#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, Q;
  cin >> N;
  int d, D[N+1][N+1];
  rep(i, N+1)
    D[i][0] = D[0][i] = 0;
  rep1(i, N) {
    rep1(j, N) {
      cin >> d;
      D[i][j] = D[i][j-1] + d;
    }
  }
  rep1(i, N) {
    rep1(j, N) {
      D[i][j] += D[i-1][j];
    }
  }
  int md[N*N+1];
  fill(md, md+N*N+1, 0);
  rep(ax, N) {
    rep(ay, N) {
      reps(bx, ax+1, N+1) {
        reps(by, ay+1, N+1) {
          md[(bx-ax)*(by-ay)] = max(md[(bx-ax)*(by-ay)], D[bx][by] - D[bx][ay] - D[ax][by] + D[ax][ay]);
        }
      }
    }
  }
  int max = 0;
  rep(i, N*N+1) {
    if (max<md[i]) {
      max = md[i];
    } else {
      md[i] = max;
    }
  }
  cin >> Q;
  int p;
  rep(i, Q) {
    cin >> p;
    print(md[p]);
  }
  return 0;
}
