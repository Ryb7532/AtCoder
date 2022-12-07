#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int N;
  cin >> N;
  if (N < 60) {
    print("Bad");
  } else if (N < 90) {
    print("Good");
  } else if (N < 100) {
    print("Great");
  } else {
    print("Perfect");
  }
  return 0;
}
