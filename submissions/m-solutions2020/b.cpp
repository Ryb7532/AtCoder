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
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  bool c1 = (A<B);
  while (K>0) {
    if (c1) {
      C *= 2;
    } else {
      B *= 2;
      c1 = (A<B);
    }
    K--;
  }
  print((A<B&&B<C)?"Yes":"No");
  return 0;
}
