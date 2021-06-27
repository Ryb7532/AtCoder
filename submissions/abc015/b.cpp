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
  int A, sum = 0, cnt = 0;
  rep(i, N) {
    cin >> A;
    if (A>0)
      cnt++;
    sum += A;
  }
  print((sum+cnt-1)/cnt);
  return 0;
}
