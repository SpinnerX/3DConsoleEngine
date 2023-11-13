#pragma once
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>


// Generic 2D Vector
template<typename T>
struct Vector2{
    Vector2<T>() = default;
    Vector2<T>(T _x, T _y) : x(_x), y(_y){ }
    Vector2<T>(const Vector2<T>& other) : x(other.y), y(other.y) {}

    T magnitude() const {
        return T(std::sqrt(x*x + y * y));
    }

    T magnitude2() const {
        return static_cast<T>(std::sqrt(std::pow(x, y) + std::pow(y,2)));
    }

    Vector2<T> normalize() const {
        T r = 1 / magnitude();
        return Vector2<T>(x * r, y * r);
    }

    Vector2<T> perp() const {
        return Vector2<T>(-y, x);
    }

    Vector2<T> floor() const {
        return Vector2<T>(std::floor(x), std::floor(y));
    }

    Vector2<T> ceil() const {
        return Vector2<T>(std::ceil(x), std::ceil(y));
    };

    Vector2<T> max(const Vector2<T>& other){
        return Vector2<T>(std::max(x, other.x), std::max(y, other.y));
    }

    Vector2<T> min(const Vector2<T>& other){
        return Vector2<T>(std::min(x, other.x), std::min(y, other.y));
    }

    Vector2<T> cart() {
        return Vector2<T>(std::cos(y) * x, std::sin(y) * x);
    }

    Vector2<T> polar(){
        return Vector2<T>(magnitude(), std::atan2(y, x));
    }

    Vector2<T> clamp(const Vector2<T>& v1, const Vector2<T>& v2){
        return this->max(v1).min(v2);
    }

    Vector2<T> lerp(const Vector2<T>& v1, const T scalar) {
        return this->operator*(T(1.0 - scalar)) + (v1 * T(scalar));
    }

    T dot(const Vector2<T> other){
        return x * other.x + y * other.y;
    }

    T crossproduct(const Vector2<T>& other){
        return x * other.x - y * other.y;
    }

    friend std::ostream& operator<<(std::ostream& outs, const Vector2<T>& v){
        outs << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")";
        return outs;
    }

    Vector2<T> operator=(const Vector2<T>& other){
        return Vector2<T>(other.x, other.y);
    }

    Vector2<T> operator+(const Vector2<T>& other) const {
        return Vector2<T>(x + other.x, y+other.y);
    }

    Vector2<T> operator-(const Vector2<T>& other) const {
        return Vector2<T>(x-other.x, y-other.y);
    }

    friend Vector2<T> operator+(const T scalar, const Vector2<T>& v){
        return Vector2<T>(v.x+scalar, v.y+scalar);
    }

    friend Vector2<T> operator*(const Vector2<T>& v, const T scalar){
        return Vector2<T>(v.x*scalar, v.y*scalar);
    }

    Vector2<T> operator*(const T& scalar){
        return Vector2<T>(x*scalar, y*scalar);
    }

    Vector2<T> operator*(const Vector2<T>& other) const {
        return Vector2<T>(x*other.x, y*other.y);
    }

    Vector2<T> operator/(const Vector2<T>& other) const {
        return Vector2<T>(x/other.y, y/other.y);
    }

    Vector2<T> operator/(const T scalar) const {
        return Vector2<T>(x/scalar, y/scalar);
    }

