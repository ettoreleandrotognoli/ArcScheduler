#ifndef __CIAG__BLUEFARY__MATH__
#define __CIAG__BLUEFARY__MATH__

namespace ciag {
    namespace bluefairy{
        namespace math {

            template<typename T>
            inline const T max(const T& a, const T& b) {
                return a > b ? a : b;
            }

            template<typename T>
            inline const T min(const T& a, const T& b) {
                return a < b ? a : b;
            }

            template<typename T>
            inline const T abs(const T& value) {
                return value > 0 ? value : -value;
            }

            template<typename T>
            const T greatestCommonDivisor(const T& a, const T& b) {
                for(T div = min(abs(a),abs(b)); div > 1 ; div -= 1) {
                    if(a % div == 0 && b % div == 0) {
                        return div;
                    }
                }
                return 1;
            }
        }
    }
}

#endif