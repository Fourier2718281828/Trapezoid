#ifndef _POINT_H_
#define	_POINT_H_
#include <iostream>
#include <cmath>
using std::ostream;

//#############################################################################
//					��ᒺ����-��������� ��������������					   
//												
//		������������� �������� ��� �������� 2 ����� ���������� �����������
//		������������� ����������� �����-����������� ��������
//		�������� �������� 2021-22 ���������� ��
//
//	1. ��������� ��������� ���� �������� Trapezoid �� ������� ���������.
//	2. ���������� ��������� � ������������ ������ ��������.
//	3. ������ ������ ����� ��������.
//	4. ϳ��������� ����� � �������� ��������.
//	���������� ��������� ��������� �������� �� �� �������.
// 
// project : Trapezoid, developed by Ruslan Zymovets (SE-1)
//#############################################################################


	class Point
	{
	private:
		static int _freeID;
		const int _pointID;
		double _x;
		double _y;
	public:
		Point(const double x, const double y);
		Point(const Point&);
		~Point();
		inline Point& operator=(const Point&);
		inline Point& operator+=(const Point& p);
		inline double& x();
		inline double& y();
		inline double x() const;
		inline double y() const;
		inline int getID() const;
		inline double distance(const Point& p) const;
	};

	inline ostream& operator<<(ostream& o, const Point& p)
	{
		return o << '(' << p.x() << ", " << p.y() << ')';//<< '{' << "pid" << p.getID() << '}';
	}

	inline const Point operator+(const Point& u, const Point& v)
	{
		return Point(u.x() + v.x(), u.y() + v.y());
	}

	inline bool operator==(const Point& u, const Point& v)
	{
		return u.x() == v.x() && u.y() == v.y();
	}

	inline bool operator!=(const Point& u, const Point& v)
	{
		return !(u == v);
	}

	inline Point& Point::operator=(const Point& p)
	{
		_x = p._x;
		_y = p._y;

		return *this;
	}

	inline Point& Point::operator+=(const Point& p)
	{
		_x += p._x;
		_y += p._y;

		return *this;
	}

	inline double& Point::x()
	{
		return _x;
	}

	inline double& Point::y()
	{
		return _y;
	}

	inline double Point::x() const
	{
		return _x; 
	}

	inline double Point::y() const
	{
		return _y;
	}

	inline int Point::getID() const
	{
		return _pointID;
	}
	inline double Point::distance(const Point& p) const
	{
		return sqrt((_x - p._x) * (_x - p._x) + (_y - p._y) * (_y - p._y));
	}

#endif // !_POINT_H_