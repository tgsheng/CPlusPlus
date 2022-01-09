#pragma once

#include <iostream>

template <typename T> class complex {
public:
  // Default constructor
  constexpr complex(const T &r = T(), const T &i = T()) : _real(r), _imag(i) {}

  // Let the compiler synthesis the copy constructor
  constexpr complex(const complex &) = default;

  // Converting constructor
  template <typename U>
  constexpr complex(const complex<U> &c) : _real(c.real()), _imag(c.imag()) {}

  // getters, return values, not references
  constexpr T real() const { return _real; }
  constexpr T imag() const { return _imag; }

  // setters
  constexpr void real(const T &val) { _real = val; }
  constexpr void imag(const T &val) { _imag = val; }

  constexpr complex &operator=(const T &);
  constexpr complex &operator+=(const T &val) {
    _real += val;
    return *this;
  }
  constexpr complex &operator-=(const T &val) {
    _real -= val;
    return *this;
  }
  constexpr complex &operator*=(const T &);
  constexpr complex &operator/=(const T &);

  // Let the compiler synthesis the copy assignment operator
  constexpr complex &operator=(const complex &) = default;

  template <typename U> constexpr complex<T> &operator=(const complex<U> &);
  template <typename U> constexpr complex<T> &operator+=(const complex<U> &);
  template <typename U> constexpr complex<T> &operator-=(const complex<U> &);
  template <typename U> constexpr complex<T> &operator*=(const complex<U> &);
  template <typename U> constexpr complex<T> &operator/=(const complex<U> &);

private:
  T _real;
  T _imag;
};

/* A function declared constexpr is implicitly an inline function. */
template <typename T>
constexpr complex<T> &complex<T>::operator=(const T &val) {
  _real = val;
  _imag = T();
  return *this;
}

template <typename T>
constexpr complex<T> &complex<T>::operator*=(const T &val) {
  _real *= val;
  _imag *= val;
  return *this;
}

template <typename T>
constexpr complex<T> &complex<T>::operator/=(const T &val) {
  _real /= val;
  _imag /= val;
  return *this;
}

template <typename T>
template <typename U>
constexpr complex<T> &complex<T>::operator=(const complex<U> &c) {
  _real = c.real();
  _imag = c.imag();
  return *this;
}

template <typename T>
template <typename U>
constexpr complex<T> &complex<T>::operator+=(const complex<U> &c) {
  _real += c.real();
  _imag += c.imag();
  return *this;
}

template <typename T>
template <typename U>
constexpr complex<T> &complex<T>::operator-=(const complex<U> &c) {
  _real -= c.real();
  _imag -= c.imag();
  return *this;
}

template <typename T>
template <typename U>
constexpr complex<T> &complex<T>::operator*=(const complex<U> &c) {
  const T r = _real * c.real() - _imag * c.imag();
  _imag = _real * c.imag() + _imag * c.real();
  _real = r;
  return *this;
}

template <typename T>
template <typename U>
constexpr complex<T> &complex<T>::operator/=(const complex<U> &c) {
  const T r = _real * c.real() + _imag * c.imag();
  const T n = c.real() * c.real() + c.imag() * c.imag();
  _imag = (_imag * c.real() - _real * c.imag()) / n;
  _real = r / n;
  return *this;
}

/******************* non-member functions *******************/

template <typename T>
inline constexpr complex<T> operator+(const complex<T> &x,
                                      const complex<T> &y) {
  complex<T> r = x;
  r += y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator+(const complex<T> &x, const T &y) {
  complex<T> r = x;
  r += y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator+(const T &x, const complex<T> &y) {
  complex<T> r = y;
  r += x;
  return r;
}

template <typename T>
inline constexpr complex<T> operator-(const complex<T> &x,
                                      const complex<T> &y) {
  complex<T> r = x;
  r -= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator-(const complex<T> &x, const T &y) {
  complex<T> r = x;
  r -= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator-(const T &x, const complex<T> &y) {
  complex<T> r = -y;
  r += x;
  return r;
}

template <typename T>
inline constexpr complex<T> operator*(const complex<T> &x,
                                      const complex<T> &y) {
  complex<T> r = x;
  r *= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator*(const complex<T> &x, const T &y) {
  complex<T> r = x;
  r *= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator*(const T &x, const complex<T> &y) {
  complex<T> r = y;
  r *= x;
  return r;
}

template <typename T>
inline constexpr complex<T> operator/(const complex<T> &x,
                                      const complex<T> &y) {
  complex<T> r = x;
  r /= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator/(const complex<T> &x, const T &y) {
  complex<T> r = x;
  r /= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator/(const T &x, const complex<T> &y) {
  complex<T> r = x;
  r /= y;
  return r;
}

template <typename T>
inline constexpr complex<T> operator+(const complex<T> &x) {
  return x;
}

template <typename T>
inline constexpr complex<T> operator-(const complex<T> &x) {
  return complex<T>(-x.real(), -x.imag());
}

template <typename T>
inline constexpr bool operator==(const complex<T> &x, const complex<T> &y) {
  return x.real() == y.real() && x.imag() == y.imag();
}

template <typename T>
inline constexpr bool operator==(const complex<T> &x, const T &y) {
  return x.real() == y && x.imag() == T();
}

template <typename T>
inline constexpr bool operator==(const T &x, const complex<T> &y) {
  return x == y.real() && T() == y.imag();
}

template <typename T>
inline constexpr bool operator!=(const complex<T> &x, const complex<T> &y) {
  return x.real() != y.real() || x.imag() != y.imag();
}

template <typename T>
inline constexpr bool operator!=(const complex<T> &x, const T &y) {
  return x.real() != y || x.imag() != T();
}

template <typename T>
inline constexpr bool operator!=(const T &x, const complex<T> &y) {
  return x != y.real() || T() != y.imag();
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const complex<T> &c) {
  return os << '(' << c.real() << ',' << c.imag() << ')';
}