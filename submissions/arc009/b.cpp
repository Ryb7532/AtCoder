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
  vec<int> b(10);
  rep(i,10) {
    int tmp;
    cin >> tmp;
    b[tmp] = i;
  }
  int N;
  cin >> N;
  vec<string> a(N);
  vec<pair<int,int>> c(N);
  rep(i,N) {
    cin >> a[i];
    int num = 0;
    for (char &e: a[i]) {
      num *= 10;
      num += b[e-'0'];
    }
    c[i] = make_pair(num,i);
  }
  sort(all(c));
  rep(i,N) {
    print(a[c[i].second]);
  }
  return 0;
}
