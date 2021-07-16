#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  string S;
  int Q;
  cin >> N >> S >> Q;
  bool c = false;
  rep(_,Q) {
    int T,A,B;
    cin >> T >> A >> B;
    if (T==1) {
      A--; B--;
      if (c) {
        A += N;
        B += N;
        A %= 2*N;
        B %= 2*N;
      }
      char tmp = S[A];
      S[A] = S[B];
      S[B] = tmp;
    } else {
      c = !c;
    }
  }
  if (c) {
    cout << S.substr(N,N) << S.substr(0,N) << endl;
  } else
    print(S);
  return 0;
}
