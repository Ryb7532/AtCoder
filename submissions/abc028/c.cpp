#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end()

int main() {
  int N[5], sum = 0;
  rep(i, 5) {
    cin >> N[i];
    sum += N[i];
  }
  vector<int> ssum;
  rep(i, 5) {
    reps(j, i+1, 5) {
      ssum.push_back(N[i] + N[j]);
    }
  }
  sort(all(ssum));
  print(sum - ssum[2]);
  return 0;
}
