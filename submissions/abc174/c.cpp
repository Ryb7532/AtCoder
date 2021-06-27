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
  ll K;
  cin >> K;
  if (K%2==0 || K%5==0) {
    print(-1);
    return 0;
  }
  ll i=1,r=7;
  while (1) {
    if (r%K == 0) {
      print(i);
      return 0;
    }
    r *= 10;
    r += 7;
    r %= K;
    i++;
  }
  return 0;
}
