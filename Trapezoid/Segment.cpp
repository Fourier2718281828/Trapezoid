#include "Segment.h"
size_t Trapezoid::Segment::_freeID = 0;

Trapezoid::Segment::Segment(const Point& start, const Point& end)
	: _myId(++_freeID), _a(start), _b(end)
{
#ifndef NDEBUG
	cout << "--Segment(const Point& start, const Point& end) : id" << _myId << endl;
#endif // !NDEBUG

	return;
}

Trapezoid::Segment::Segment(const Trapezoid::Segment& s)
	: _myId(++_freeID), _a(s.start()), _b(s.end())
{
#ifndef NDEBUG
	cout << "--Segment(const Segment& s) : id" << _myId << endl;
#endif // !NDEBUG

	return;
}

Trapezoid::Segment::~Segment()
{
#ifndef NDEBUG
	cout << "-- ~Segment() : id" << _myId << endl;
#endif // !NDEBUG
	return;
}