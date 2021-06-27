#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int ans = 0;
vec<int> A(3),B(3);

void dfs(int a, int c) {
  if (a>=3) {
    ans = max(ans,c);
    return ;
  }
  rep(i,3) {
    if (B[i] == 0)
      continue;
    int b = B[i];
    B[i] = 0;
    dfs(a+1,c*(A[a]/b));
    B[i] = b;
  }
  return ;
}

int main() {
  rep(i,3) cin >> A[i];
  rep(i,3) cin >> B[i];
  dfs(0,1);
  print(ans);
  return 0;
}
