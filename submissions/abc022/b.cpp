#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int a, A[100000], ans = 0;
  fill(A, A+100000, 0);
  rep(i, N) {
    cin >> a;
    a--;
    ans += (A[a]>0);
    A[a]++;
  }
  print(ans);
  return 0;
}
