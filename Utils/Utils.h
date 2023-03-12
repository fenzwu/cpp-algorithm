#ifndef IGMDK_UTILS_H
#define IGMDK_UTILS_H
#include <new>         //for new
#include <cassert>     //for assert
#include <limits>      //for numeric limits
#include <type_traits> //for is_trivially_copyable and others
#include <utility>     //for pair
#include "Debug.h"
using namespace std;

namespace igmdk
{
    struct EMPTY
    {
    };

    template <typename ITEM>
    ITEM *rawMemory(int n = 1)
    {
        return (ITEM *)::operator new(sizeof(ITEM) * n);
    }
    void rawDelete(void *array) { ::operator delete(array); }
    template <typename ITEM>
    void rawDestruct(ITEM *array, int size)
    {
        for (int i = 0; i < size; ++i)
            array[i].~ITEM();
        rawDelete(array);
    }

    template <typename T>
    struct ArithmeticType
    {
        friend T operator+(T const &a, T const &b)
        {
            T result(a);
            return result += b;
        }
        friend T operator-(T const &a, T const &b)
        {
            T result(a);
            return result -= b;
        }
        friend T operator*(T const &a, T const &b)
        {
            T result(a);
            return result *= b;
        }
        friend T operator<<(T const &a, int shift)
        {
            T result(a);
            return result <<= shift;
        }
        friend T operator>>(T const &a, int shift)
        {
            T result(a);
            return result >>= shift;
        }
        friend T operator%(T const &a, T const &b)
        {
            T result(a);
            return result %= b;
        }
        friend T operator/(T const &a, T const &b)
        {
            T result(a);
            return result /= b;
        }
    };

}
#endif