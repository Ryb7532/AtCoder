#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i, s, n) for (int i=(s); i>(n); i--)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N, ng1, ng2, ng3;
  cin >> N >> ng1 >> ng2 >> ng3;
  if (N == ng1 || N == ng2 || N == ng3) {
    print("NO");
    return 0;
  }
  rep(j, 100) {
    repr(i, 3, 0) {
      if (N-i == ng1 || N-i == ng2 || N-i == ng3) {
        continue;
      }
      N -= i;
      break;
    }
  }
  print((N<=0)?"YES":"NO");
  return 0;
}
