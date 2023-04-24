#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


const uint32_t aid = 0; // Additive identity
const uint32_t mid = UINT32_MAX; // Multiplicative identity

// Matrix
template< typename T >
struct Matrix {
  vector<vector<T>> A;
  Matrix(size_t n, size_t m): A(n,vector<T>(m,aid)) {};
  Matrix(size_t n): A(n,vector<T>(n,aid)) {};
  size_t height() const { return (A.size()); }
  size_t width() const { return (A[0].size()); }
  inline const vector< T > &operator[](int k) const { return A.at(k); }
  inline vector< T > &operator[](int k) { return A.at(k); }
  static Matrix I(size_t n) {
    Matrix mat(n);
    rep(i,n) mat[i][i] = mid;
    return mat;
  }
  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    rep(i,n)
      rep(j,m)
        (*this)[i][j] += B[i][j];
    return *this;
  }
  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    rep(i,n)
      rep(j,m)
        (*this)[i][j] -= B[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector<vector<T>> C(n, vector<T>(m,aid));
    rep(i,n)
      rep(j,m)
        rep(k,p)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return *this;
  }
  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return *this;
  }
  Matrix operator+(const Matrix &B) const { return Matrix(*this)+=B; }
  Matrix operator-(const Matrix &B) const { return Matrix(*this)-=B; }
  Matrix operator*(const Matrix &B) const { return Matrix(*this)*=B; }
  Matrix operator^(const long long k) const { return Matrix(*this) ^= k; }
  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    rep(i,n) {
      os << "[";
      rep(j,m)
        os << p[i][j] << (j+1 == m ? "]\n" : ",");
    }
    return os;
  }
  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    rep(i,height()) {
      int idx = -1;
      rep(j,height()) {
        if(B[j][i]!=aid) idx = j;
      }
      if(idx==-1) return (aid);
      if(i!=idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      rep(j,height()) {
        B[i][j] /= vv;
      }
      for(int j=i+1; j<(int)width(); j++) {
        T a = B[j][i];
        rep(k,height()) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};


struct bitInt {
  uint32_t v;

  bitInt(uint32_t v=0) : v(v) {}
  bitInt &operator=(const bitInt &a) {
    this->v = a.v;
    return *this;
  }
  bitInt &operator+=(const bitInt &a) {
    this->v ^= a.v;
    return *this;
  }
  bitInt &operator*=(const bitInt &a) {
    this->v &= a.v;
    return *this;
  }
  bitInt operator+(const bitInt &a) {
    return bitInt(*this) += a;
  }
  bitInt operator*(const bitInt &a) {
    return bitInt(*this) *= a;
  }
  friend ostream &operator<<(ostream &os, bitInt &a) {
    return os << a.v;
  }
};


int main() {
  int K,M;
  cin >> K >> M;
  vector<uint32_t> A(K), C(K);
  rep(i,K) {
    cin >> A[i];
  }
  rep(i,K) {
    cin >> C[i];
  }
  if (M <= K) {
    print(A[M-1]);
    return 0;
  }
  Matrix<bitInt> Bk(K,1), D(K);
  rep(i,K) {
    Bk[i][0] = A[K-1-i];
    if (i == 0) {
      rep(j,K) {
        D[i][j] = C[j];
      }
    } else {
      D[i][i-1] = mid;
    }
  }
  D ^= M-K;
  auto Bm = D * Bk;
  print(Bm[0][0]);
  return 0;
}
