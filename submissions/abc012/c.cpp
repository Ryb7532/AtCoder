#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  int N;
  cin >> N;
  int a = 45*45;
  a -= N;
  rep1(i, 9) {
    if (a%i)
      continue;
    int j = a/i;
    if (j<0 || j>9)
      continue;
    printf("%d x %d\n", i, j);
  }
  return 0;
}
