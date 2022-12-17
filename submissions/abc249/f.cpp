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


int main() {
  int N,K;
  cin >> N >> K;
  vector<bool> T(N+1);
  vector<int> Y(N+1);
  rep(i,N) {
    int t;
    cin >> t >> Y[i+1];
    T[i+1] = (t == 1);
  }
  Y[0] = 0;
  T[0] = true;
  ll res = -1e18;
  ll add = 0;
  priority_queue<int> minus;
  for (int i=N; i>=0 && K>=0; i--) {
    if (!T[i]) {
      if (Y[i]>=0) {
        add += Y[i];
      } else {
        // minus.push(Y[i]);
        // while (minus.size() > K) {
        //   add += minus.top();
        //   minus.pop();
        // }
        if (K == 0) {
          add += Y[i];
        } else if (minus.size() < K) {
          minus.push(Y[i]);
        } else {
          int top = minus.top();
          if (top <= Y[i]) {
            add += Y[i];
          } else {
            add += top;
            minus.pop();
            minus.push(Y[i]);
          }
        }
      }
    } else {
      res = max(res, Y[i] + add);
      while (!minus.empty() && minus.size() >= K) {
        add += minus.top();
        minus.pop();
      }
      K--;
    }
  }
  print(res);
  return 0;
}
