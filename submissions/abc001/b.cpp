#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int m;
  cin >> m;
  int vv;
  if (m<100) {
    vv = 0;
  } else if (m<=5000) {
    vv = m/100;
  } else if (m<=30000) {
    vv = m/1000+50;
  } else if (m<=70000) {
    vv = (m/1000-30)/5+80;
  } else {
    vv = 89;
  }
  printf("%02d\n", vv);
  return 0;
}
