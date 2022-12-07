#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
long com[51][51] = {};

//降順
int des(const void *a, const void *b)
{
  return *(long *)b - *(long *)a;
}

void com_init() {
  for (int i=0; i<=50; i++)
    com[i][0] = 1;
  for (int i=1; i<=50; i++) {
    for (int j=1; j<=i; j++) {
      com[i][j] = com[i-1][j] + com[i-1][j-1];
    }
  }
  return ;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  long v[N];
  double sum = 0.0;
  int ca = 0, ct = 0;
  for (int i=0; i<N; i++)
    cin >> v[i];
  sort(v, v+N);
  reverse(v, v+N);
  for (int i=0; i<A; i++) {
    sum += v[i];
    if (v[i] == v[A-1])
      ca++;
  }
  printf("%.6lf\n", sum/A);
  for (int i=0; i<N; i++)
    if (v[i] == v[A-1])
      ct++;
  long ans = 0;
  com_init();
  if (ca == A)
    for (int i=A; i<=B; i++)
      ans += com[ct][i];
  else
    ans += com[ct][ca];
  cout << ans << endl;
  return 0;
}
