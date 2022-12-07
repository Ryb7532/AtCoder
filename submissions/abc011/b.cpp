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
  string S;
  cin >> S;
  int n = S.size(), c = S[0]-'a';
  if (c>=0 && c<26)
    S[0] = c+'A';
  rep1(i, n-1) {
    c = S[i]-'A';
    if (c>=0 && c<26)
      S[i] = c+'a';
  }
  print(S);
  return 0;
}
