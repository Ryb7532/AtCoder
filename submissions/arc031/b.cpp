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
string A[10];

bool connect(int a,int b) {
  vector<vector<bool>> go(10,vector<bool>(10,false));
  queue<pii> Q;
  Q.push(make_pair(a,b));
  while (!Q.empty()) {
    pii q = Q.front();
    int x=q.first, y=q.second;
    go[x][y] = true;
    Q.pop();
    if (x>0 && A[x-1][y] == 'o' && !go[x-1][y])
      Q.push(make_pair(x-1,y));
    if (x<9 && A[x+1][y] == 'o' && !go[x+1][y])
      Q.push(make_pair(x+1,y));
    if (y>0 && A[x][y-1] == 'o' && !go[x][y-1])
      Q.push(make_pair(x,y-1));
    if (y<9 && A[x][y+1] == 'o' && !go[x][y+1])
      Q.push(make_pair(x,y+1));
  }
  rep(i,10) {
    rep(j,10) {
      if (A[i][j] == 'o' && !go[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  rep(i,10) {
    cin >> A[i];
  }
  rep(i,10) {
    rep(j,10) {
      if (connect(i,j)) {
        print("YES");
        return 0;
      }
    }
  }
  print("NO");
  return 0;
}
