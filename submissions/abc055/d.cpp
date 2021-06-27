#include <bits/stdc++.h>
using namespace std;
char ans[100002];
string s;

bool check(int n) {
  for (int i=1; i<n+1; i++) {
    if (s[i%n] == 'o') {
      if (ans[i] == 'S')
        ans[i+1] = ans[i-1];
      else
        ans[i+1] = (ans[i-1] == 'S') ? 'W' : 'S';
    } else {
      if (ans[i] == 'W')
        ans[i+1] = ans[i-1];
      else
        ans[i+1] = (ans[i-1] == 'S') ? 'W' : 'S';
    }
  }
  return (ans[0]==ans[n] && ans[1]==ans[n+1]);
}

int main() {
  int N;
  cin >> N >> s;
  ans[0] = 'S';
  ans[1] = 'S';
  if (check(N)) {
    for (int i=0; i<N; i++)
      cout << ans[i];
    cout << endl;
    return 0;
  }
  ans[0] = 'S';
  ans[1] = 'W';
  if (check(N)) {
    for (int i=0; i<N; i++)
      cout << ans[i];
    cout << endl;
    return 0;
  }
  ans[0] = 'W';
  ans[1] = 'S';
  if (check(N)) {
    for (int i=0; i<N; i++)
      cout << ans[i];
    cout << endl;
    return 0;
  }
  ans[0] = 'W';
  ans[1] = 'W';
  if (check(N)) {
    for (int i=0; i<N; i++)
      cout << ans[i];
    cout << endl;
    return 0;
  }
  cout << "-1\n";
  return 0;
}