#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


void printtime(int h, int m, int s) {
  cout << h/10 << h%10 << ":" << m/10 << m%10 << ":" <<  s/10 << s%10 << endl;
  return;
}

int main() {
  int N;
  cin >> N;
  int h, m, s;
  s = N%60;
  N /= 60;
  m = N%60;
  h = N/60;
  printtime(h, m, s);
  return 0;
}
