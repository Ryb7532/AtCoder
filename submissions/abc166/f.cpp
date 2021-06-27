#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, num[3];
  cin >> N >> num[0] >> num[1] >> num[2];
  string s[N], c[3] = {"AB", "BC", "AC"};
  int ans[N];
  for (int i=0; i<N; i++)
    cin >> s[i];
  if (num[0]+num[1]+num[2] == 0) {
    cout << "No\n";
    return 0;
  }
  if (num[0]+num[1]+num[2] == 1) {
    for (int i=0; i<N; i++) {
      for (int j=0; j<3; j++) {
        if (s[i].compare(c[j]) == 0) {
          if (num[j] == 1) {
            num[j]--;
            num[(j+1)%3]++;
            ans[i] = (j+1)%3;
          } else if (num[(j+1)%3] == 1) {
            num[(j+1)%3]--;
            num[j]++;
            ans[i] = j;
          } else {
            cout << "No\n";
            return 0;
          }
        }
      }
    }
  } else {
    for (int i=0; i<3; i++)
      if (s[0].compare(c[i]) == 0)
        if (num[i]+num[(i+1)%3] == 0) {
          cout << "No\n";
          return 0;
        }
    for (int i=0; i<N; i++) {
      for (int j=0; j<3; j++) {
        if (s[i].compare(c[j]) == 0) {
          if (num[j]==1 && num[(j+1)%3]==1 && i<N-1) {
            if (s[i+1].compare(c[(j+2)%3])==0) {
              num[j]++;
              num[(j+1)%3]--;
              ans[i] = j;
            } else {
              num[(j+1)%3]++;
              num[j]--;
              ans[i] = (j+1)%3;
            }
          } else {
            if (num[j]<num[(j+1)%3]) {
              num[j]++;
              num[(j+1)%3]--;
              ans[i] = j;
            } else {
              num[j]--;
              num[(j+1)%3]++;
              ans[i] = (j+1)%3;
            }
          }
        }
      }
    }
  }
  cout << "Yes\n";
  for (int i=0; i<N; i++) {
    char a = 'A'+ans[i];
    cout << a << endl;
  }
  return 0;
}
