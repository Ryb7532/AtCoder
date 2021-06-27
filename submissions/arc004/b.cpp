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
  int N;
  cin >> N;
  int d, sum = 0, M = 0;
  rep(i,N) {
    cin >> d;
    sum += d;
    M = max(M,d);
  }
  print(sum);
  print(((sum>2*M)?0:2*M-sum));
  return 0;
}
