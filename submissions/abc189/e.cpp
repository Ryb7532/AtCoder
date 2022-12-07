#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

template< typename T >
struct Matrix {
  vec<vec<T>> A;
  Matrix(int n, int m): A(n,vec<T>(m,0)) {}
  Matrix(int n): A(n,vec<T>(n,0)) {};
  int height() const { return (A.size()); }
  int width() const { return (A[0].size()); }
  inline const vec< T > &operator[](int k) const { return A.at(k); }
  inline vec< T > &operator[](int k) { return A.at(k); }
  static Matrix I(int n) {
    Matrix mat(n);
    for(int i=0; i<n; i++) mat[i][i] = 1;
    return mat;
  }
  Matrix &operator+=(const Matrix &B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        (*this)[i][j] += B[i][j];
    return *this;
  }
  Matrix &operator-=(const Matrix &B) {
    int n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        (*this)[i][j] -= B[i][j];
    return *this;
  }
  Matrix &operator*=(const Matrix &B) {
    int n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vec<vec< T >> C(n, vec< T >(m,0));
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        for(int k=0; k<p; k++)
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
    int n = p.height(), m = p.width();
    for(int i=0; i<n; i++) {
      os << "[";
      for(int j=0; j<m; j++)
        os << p[i][j] << (j+1 == m ? "]\n" : ",");
    }
    return os;
  }
  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for(int i=0; i<width(); i++) {
      int idx = -1;
      for(int j=i; j<width(); j++) {
        if(B[j][i]!=0) idx = j;
      }
      if(idx==-1) return (0);
      if(i!=idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j=0; j<width(); j++) {
        B[i][j] /= vv;
      }
      for(int j=i+1; j<width(); j++) {
        T a = B[j][i];
        for(int k=0; k<width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

int main() {
  int N, M, Q;
  cin >> N;
  vec<ll> X(N), Y(N);
  rep(i,N)
    cin >> X[i] >> Y[i];
  cin >> M;
  vec<Matrix<ll>> mat(M+1, Matrix<ll>(3,3));
  mat[0] = Matrix<ll>::I(3);
  rep(i,M) {
    int op,p;
    cin >> op;
    Matrix<ll> m(3);
    if (op==1) {
      m[0][1] = 1;
      m[1][0] = -1;
      m[2][2] = 1;
    } else if (op==2) {
      m[0][1] = -1;
      m[1][0] = 1;
      m[2][2] = 1;
    } else {
      cin >> p;
      if (op==3) {
        m[0][0] = -1;
        m[0][2] = 2*p;
        m[1][1] = 1;
        m[2][2] = 1;
      } else {
        m[0][0] = 1;
        m[1][1] = -1;
        m[1][2] = 2*p;
        m[2][2] = 1;
      }
    }
    mat[i+1] = m*mat[i];
  }
  cin >> Q;
  rep(_,Q) {
    int A,B;
    cin >> A >> B;
    B--;
    Matrix<ll> x(3,1);
    x[0][0] = X[B];
    x[1][0] = Y[B];
    x[2][0] = 1;
    Matrix<ll> res = mat[A]*x;
    print(res[0][0] << " " << res[1][0]);
  }
  return 0;
}
