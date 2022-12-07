#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();
int N;
int dis[8];

void rec(int s) {
  if (s == N) {
    rep(i, N) {
      cout << (char)(dis[i]+'a');
    }
    cout << endl;
    return ;
  }
  rep(i, 3) {
    dis[s] = i;
    rec(s+1);
  }
  return ;
}

int main() {
  cin >> N;
  rec(0);
  return 0;
}
