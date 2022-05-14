#include "Trapezoid.h"
#include <iostream>
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


int main(void)
{
	{
		cout << "##########################################################################" << endl;
		cout << "In this project class Trapezoid represents trapezoids with bases parallel" << endl;
		cout << "to horizontal axis. Besides, the projection of one of the bases on the" << endl;
		cout << "horizontal axis is a subset of another's projection." << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Let's create a trapezoid of point set : (0, 0), (1, 2), (3, 2), (4, 0) :" << endl;
		Trapezoid t(Point(0, 0), Point(1, 2), Point(3, 2), Point(4, 0));

		cout << "operator<< : " << t << endl;
		cout << "We should notice that no edges have been constructed so far." << endl << endl;
		cout << "Vertex selectors : " << t.vertexA() << ", " << t.vertexB()
			<< ", " << t.vertexC() << ", " << t.vertexD() << endl;
		cout << "Modifying vertex A = (0, 2): " << endl;
		try
		{
			t.set_vertexA(Point(0, 2));
		}
		catch (const Trapezoid::BadTrapezoid& bt)
		{
			bt.print_diagnosis(cout);
		}
		cout << "Let's modify it in correct way :" << endl;
		cout << "B := (0, 2)" << endl;
		t.set_vertexB(Point(0, 2));
		cout << "Our trapezoid : " << t << endl << endl;

		cout << "Now let's see edge ab : " << endl; cout << t.ab() << endl;
		cout << "It got constructed only when we called the selector." << endl;
		cout << "If we modify vertex B := (1, 2) : " << endl;
		t.set_vertexB(Point(1, 2));
		cout << "The edge ab will be modified too : " << t.ab() << endl;
		cout << "And it was not constructed again." << endl << endl;
		cout << "All other edges : " << endl;
		cout << t.bc() << endl;
		cout << t.cd() << endl;
		cout << t.ad() << endl;
		cout << "Now calculate area and perimeter of our trapezoid : " << endl << t << endl;
		cout << "area  = " << t.area() << endl;
		cout << "perim = " << t.perimeter() << endl;
		cout << "If modify a vertex, area and perimeter change too : \nb := (2, 2)" << endl;
		t.set_vertexB(Point(2, 2));
		cout << "area  = " << t.area() << endl;
		cout << "perim = " << t.perimeter() << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	{
		cout << "Now let's construct two trapezoids and compare them by area : " << endl;
		Trapezoid	t1(Point(0, 0), Point(1, 2), Point(3, 2), Point(4, 0)), 
					t2(Point(0, 0), Point(0, 2), Point(3, 2), Point(4, 0));
		cout << "t1 : " << t1 << endl;
		cout << "t2 : " << t2 << endl << endl;
		cout << "area_t1 = " << t1.area() << endl;
		cout << "area_t2 = " << t2.area() << endl;

		cout << std::boolalpha << "t1 < t2 = " << (t1 < t2) << endl;
		cout << "t1 <= t2 = " << (t1 <= t2) << endl;
		cout << "t1 > t2 = " << (t1 > t2) << endl;
		cout << "t1 >= t2 = " << (t1 >= t2) << endl;
		cout << "t1 == t2 = " << (t1 == t2) << endl;
		cout << "t1 != t2 = " << (t1 != t2) << endl;
	}
	cout << "--------------------------------------------------------------------------" << endl;
	{
		try
		{
			cout << "If we try to construct trapezoid of incorrect set of points :" << endl;
			cout << Point(0, 0) << ", " << Point(0, 0) << ", " << Point(0, 0) << ", " << Point(4, 0) << endl;
			cout << "Exception : " << endl;
			Trapezoid t(Point(0, 0), Point(0, 0), Point(0, 0), Point(4, 0));
		}
		catch (const Trapezoid::BadTrapezoid& bt)
		{
			bt.print_diagnosis(cout);
		}
	}
	cout << "--------------------------------------------------------------------------" << endl;


	return 0;
}