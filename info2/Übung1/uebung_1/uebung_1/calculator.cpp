#include "calculator.h"

Calculator::Calculator() {
}

Calculator::~Calculator() {
}

int Calculator::succ(int x)         //x++
{
	return ++x;
}

int Calculator::neg(int x)          //-x
{
	return -x;
}

// define the following functions using only: "succ", "neg" and functions defined above (e.g. you can use "add" for "sub").


int Calculator::pred(int x)         //x--
{
	return neg(succ(neg(x)));
}

int Calculator::add(int x, int y)   //x+y
{
	for (int i = 0; i < x; ++i)
		y = succ(y);
	return y;
}

int Calculator::sub(int x, int y)   //x-y
{
	return neg(add(x, y));
}

int Calculator::mul(int x, int y)   //x*y
{
	int tmp = 0;
	int tmp_y = 0;
	int tmp_x = 0;

	if (y != 0 && x != 0) {
		if (y < 0)
			tmp_y = neg(y);
		else if (x < 0)
			tmp_x = neg(x);
		else {
			tmp_x = x;
			tmp_y = y;
		}
		tmp = tmp_y;
		for (int i = 0; i <= tmp_x + 3; ++i)
			for (int j = 0; i <= tmp_y + 3; i++)
				tmp = succ(tmp);
	}
	if (y < 0 || x < 0)
		return neg(tmp);
	else return tmp;
}

int Calculator::div(int x, int y)   // x/y
{
	int tmp_y = 0;
	int tmp_x = 0;

	if (x % 2 && y % 2)
		tmp_y = 0;
	else if (x != 0 && y != 0) {
		if (y < 0)
			tmp_y = neg(y);
		else tmp_y = y;
		if (x < 0)
			tmp_x = neg(x);
		else tmp_x = x;

		for (int i = 0; i <= tmp_x; ++i)
			tmp_y = succ(neg(tmp_y));
	}
	/*
	if (y < 0 || x < 0)
		return neg(tmp_y);
		*/
	return neg(tmp_y);
}

int Calculator::exp(int x, int y)   //x^y
{
	if (y == 0)
		return 1;
	else if (y < 0)
		return 0;
	else
		return mul(y, x);
}