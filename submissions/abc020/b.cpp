#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  string A, B;
  int ans = 0;
  cin >> A >> B;
  int a = A.size(), b = B.size();
  rep(i, a) {
    ans *= 10;
    ans += A[i]-'0';
  }
  rep(i, b) {
    ans *= 10;
    ans += B[i]-'0';
  }
  print(ans*2);
  return 0;
}
