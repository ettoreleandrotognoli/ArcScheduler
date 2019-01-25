
#ifndef __CIAG__BLUEFARY__MATH__RATIONAL__
#define __CIAG__BLUEFARY__MATH__RATIONAL__

#include "math.h"

namespace ciag {
    namespace bluefairy{
        namespace math {

            template<typename T>
            class Rational {
            public:
                Rational(const T& numerator);
                Rational(const T& numerator, const T& denominator);
                inline const T& getNumerator() const;
                inline const T& getDenominator() const;
                Rational& bitReduce();
                Rational& reduce();
            protected:
                T numerator;
                T denominator;
            };

            template<typename T>
            Rational<T>::Rational(const T& numerator) :
                numerator(numerator), denominator(static_cast<const T&>(1))  {

            }

            template<typename T>
            Rational<T>::Rational(const T& numerator, const T& denominator) :
                numerator(numerator), denominator(denominator) {

            }

            template<typename T>
            const T& Rational<T>::getNumerator() const {
                return this->numerator;
            }

            template<typename T>
            const T& Rational<T>::getDenominator() const {
                return this->denominator;
            }

            template<typename T>
            Rational<T>& Rational<T>::bitReduce() {
                while(((this->numerator | this->denominator) & 0b1) == 0) {
                    this->numerator = this->numerator >> 1;
                    this->denominator = this->denominator >> 1;
                }
                return *this;
            }

            template<typename T>
            Rational<T>& Rational<T>::reduce() {
               const T divisor = greatestCommonDivisor(this->numerator, this->denominator);
               this->numerator /= divisor;
               this->denominator /= divisor;
               return *this;
            }

        }
    }
}

using ciag::bluefairy::math::Rational;


template<typename T>
inline const Rational<T> operator*(const Rational<T>& a, const Rational<T>& b) {
    return Rational<T>(a.getNumerator() * b.getNumerator(), a.getDenominator() * b.getDenominator());
}


template<typename T>
inline const Rational<T> operator/(const Rational<T>& a, const Rational<T>& b) {
    return Rational<T>(a.getNumerator() * b.getDenominator(), a.getDenominator() * b.getNumerator());
}

template<typename T>
inline const Rational<T> operator+(const Rational<T>& a, const Rational<T>& b) {
    
}

template<typename T>
inline const Rational<T> operator-(const Rational<T>& a, const Rational<T>& b) {
    
}

#endif