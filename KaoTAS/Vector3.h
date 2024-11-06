#ifndef VECTOR3_H
#define VECTOR3_H

template <typename T>
struct Vector3
{
    explicit Vector3(T x, T y, T z) : x(x), y(y), z(z) { }
    Vector3() = default;

    T x = {}; 
    T y = {};
    T z = {};
};


#endif // !VECTOR3_H

