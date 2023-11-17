#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rep(i,s,e) for (int i=(s); i<(e); i++)
#define rrep(i,n) for (int i=(n)-1; i>=0; i--)
#define rrep(i,s,e) for (int i=(e)-1; i>=(s); i--)
#define all(v) v.begin(),v.end()


// Task: Suffix Array
// Suffix Array Induced Sorting
struct RMQ {
  int sz;
  vector<int> data;
  RMQ() {}
  void init(int *v, int n) {
    sz = 1;
    while(sz<n) sz <<= 1;
    data.assign(2*sz, 1e9);
    rep(i,n) data[i+sz] = v[i];
    for(int k=sz-1; k>0; k--) data[k] = min(data[2*k], data[2*k+1]);
  }
  int get(int a, int b) {
    int L = 1e9, R = 1e9;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = min(L, data[a++]);
      if(b & 1) R = min(data[--b], R);
    }
    return min(L, R);
  }
};
class SuffixArrayIS {
  int N;
  int *S, *bkt, *sa, *lcp, *rank;
  RMQ rmq;

  inline void bucket(int *data, int n, int num_bkt) {
    bkt = new int[num_bkt];
    rep(i,num_bkt) bkt[i] = 0;
    rep(i,n) bkt[data[i]]++;
    rep(i,num_bkt-1) bkt[i+1] += bkt[i];
  }
  inline void induced_sort(int *arr, int *data, int n, int num_bkt, bool *stype) {
    bucket(data, n, num_bkt);
    rep(i,n) {
      int j = arr[i] - 1;
			if (j >= 0 && !stype[j]) arr[bkt[data[j]-1]++] = j;
    }
    bucket(data, n, num_bkt);
    rrep(i,n) {
      int j = arr[i] - 1;
      if (j >= 0 && stype[j]) arr[--bkt[data[j]]] = j;
    }
  }
  inline bool is_LMS(int i, int n, bool *stype) {
    if (i == 0)
      return false;
    return stype[i] && !stype[i-1];
  }
  void buildSA(int *arr, int *data, int n, int num_bkt) {
    rep(i,n)
      arr[i] = -1;
    if (n == 1) {
      arr[0] = 0;
      return ;
    }
    bool Stype[n];
    Stype[n-1] = true;
    rrep(i,n-1)
      Stype[i] = (data[i] < data[i+1] || (data[i] == data[i+1] && Stype[i+1]));
    bucket(data, n, num_bkt);
    rep(i,n)
      if (is_LMS(i,n,Stype)) arr[--bkt[data[i]]] = i;
    induced_sort(arr, data, n, num_bkt, Stype);

    int N_ = 0;
    rep(i,n) if (is_LMS(arr[i],n,Stype)) arr[N_++] = arr[i];

    rep(i,N_,n)
      arr[i] = -1;
    arr[N_+arr[0]/2] = 0;
    rep(i,1,N_) {
      int prev = arr[i-1], curr = arr[i];
      bool diff = (i == 1 || data[prev] != data[curr]);
      for (int j=1; !diff; j++) {
        if (data[prev+j] != data[curr+j]) diff = true;
        if (!is_LMS(prev+j,n,Stype) && !is_LMS(curr+j,n,Stype)) continue;
        if (!(is_LMS(prev+j,n,Stype) && is_LMS(curr+j,n,Stype))) diff = true;
        break;
      }
      if (diff)
        arr[N_+curr/2] = arr[N_+prev/2]+1; // N_ <= N/2 and LCMs are not continuous
      else
        arr[N_+curr/2] = arr[N_+prev/2];
    }

    int label = arr[N_+arr[N_-1]/2]+1;
    int r = n;
    rrep(i,N_,n)
      if (arr[i] != -1) arr[--r] = arr[i]; // Rearrange the original array to right
    if (N_ != label) {
      buildSA(arr, arr+n-N_, N_, label);

      rep(i,N_)
        arr[r+arr[i]] = i;
      int l = 0;
      rep(i,n)
        if (is_LMS(i,n,Stype)) arr[arr[r+l++]] = i;
    }

    rep(i,N_,n)
      arr[i] = -1;
    bucket(data, n, num_bkt);
    rrep(i,N_)
      swap(arr[--bkt[data[arr[i]]]], arr[i]);
    induced_sort(arr, data, n, num_bkt, Stype);
  }
  void buildLCP() {
    rank = new int[N];
    lcp = new int[N-1];
    rep(i,N) rank[sa[i]] = i;
    int h = 0;
    rep(i,N-1) {
      int j = sa[rank[i]-1];
      if (h > 0) h--;
      while (j+h < N && i+h < N && S[j+h] == S[i+h]) h++;
      lcp[rank[i]-1] = h;
    }
  }
  void buildRMQ() { rmq.init(lcp, N-1); }

public:
  SuffixArrayIS(const string &s) : N(s.size()+1) {
    S = new int[N];
    sa = new int[N];
    rep(i,N-1) {
      S[i] = (int)(s[i]);
    }
    S[N-1] = 0;
    int NB = 256;
    buildSA(sa, S, N, NB);
    buildLCP();
    buildRMQ();
  }
    SuffixArrayIS(const vector<int> &v) : N(v.size()+1) {
    S = new int[N];
    sa = new int[N];
    int m = INT_MAX, M = INT_MIN;
    rep(i,N-1) {
      S[i] = v[i];
      m = min(m,v[i]);
      M = max(M,v[i]);
    }
    S[N-1] = --m;
    int NB = M-m+1;
    buildSA(sa, S, N, NB);
    buildLCP();
    buildRMQ();
  }
  int common_prefix(int a, int b) {
    if (a == b) return N-1-a;
    if (b >= N-1) return 0;
    if (rank[a] > rank[b]) swap(a,b);
    return rmq.get(rank[a], rank[b]);
  }
  inline int &operator[](int id) { return sa[id+1]; };
};


