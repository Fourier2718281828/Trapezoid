#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include "Trapezoid.h"

class Trapezoid::Segment
{
private:
	static size_t _freeID;
	const size_t _myId;
	const Point& _a;
	const Point& _b;
public:
	Segment(const Point&, const Point&);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment& s) = delete;
	inline const Point& start()				const;
	inline const Point& end()				const;
	inline const double startX()			const;
	inline const double startY()			const;
	inline const double endX()				const;
	inline const double endY()				const;
	inline double length()					const;
	inline double distance(const Point& p)	const;
	inline int getID()						const;
};

inline ostream& operator<<(ostream& o, const Trapezoid::Segment& s)
{
	return o << '[' << s.start() << "; " << s.end() << "] {id" << s.getID() << '}';
}

inline const Point& Trapezoid::Segment::start() const
{
	return _a;
}

inline const Point& Trapezoid::Segment::end() const
{
	return _b;
}

inline const double Trapezoid::Segment::startX() const
{
	return start().x();
}

inline const double Trapezoid::Segment::startY() const
{
	return start().y();
}

inline const double Trapezoid::Segment::endX() const
{
	return end().x();
}

inline const double Trapezoid::Segment::endY() const
{
	return end().y();
}

inline double Trapezoid::Segment::length() const
{
	return start().distance(end());
}

inline double Trapezoid::Segment::distance(const Point& p) const
{
	double a11 = p.x() - startX();
	double a12 = p.y() - startY();
	double a21 = endX() - startX();
	double a22 = endY() - startY();
	double det = a11 * a22 - a12 * a21;
	return fabs(det) / length();
}

inline int Trapezoid::Segment::getID() const
{
	return _myId;
}

#endif // !_SEGMENT_H_