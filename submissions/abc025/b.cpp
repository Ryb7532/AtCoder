#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int d[N], p = 0;
  string s;
  rep(i, N) {
    cin >> s >> d[i];
    if (s.compare("West") == 0)
      d[i] = -d[i];
  }
  rep(i, N) {
    int dis = abs(d[i]);
    if (dis < A) {
      p += d[i]*A/dis;
    } else if (dis <= B) {
      p += d[i];
    } else {
      p += d[i]*B/dis;
    }
  }
  if (p < 0) {
    cout << "West ";
    p = -p;
  } else if (p > 0)
    cout << "East ";
  print(p);
  return 0;
}
