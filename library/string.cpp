#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

// Task: Longest Common Prefix between S[0:|S|-1] and S[i:|S|-1] (0<=i<|S|)
// Z-Algorithm (O(|S|))
vector<int> z_algorithm(const string &s) {
  int l = s.size();
  vector<int> prefix(l,0);
  for (int i=1, j=0; i<l; i++) {
    if (i + prefix[i-j] < j + prefix[j])
      prefix[i] = prefix[i-j];
    else {
      int k = max(0, j+prefix[j]-i);
      while (i + k < l && s[k] == s[i+k])
        k++;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = l;
  return prefix;
}


// Task: Longest Palindromic Substring
// Manacher Algorithm (O(|S|))
vector<int> manacher(const string &s) {
  int l = s.size();
  vector<int> radius(l);
  int i=0, j=0;
  while(i < l) {
    while (i-j>=0 && i+j<l && s[i-j]==s[i+j])
      j++;
    radius[i] = j;
    int k = 1;
    while (i-k>=0 && i+k<l && k+radius[i-k]<j) {
      radius[i+k] = radius[i-k];
      k++;
    }
    i += k;
    j -= k;
  }
  return radius;
}
