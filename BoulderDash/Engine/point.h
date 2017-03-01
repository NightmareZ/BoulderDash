#ifndef POINT_H
#define POINT_H

namespace Engine
{
	template<typename T> struct Point
	{
		T x, y;
		Point(T x_, T y_): x(x_), y(y_) { }
		Point(): x(0), y(0) { }
	};
}

#endif