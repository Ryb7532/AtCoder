#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int A, B, C, K, S, T;
  cin >> A >> B >> C >> K >> S >> T;
  int ans = 0;
  ans += A*S;
  ans += B*T;
  if (S+T>=K)
    ans -= (S+T)*C;
  print(ans);
  return 0;
}