// Task: Maximum Common Length between prefix and suffix of S[0:i] (0<=i<|S|)
// KMP Algorithm (O(|S|))
class KMP {
  int N;
  vector<int> S, res, path;

  void solve() {
    int j = -1;
    rep(i,N) {
      while (j >= 0 && S[i] != S[j]) {
        j = path[j];
      }
      j++;
      res[i+1] = path[i+1] = j;
      if (S[i+1] == S[j])
        path[i+1] = path[j];
    }
  }

public:
  KMP(const string &s) : N(s.size()), S(N), res(N+1,-1), path(N+1,-1) {
    rep(i,N) {
      S[i] = (int)s[i];
    }
    solve();
  }
  KMP(const vector<int> &v) : N(v.size()), S(v), res(N+1,-1), path(N+1,-1) {
    solve();
  }
  int operator[](const int &i) const { return res[i+1]; }
};


// Task: Maximum Common Prefix Length between S[0:|S|-1] and S[i:|S|-1] (0<=i<|S|)
// Z-Algorithm (O(|S|))
class LongestCommonPrefix {
  int N;
  vector<int> S, prefix;

  void solve() {
    for (int i=1, j=0; i<N; i++) {
      if (i-j + prefix[i-j] < prefix[j])
        prefix[i] = prefix[i-j];
      else {
        int k = max(0, j+prefix[j]-i);
        while (i + k < N && S[k] == S[i+k])
          k++;
        prefix[i] = k;
        j = i;
      }
    }
    prefix[0] = N;
  }

public:
  LongestCommonPrefix(const string &s) : N(s.size()), S(N), prefix(N,0) {
    rep(i,N) {
      S[i] = (int)s[i];
    }
    solve();
  }
  LongestCommonPrefix(const vector<int> &v) : N(v.size()), S(v), prefix(N,0) {
    solve();
  }
  int operator[](const int &i) const { return prefix[i]; }
};


// Task: Longest Palindromic Substring
// Manacher Algorithm (O(|S|))
struct Palindrome {
  int N;
  string S;
  vector<int> radius;

  Palindrome() {}
  Palindrome(const string &s, const char dammy='#') : N(2*s.size()+1), S(s), radius(N) {
    string T;
    T.push_back(dammy);
    for (char c: s) {
      T.push_back(c);
      T.push_back(dammy);
    }
    int i=0, j=0;
    while (i < N) {
      while (i-j >= 0 && i+j < N && T[i-j] == T[i+j])
        j++;
      radius[i] = j;
      int k = 1;
      while (i-k >= 0 && i+k < N && k+radius[i-k] < j) {
        radius[i+k] = radius[i-k];
        k++;
      }
      i += k;
      j -= k;
    }
  }
  inline int size() { return N/2; }
  string get(const int &i) { return S.substr((i-radius[i]+1)/2, radius[i]-1); }
  string longest() {
    int len = 0, c = -1;
    rep(i,N) {
      if (len < radius[i]-1) {
        len = radius[i]-1;
        c = i;
      }
    }
    return get(c);
  }
  friend istream &operator>>(istream &is,Palindrome &a) {
    string s;
    is >> s;
    a = Palindrome(s);
    return (is);
  }
};
