#ifndef _TRAPEZOID_
#define _TRAPEZOID_
#include "Point.h"
using std::cout;
using std::endl;

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


	class Trapezoid
	{
	public:
		class Segment;
		class BadTrapezoid;
	private:
		static size_t	_freeId;
		const  size_t	_id;
		Point _a, _b, _c, _d;
		mutable Segment* _ab, * _bc, * _cd, * _ad;
	public:
		Trapezoid(const Point&, const Point&, const Point&, const Point&);
		Trapezoid(const Trapezoid&);
		~Trapezoid();
		inline Trapezoid& operator=(const Trapezoid&)	&;
		inline void set_vertexA(const Point&)			&;
		inline void set_vertexB(const Point&)			&;
		inline void set_vertexC(const Point&)			&;
		inline void set_vertexD(const Point&)			&;
		inline const Point& vertexA()				const;
		inline const Point& vertexB()				const;
		inline const Point& vertexC()				const;
		inline const Point& vertexD()				const;
		inline double area()						const;
		inline double perimeter()					const;
		const Segment& ab()							const;
		const Segment& bc()							const;
		const Segment& cd()							const;
		const Segment& ad()							const;
		double ab_length()							const;
		double bc_length()							const;
		double cd_length()							const;
		double ad_length()							const;
		double height()								const;
	private:
		inline bool check_for_correctness();
	};

	class Trapezoid::BadTrapezoid
	{
	private:
		const std::string _message;
	public:
		BadTrapezoid(const std::string message)
			:	_message(message)
		{}
		~BadTrapezoid() = default;
		inline void print_diagnosis(ostream& o) { o << _message << endl; }
	};

#include "Segment.h"

	inline ostream& operator<<(ostream& o, const Trapezoid& t)
	{
		return o << '['		<< t.vertexA() << ", "
							<< t.vertexB() << ", "
							<< t.vertexC() << ", "
							<< t.vertexD() << ']';
	}

	inline bool operator<(const Trapezoid& a, const Trapezoid& b)
	{
		return a.area() < b.area();
	}

	inline bool operator<=(const Trapezoid& a, const Trapezoid& b)
	{
		return !(b < a);
	}

	inline bool operator>(const Trapezoid& a, const Trapezoid& b)
	{
		return b < a;
	}

	inline bool operator>=(const Trapezoid& a, const Trapezoid& b)
	{
		return !(a < b);
	}

	inline bool operator==(const Trapezoid& a, const Trapezoid& b)
	{
		return a.area() == b.area();
	}

	inline bool operator!=(const Trapezoid& a, const Trapezoid& b)
	{
		return !(a == b);
	}

	inline Trapezoid& Trapezoid::operator=(const Trapezoid& t)&
	{
		if (this == &t)
		{
			return *this;
		}

		_a = t._a;
		_b = t._b;
		_c = t._c;
		_d = t._d;

		delete _ab; _ab = nullptr;
		delete _bc; _bc = nullptr;
		delete _cd; _cd = nullptr;
		delete _ad; _ad = nullptr;

		return *this;
	}

	inline void Trapezoid::set_vertexA(const Point& p)&
	{
		_a = p;
		if (!check_for_correctness()) 
			throw BadTrapezoid("Incorrect vertex modification.");
		return;
	}

	inline void Trapezoid::set_vertexB(const Point& p)&
	{
		_b = p;
		if (!check_for_correctness())
			throw BadTrapezoid("Incorrect vertex modification.");
		return;
	}

	inline void Trapezoid::set_vertexC(const Point& p)&
	{
		_c = p;
		if (!check_for_correctness())
			throw BadTrapezoid("Incorrect vertex modification.");
		return;
	}

	inline void Trapezoid::set_vertexD(const Point& p)&
	{
		_d = p;
		if (!check_for_correctness())
			throw BadTrapezoid("Incorrect vertex modification.");
		return;
	}

	inline const Point& Trapezoid::vertexA() const
	{
		return _a;
	}

	inline const Point& Trapezoid::vertexB() const
	{
		return _b;
	}

	inline const Point& Trapezoid::vertexC() const
	{
		return _c;
	}

	inline const Point& Trapezoid::vertexD() const
	{
		return _d;
	}

	inline double Trapezoid::area()			const
	{
		double m = fabs(bc_length() + ad_length()) / 2;
		return m * height();
	}
	inline double Trapezoid::perimeter()	const
	{
		return ab_length() + bc_length() + cd_length() + ad_length();
	}

	//inline double Trapezoid::height()		const
	//{
	//	/*double m = fabs(bc_length() - ad_length()) / 2;
	//	double x = (ab_length() * ab_length() - cd_length() * cd_length()) / (4 * m) + m;
	//	return sqrt(ab_length() * ab_length() - x * x);*/
	//	return ad().distance(vertexB());
	//}

	inline bool Trapezoid::check_for_correctness()
	{
		bool ad = vertexA().x() < vertexD().x() && vertexA().y() == vertexD().y();
		bool bc = vertexB().x() < vertexC().x() && vertexB().y() == vertexC().y();
		bool h = vertexA().y() != vertexB().y();
		bool right =	(vertexA().x() <= vertexB().x() && vertexC().x() <= vertexD().x()) 
						|| 
						(vertexB().x() <= vertexA().x() && vertexD().x() <= vertexC().x());
		return ad && bc && h && right;
	}
#endif // !_TRAPEZOID_