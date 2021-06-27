#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


int main() {
  string X;
  cin >> X;
  int n = X.size();
  rep(i, n) {
    if (X[i] == 'c') {
      i++;
      if (i >= n || X[i] != 'h') {
        print("NO");
        return 0;
      }
    } else if (X[i] == 'o' || X[i] == 'k' || X[i] == 'u') {
      continue;
    } else {
      print("NO");
      return 0;
    }
  }
  print("YES");
  return 0;
}
