#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int a = (M/2)*2+1;
  for (int i=1; i<=M/2; i++)
    cout << i << ' ' << a+1-i << endl;
  for (int i=1; i<=(M+1)/2; i++)
    cout << a+i << ' ' << 2*M+2-i << endl;
  return 0;
}