    Vector2<T>& operator+=(const Vector2<T>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2<T>& operator-=(const Vector2<T>& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vector2<T>& operator*=(const T& scalar){
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2<T>& operator*=(const Vector2<T>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    Vector2<T>& operator/=(const Vector2<T>& other) {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Vector2<T> operator+() const {
        return Vector2<T>(+x, +y);
    }

    Vector2<T> operator-() const {
        return Vector2<T>(-x, -y);
    }

    T x;
    T y;
};

template<typename T>
struct Vector3;

// Generic 2D Vector for doubles
template<>
struct Vector2<double>{

    Vector2<double>() : x(0.0), y(0.0) {}
    Vector2<double>(double _x, double _y) : x(_x), y(_y){ }
    Vector2<double>(const Vector2<double>& other) : x(other.y), y(other.y) {}

    double magnitude() const {
        return double(std::sqrt(x*x + y * y));
    }

    double magnitude2() const {
        return static_cast<double>(std::sqrt(std::pow(x, y) + std::pow(y,2)));
    }

    Vector2<double> normalize() const {
        double r = 1 / magnitude();
        return Vector2<double>(x * r, y * r);
    }

    Vector2<double> perp() const {
        return Vector2<double>(-y, x);
    }

    Vector2<double> floor() const {
        return Vector2<double>(std::floor(x), std::floor(y));
    }

    Vector2<double> ceil() const {
        return Vector2<double>(std::ceil(x), std::ceil(y));
    };

    Vector2<double> max(const Vector2<double>& other){
        return Vector2<double>(std::max(x, other.x), std::max(y, other.y));
    }

    Vector2<double> min(const Vector2<double>& other){
        return Vector2<double>(std::min(x, other.x), std::min(y, other.y));
    }

    Vector2<double> cart() {
        return Vector2<double>(std::cos(y) * x, std::sin(y) * x);
    }

    Vector2<double> polar(){
        return Vector2<double>(magnitude(), std::atan2(y, x));
    }

    Vector2<double> clamp(const Vector2<double>& v1, const Vector2<double>& v2){
        return this->max(v1).min(v2);
    }

    Vector2<double> lerp(const Vector2<double>& v1, const double scalar) {
        return this->operator*(double(1.0 - scalar)) + (v1 * double(scalar));
    }

    double dot(const Vector2<double> other){
        return x * other.x + y * other.y;
    }

    double crossproduct(const Vector2<double>& other){
        return x * other.x - y * other.y;
    }

    friend std::ostream& operator<<(std::ostream& outs, const Vector2<double>& v){
        outs << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")";
        return outs;
    }

    Vector2<double> operator=(const Vector2<double>& other){
        return Vector2<double>(other.x, other.y);
    }

    Vector2<double> operator+(const Vector2<double>& other) const {
        return Vector2<double>(x + other.x, y+other.y);
    }

    Vector2<double> operator-(const Vector2<double>& other) const {
        return Vector2<double>(x-other.x, y-other.y);
    }

    friend Vector2<double> operator+(const double scalar, const Vector2<double>& v){
        return Vector2<double>(v.x+scalar, v.y+scalar);
    }

    friend Vector2<double> operator*(const Vector2<double>& v, const double scalar){
        return Vector2<double>(v.x*scalar, v.y*scalar);
    }

    Vector2<double> operator*(const double& scalar){
        return Vector2<double>(x*scalar, y*scalar);
    }

    Vector2<double> operator*(const Vector2<double>& other) const {
        return Vector2<double>(x*other.x, y*other.y);
    }

    Vector2<double> operator/(const Vector2<double>& other) const {
        return Vector2<double>(x/other.y, y/other.y);
    }

    Vector2<double> operator/(const double scalar) const {
        return Vector2<double>(x/scalar, y/scalar);
    }

    Vector2<double>& operator+=(const Vector2<double>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2<double>& operator-=(const Vector2<double>& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vector2<double>& operator*=(const double& scalar){
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2<double>& operator*=(const Vector2<double>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    Vector2<double>& operator/=(const Vector2<double>& other) {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Vector2<double> operator+() const {
        return Vector2<double>(+x, +y);
    }

    Vector2<double> operator-() const {
        return Vector2<double>(-x, -y);
    }

    double x;
    double y;
};

// Generic 2D Vector for floats
template<>
struct Vector2<float>{
    Vector2<float>() : x(0.0), y(0.0) {}
    Vector2<float>(float _x, float _y) : x(_x), y(_y){ }
    Vector2<float>(const Vector2<float>& other) : x(other.y), y(other.y) {}

    float magnitude() const {
        return float(std::sqrt(x*x + y * y));
    }

    float magnitude2() const {
        return static_cast<float>(std::sqrt(std::pow(x, y) + std::pow(y,2)));
    }

    Vector2<float> normalize() const {
        float r = 1 / magnitude();
        return Vector2<float>(x * r, y * r);
    }

    Vector2<float> perp() const {
        return Vector2<float>(-y, x);
    }

    Vector2<float> floor() const {
        return Vector2<float>(std::floor(x), std::floor(y));
    }

    Vector2<float> ceil() const {
        return Vector2<float>(std::ceil(x), std::ceil(y));
    };

    Vector2<float> max(const Vector2<float>& other){
        return Vector2<float>(std::max(x, other.x), std::max(y, other.y));
    }

    Vector2<float> min(const Vector2<float>& other){
        return Vector2<float>(std::min(x, other.x), std::min(y, other.y));
    }

    Vector2<float> cart() {
        return Vector2<float>(std::cos(y) * x, std::sin(y) * x);
    }

    Vector2<float> polar(){
        return Vector2<float>(magnitude(), std::atan2(y, x));
    }

    Vector2<float> clamp(const Vector2<float>& v1, const Vector2<float>& v2){
        return this->max(v1).min(v2);
    }

    Vector2<float> lerp(const Vector2<float>& v1, const float scalar) {
        return this->operator*(float(1.0 - scalar)) + (v1 * float(scalar));
    }

    float dot(const Vector2<float> other){
        return x * other.x + y * other.y;
    }

    float crossproduct(const Vector2<float>& other){
        return x * other.x - y * other.y;
    }

    friend std::ostream& operator<<(std::ostream& outs, const Vector2<float>& v){
        outs << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")";
        return outs;
    }

    Vector2<float> operator=(const Vector2<float>& other){
        return Vector2<float>(other.x, other.y);
    }

    Vector2<float> operator+(const Vector2<float>& other) const {
        return Vector2<float>(x + other.x, y+other.y);
    }

    Vector2<float> operator-(const Vector2<float>& other) const {
        return Vector2<float>(x-other.x, y-other.y);
    }

    friend Vector2<float> operator+(const float scalar, const Vector2<float>& v){
        return Vector2<float>(v.x+scalar, v.y+scalar);
    }

    friend Vector2<float> operator*(const Vector2<float>& v, const float scalar){
        return Vector2<float>(v.x*scalar, v.y*scalar);
    }

    Vector2<float> operator*(const float& scalar){
        return Vector2<float>(x*scalar, y*scalar);
    }

    Vector2<float> operator*(const Vector2<float>& other) const {
        return Vector2<float>(x*other.x, y*other.y);
    }

    Vector2<float> operator/(const Vector2<float>& other) const {
        return Vector2<float>(x/other.y, y/other.y);
    }

    Vector2<float> operator/(const float scalar) const {
        return Vector2<float>(x/scalar, y/scalar);
    }

    Vector2<float>& operator+=(const Vector2<float>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2<float>& operator-=(const Vector2<float>& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vector2<float>& operator*=(const float& scalar){
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    Vector2<float>& operator*=(const Vector2<float>& other) {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    Vector2<float>& operator/=(const Vector2<float>& other) {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Vector2<float> operator+() const {
        return Vector2<float>(+x, +y);
    }

    Vector2<float> operator-() const {
        return Vector2<float>(-x, -y);
    }


    float x;
    float y;
};

template<>
struct Vector3<double>{
    double x;
    double y;
    double z;
};

template<>
struct Vector3<float>{

    Vector3<float>() = default;
    Vector3<float>(float _x, float _y) : x(_x), y(_y){ }
    Vector3<float>(const Vector2<float>& other) : x(other.y), y(other.y) {}

    double magnitude() const {
        return double(std::sqrt(x*x + y * y));
    }

    double magnitude2() const {
        return static_cast<double>(std::sqrt(std::pow(x, y) + std::pow(y,2)));
    }

    Vector3<float> normalize() const {
        float r = 1 / magnitude();
        return Vector3<float>(x * r, y * r);
    }

    Vector3<float> perp() const {
        return Vector3<float>(-y, x);
    }

    Vector3<float> floor() const {
        return Vector3<float>(std::floor(x), std::floor(y));
    }

    Vector3<float> ceil() const {
        return Vector3<float>(std::ceil(x), std::ceil(y));
    };

    Vector3<float> max(const Vector3<float>& other){
        return Vector3<float>(std::max(x, other.x), std::max(y, other.y));
    }

    Vector3<float> min(const Vector3<float>& other){
        return Vector3<float>(std::min(x, other.x), std::min(y, other.y));
    }

    Vector3<float> cart() {
        return Vector3<float>(std::cos(y) * x, std::sin(y) * x);
    }

    Vector3<float> polar(){
        return Vector3<float>(magnitude(), std::atan2(y, x));
    }

    Vector3<float> clamp(const Vector3<float>& v1, const Vector3<float>& v2){
        return this->max(v1).min(v2).min(v2);
    }

    float dot(const Vector3<float> other){
        return x * other.x + y * other.y + z * other.z;
    }

    float crossproduct(const Vector3<float>& other){
        return x * other.x - y * other.y; - z * other.z;
    }


    float x;
    float y;
    float z;
};



template<typename T>
using Vector2_t = Vector2<T>;
using Vector2d = Vector2<double>;
using Vector2f = Vector2<float>;

using Vector3d = Vector3<double>;
using Vector3f = Vector3<float>;