#include <bits/stdc++.h>
using namespace std;

int main() {
  string S[3];
  for (int i=0; i<3; i++)
    cin >> S[i];
  for (int i=0; i<3; i++)
    printf("%c", S[i][0]-'a'+'A');
  cout << endl;
  return 0;
}
