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
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i,M) {
    cin >> A[i];
  }
  vector<int> stack;
  int j = 0;
  rep(i,N) {
    stack.push_back(i+1);
    if (j < M && i+1 == A[j]) {
      j++;
    } else {
      while (!stack.empty()) {
        int back = stack.back();
        stack.pop_back();
        cout << back << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
