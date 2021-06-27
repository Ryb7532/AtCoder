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


int main() {
  int N,L,o;
  cin >> N >> L;
  vec<vec<bool>> x(L,vec<bool>(N+1));
  char c;
  scanf("%c",&c); //read \n
  rep(i,L) {
    int cnt = 0;
    rep(j,2*N) {
      scanf("%c",&c);
      if (c == '|')
        cnt++;
      else if (c == '-')
        x[i][cnt] = true;
    }
  }
  rep(i,2*N) {
    scanf("%c",&c);
    if (c == 'o')
      o = i/2;
  }
  int ans = o;
  repr(i,L,0) {
    if (x[i][ans+1])
      ans++;
    else if (x[i][ans])
      ans--;
  }
  print(++ans);
  return 0;
}
