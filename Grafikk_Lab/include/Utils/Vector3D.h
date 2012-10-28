#ifndef VECTOR3D_H__
#define VECTOR3D_H__

#include <math.h>
#include <string>
#include <sstream>

template<class T>
class Vector3D
	{
	public:
		Vector3D()
		{
			SetVector(0,0,0);
		}

		Vector3D(T x, T y, T z)
		{
			SetVector(x, y, z);
		}

		void SetVector(T x, T y, T z)
		{
			SetX(x);
			SetY(y);
			SetZ(z);
		}

		void SetX(T x) { _x = x; }
		void SetY(T y) { _y = y; }
		void SetZ(T z) { _z = z; }

		T X() { return _x; }
		T Y() { return _y; }
		T Z() { return _z; }

		static Vector3D<T> Zero()
		{
			return Vector3D<T>(0,0,0);
		}

	private:
		T _x, _y, _z;

	public:
		Vector3D<T> operator+(Vector3D<T>& vec) const
		{
			return Vector3D<T>(
				_x + vec.X(), 
				_y + vec.Y(), 
				_z + vec.Z());
		}

		Vector3D<T>& operator+=(Vector3D<T>& other)
		{
			*this = *this + other;
			return *this;
		}

		Vector3D<T> operator+(T constant)
		{
			return Vector3D<T>(_x + constant, _y + constant, _z + constant);
		}

		Vector3D<T> operator-(Vector3D<T> other)
		{
			return Vector3D<T>(_x - other.X(), _y - other.Y(), _z - other.Z());
		}

		Vector3D<T> operator-(T constant)
		{
			return Vector3D<T>(_x - constant, _y - constant, _z - constant);
		}

		Vector3D<T> operator*(Vector3D<T> other)
		{
			return Vector3D<T>(_x * other.X(), _y * other.Y(), _z * other.Z());
		}

		Vector3D<T> operator*(T constant)
		{
			return Vector3D<T>(_x * constant, _y * constant, _z * constant);
		}

		Vector3D<T> operator/(Vector3D<T> other)
		{
			return Vector3D<T>(_x / other.X(), _y / other.Y(), _z / other.Z());
		}

		Vector3D<T> operator/(T constant)
		{
			return Vector3D<T>(_x / constant, _y / constant, _z / constant);
		}

		Vector3D<T> operator-=(Vector3D<T> other)
		{
			return Vector3D<T>(_x, _y, _z) - other;
		}

		Vector3D<T> operator*=(Vector3D<T> other)
		{
			return Vector3D<T>(_x, _y, _z) * other;
		}

		Vector3D<T> operator/=(Vector3D<T> other)
		{
			return Vector3D<T>(_x, _y, _z) / other;
		}

		bool operator==(Vector3D other)
		{
			return other.X() == _x && other.Y() == _y && other.Z() == _z;
		}

		bool operator==(T constant)
		{
			return constant == _x && constant == _y && constant == _z;
		}

		bool operator!=(Vector3D other)
		{
			return !(Vector3D(_x, _y,_z) == other);
		}

		bool operator!=(T constant)
		{
			return !(Vector3D(_x, _y,_z) == constant);
		}
	};

#endif