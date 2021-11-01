#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,Q;
  cin >> N >> Q;
  vec<pair<int,int>> T(N, {-1,-1});
  rep(_,Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int x,y;
      cin >> x >> y;
      x--; y--;
      T[x].second = y;
      T[y].first = x;
    } else if (q == 2) {
      int x,y;
      cin >> x >> y;
      x--; y--;
      T[x].second = -1;
      T[y].first = -1;
    } else {
      int x;
      cin >> x;
      x--;
      vec<int> F;
      vec<int> B;
      int id = x;
      F.push_back(id+1);
      while(T[id].first!=-1) {
        id = T[id].first;
        F.push_back(id+1);
      }
      id = x;
      while(T[id].second!=-1) {
        id = T[id].second;
        B.push_back(id+1);
      }
      int sf = F.size(), sb = B.size();
      int m = sf + sb;
      stringstream ss;
      ss << m << ' ';
      rep(i,sf) {
        ss << F[sf-1-i] << ' ';
      }
      rep(i,sb) {
        ss << B[i] << ' ';
      }
      string res = ss.str();
      res.pop_back();
      print(res);
    }
  }
  return 0;
}
