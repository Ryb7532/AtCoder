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
  int T, N, M;
  cin >> T >> N;
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  cin >> M;
  int B[M];
  rep(i, M) {
    cin >> B[i];
  }
  bool ans = true;
  int a = 0;
  rep(i, M) {
    while (a<N && A[a]+T<B[i]) {
      a++;
    }
    if (a>=N || A[a]>B[i]) {
      ans = false;
      break;
    }
    a++;
  }
  print((ans)?"yes":"no");
  return 0;
}
