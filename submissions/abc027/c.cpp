#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  ll N;
  cin >> N;
  int h = 0;
  ll x = 1;
  int ans = 1; // 1->turn of takahashi
  while ((N >> h) != 0)
    h++;
  if (h%2) {
    while (x<=N) {
      if (ans) {
        x *= 2;
        x++;
      } else {
        x *= 2;
      }
      ans++;
      ans %= 2;
    }
  } else {
    while (x<=N) {
      if (ans) {
        x *= 2;
      } else {
        x *= 2;
        x++;
      }
      ans++;
      ans %= 2;
    }
  }
  if (ans) {
    print("Takahashi");
  } else {
    print("Aoki");
  }
  return 0;
}
