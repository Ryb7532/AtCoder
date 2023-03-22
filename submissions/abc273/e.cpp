#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


using Node = struct {int p; int x;};

int main() {
  int Q;
  cin >> Q;
  vector<Node> nodes(Q+1);
  map<int,int> save;
  nodes[0] = {0,-1};
  int last = 0;
  rep(i,Q) {
    string OP;
    cin >> OP;
    int X;
    if (OP != "DELETE")
      cin >> X;
    if (OP == "ADD") {
      nodes[i+1] = {last, X};
      last = i+1;
    }
    if (OP == "DELETE") {
      last = nodes[last].p;
    }
    if (OP == "SAVE") {
      save[X] = last;
    }
    if (OP == "LOAD") {
      if (save.find(X) != save.end())
        last = save[X];
      else
        last = 0;
    }
    cout << nodes[last].x << " ";
  }
  cout << endl;
  return 0;
}
