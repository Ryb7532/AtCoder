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
  N %= 30;
  string ans = "123456";
  rep(i, N) {
    int id1 = i%5, id2 = i%5+1;
    swap(ans[id1], ans[id2]);
  }
  print(ans);
  return 0;
}
