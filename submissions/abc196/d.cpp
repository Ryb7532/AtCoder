#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

vec<vec<bool>> is(16, vec<bool>(16,false));
int H,W;
ll res = 0;

void dfs(int h, int w, int a) {
  if (a==0) {
    res++;
    return ;
  }
  if (h==H-1 && w==W-1)
    return;
  if (h!=H-1)
    dfs(h+1,w,a);
  else
    dfs(0,w+1,a);
  if (!is[h][w]) {
    if (h!=H-1 && !is[h+1][w]) {
      is[h+1][w] = true;
      dfs(h+1,w,a-1);
      is[h+1][w] = false;
    }
    if (w!=W-1 && !is[h][w+1]) {
      is[h][w+1] = true;
      if (h!=H-1)
        dfs(h+1,w,a-1);
      else
        dfs(0,w+1,a-1);
      is[h][w+1] = false;
    }
  }
}

int main() {
  int A,B;
  cin >> H >> W >> A >> B;
  dfs(0,0,A);
  print(res);
  return 0;
}
