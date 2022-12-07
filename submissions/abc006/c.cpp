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
  int N, M, a, b, c;
  cin >> N >> M;
  if (2*N>M || M>4*N) {
    a = b = c = -1;
  } else {
    c = (M-2*N)/2;
    b = (M-2*N)%2;
    a = N-b-c;
  }
  printf("%d %d %d\n", a, b, c);
  return 0;
}
