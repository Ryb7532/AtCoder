#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

const int MAX_V = 400;
const ll INF = 1e9;
int V;
ll d[MAX_V][MAX_V];
typedef struct{
  int from;
  int to;
  ll cost;
} Edge;


void init() {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  rep(k, V)
    rep(i, V)
      rep(j, V)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}


int main() {
  int M,K;
  cin >> V >> M;
  init();
  rep(i,M) {
    int a,b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b] = d[b][a] = c;
  }
  warshall_floyd();
  cin >> K;
  rep(k,K) {
    int x,y; ll z,res = 0;
    cin >> x >> y >> z;
    x--; y--;
    rep(i,V) {
      rep(j,V) {
        d[i][j] = min(d[i][j],min(d[i][x]+d[y][j]+z,d[i][y]+d[x][j]+z));
      }
    }
    rep(i,V-1) {
      reps(j,i+1,V) {
        res += d[i][j];
      }
    }
    print(res);
  }
  return 0;
}
