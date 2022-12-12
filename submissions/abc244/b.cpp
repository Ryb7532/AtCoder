#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

pair<int,int> direct[] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
int d = 0;


int main() {
  int N;
  string T;
  cin >> N >> T;
  int x = 0, y = 0;
  rep(i,N) {
    if (T[i] == 'R') {
      d++;
      d %= 4;
    } else {
      x += direct[d].first;
      y += direct[d].second;
    }
  }
  print(x << " " << y);
  return 0;
}
