//#include "Segment.h"
#include "Trapezoid.h"

//#############################################################################
//					“Об’єктно-орієнтоване програмування”					   
//												
//		Екзаменаційне завдання для студентів 2 курсу факультету інформатики
//		Національного університету “Києво-Могилянська академія”
//		Весняний триместр 2021-22 навчальний рік
//
//	1. Визначити економний клас трапецій Trapezoid за чотирма вершинами.
//	2. Реалізувати селектори і модифікатори вершин трапеції.
//	3. Знайти відрізки сторін трапеції.
//	4. Підрахувати площу і периметр трапеції.
//	Реалізувати оператори порівняння трапецій за їх площами.
// 
// project : Trapezoid, developed by Ruslan Zymovets (SE-1)
//#############################################################################

	size_t Trapezoid::_freeId = 0;

    Trapezoid::Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d)
		:	_id(++_freeId),
			_a(a), _b(b), _c(c), _d(d), 
			_ab(nullptr), _bc(nullptr),
			_cd(nullptr), _ad(nullptr)
    {
		if (!check_for_correctness(vertexA(), vertexB(), vertexC(), vertexD()))
			throw BadTrapezoid("The set of points does not form a trapezoid.");

#ifndef NDEBUG
		cout << "Trapezoid (const Point&...) : id" << _id << endl;
#endif // !NDEBUG
		return;
    }
	Trapezoid::Trapezoid(const Trapezoid& t)
		: _id(++_freeId),
		_a(t._a), _b(t._b), _c(t._c), _d(t._d),
		_ab(nullptr), _bc(nullptr),
		_cd(nullptr), _ad(nullptr)
	{
#ifndef NDEBUG
		cout << "Trapezoid (const Trapezoid&) : id" << _id << endl;
#endif // !NDEBUG
		return;
	}

	Trapezoid::~Trapezoid()
	{
#ifndef NDEBUG
		cout << "~Trapezoid() : id" << _id << endl;
#endif // !NDEBUG
		delete _ab; _ab = nullptr;
		delete _bc; _bc = nullptr;
		delete _cd; _cd = nullptr;
		delete _ad; _ad = nullptr;
		return;
	}

	const Trapezoid::Segment& Trapezoid::ab()	const
	{
		if (nullptr == _ab)
		{
			_ab = new Segment(_a, _b);
		}

		return *_ab;
	}

	const Trapezoid::Segment& Trapezoid::bc()	const
	{
		if (nullptr == _bc)
		{
			_bc = new Segment(_b, _c);
		}

		return *_bc;
	}

	const Trapezoid::Segment& Trapezoid::cd()	const
	{
		if (nullptr == _cd)
		{
			_cd = new Segment(_c, _d);
		}

		return *_cd;
	}

	const Trapezoid::Segment& Trapezoid::ad()	const
	{
		if (nullptr == _ad)
		{
			_ad = new Segment(_a, _d);
		}

		return *_ad;
	}

	double Trapezoid::ab_length()	const
	{
		return ab().length();
	}

	double Trapezoid::bc_length()	const
	{
		return bc().length();
	}

	double Trapezoid::cd_length()	const
	{
		return cd().length();
	}

	double Trapezoid::ad_length()	const
	{
		return ad().length();
	}

	double Trapezoid::height() const
	{
		return ad().distance(vertexB());
	}
