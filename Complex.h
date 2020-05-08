#ifndef COMPLEX_
#define COMPLEX_

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

class Complex
{

private: 

	double real, imag; //doubles

public:

	/**
	Default constructor with real and imag as arguments
	that are initialized to 0.
	@param _real : real number
	@param _imag : imaginary number
	*/
	constexpr Complex(double _real = 0, double _imag = 0) : real(_real), imag(_imag) {}

	/**
	String constructor that takes string ref input
	and converts it into a complex number
	@param input : string input
	*/
	Complex(std::string& input); 

	/**
	Overloaded constexpr operator += that adds 2 complex
	numbers and changes left side
	@param num : right hand side complex num
	@return *this : the left side
	*/
	constexpr Complex& operator+=(const Complex& num)
	{
		real += num.real;
		imag += num.imag;
		return *this;
	}

	/**
	Overloaded operator + that creates
	copy of Complex object
	@return copy : copy of complex num
	*/
	constexpr Complex operator+() const
	{
		Complex copy(*this); //creates copy
		copy.real = real;
		copy.imag = imag;
		return copy;
	}

	/**
	Overloaded unary prefix operator ++ that
	increments real number
	@return *this : real number
	*/
	constexpr Complex& operator++()
	{
		++real; //increments
		return *this;
	}

	/**
	Overloaded binary postfix operator ++ that
	increments real num using a copy
	@param unused : unused int
	@return copy : return incremented copy
	*/
	constexpr Complex operator++(int unused)
	{
		Complex copy(*this);
		++copy.real;
		return copy;
	}

	/**
	Overloaded operator -= to subtract two
	complex numbers and change left side
	@param num : right side
	@return *this : left side
	*/
	constexpr Complex& operator-=(const Complex& num)
	{
		real -= num.real;
		imag -= num.imag;

		return *this;
	}

	/**
	Overloaded operator - that negates real
	and imag parts using copy of complex num
	@return copy : negated copy
	*/
	constexpr Complex operator-() const
	{
		Complex copy(*this);
		copy.real = -real; //negated real
		copy.imag = -imag;
		return copy;
	}

	/**
	Overloaded unary prefix operator -- that
	decrements real part
	@return *this : decremented complex num
	*/
	constexpr Complex& operator--()
	{
		--real; //decrement
		return *this;
	}

	/**
	Overloaded binary postfix operator -- that
	decrements real part using copy of complex
	num
	@return copy : decremented copy
	*/
	constexpr Complex operator--(int unused)
	{
		Complex copy(*this);
		--real;
		return copy;
	}

	/**
	Overloaded operator *= that multiples complex
	nums and changes left side
	@param num : right side
	@return *this : left side
	*/
	constexpr Complex& operator*=(const Complex& num)
	{
		real = (real * num.real) - (imag * num.imag); //using complex number rules to multiply
		imag = (imag * num.real) + (real * num.imag);

		return *this;
	}

	/**
	Overloaded operator /= that divides 2 complex
	nums and changes left side
	@param num : right side
	@return *this : left side
	*/
	constexpr Complex& operator/=(const Complex& num)
	{
		real = ((real * num.real) + (imag * num.imag)) / ((num.real * num.real) + (num.imag * num.imag)); //divides following rules
		imag = ((imag * num.real) - (real * num.imag)) / ((num.real * num.real) + (num.imag * num.imag));

		return *this;
	}

	/**
	Overloaded unary operator~ that returns
	conjugate of complex nums
	@return Complex(real, -imag) : conjugate
	*/
	constexpr Complex operator~() const
	{
		return Complex(real, -imag); //returns conjugate
	}

	/**
	Call operator taking no arguments that sets complex
	number to 0
	@return *this : complex num set to 0
	*/
	constexpr Complex& operator()() 
	{
		real = 0;
		imag = 0;

		return *this;
	}

	/**
	Subscript operator taking string argument
	and returning either real or imag references.
	Throws exception if invalid
	@param str : real or imag input
	@return refreal, refimag : references to real/imag
	*/
	double& operator[](const std::string& str);

	/**
	Subscript operator overloaded on const
	that takes real/imag input and returns
	member variables respectively.
	Throws exception if invalid
	@param str : real/imag input
	@return real, imag : member variables
	*/
	const double operator[](const std::string& str) const;

	/**
	Overloaded friend operator >> that reads 2
	doubles and sets real and imag to them 
	of an input stream. Throws exception if istream
	fails
	@param in : istream in object
	@param num : complex num
	@return in : returns istream obj
	*/
	friend std::istream& operator>>(std::istream& in, Complex& num);

	/**
	Overloaded conversion operator that converts
	Complex object to std::string
	@return oss.str() : string version of ostringstream that is the Complex object
	*/
	operator std::string() const;

};

/**
Operator + that adds 2 complex nums
and returns sum
@param lnum : left side
@param rnum : right side
@return sum
*/
constexpr Complex operator+(Complex lnum, const Complex& rnum)
{
	return lnum += rnum;

}

/**
Operator - that calculates difference
of 2 complex nums
@param lnum : left side
@param rnum : right side
@return difference
*/
constexpr Complex operator-(Complex lnum, const Complex& rnum)
{
	return lnum -= rnum;
}

/**
Operator * calculates product of 2 complex
nums
@param lnum : left side
@param rnum : right side
@return product
*/
constexpr Complex operator*(Complex lnum, const Complex& rnum)
{
	return lnum *= rnum;
}

/**
Operator / divides 2 complex nums
@param lnum : left side
@param rnum : right side
@return quotient
*/
constexpr Complex operator/(Complex lnum, const Complex& rnum)
{
	return lnum /= rnum;
}

/**
Operator << that displays complex num
with output stream properly
@param out : ostream object
@param num : complex num
@return out : printed object
*/
std::ostream& operator<<(std::ostream& out, const Complex& num);

/**
Comparison operator < comparing left
and right side
@param left : left side complex num
@param right : ride side
@return : comparison
*/
constexpr bool operator<(const Complex& left, const Complex& right)
{
	if (left < right)
	{
		return !(left < right);
	}

	return false;
}

/**
Comparison operator == comparing left
and right side if they have the same values
@param left : left side complex num
@param right : ride side
@return : comparison
*/
constexpr bool operator==(const Complex& left, const Complex& right)
{
	return !((left < right) || (right < left));
}

/**
Comparison operator > comparing left
and right side
@param left : left side complex num
@param right : ride side
@return : comparison
*/
constexpr bool operator>(const Complex& left, const Complex& right)
{
	if (left > right) //if true
	{
		return !(left > right);
	}
	else //if false
	{
		return false;
	}
}

/**
Comparison operator <= comparing left
and right side
@param left : left side complex num
@param right : ride side
@return : comparison if true
*/
constexpr bool operator<=(const Complex& left, const Complex& right)
{
	if (left <= right) //if true
	{
		return !(left <= right);
	}
	else 
	{
		return false;
	}
}

/**
Comparison operator >= comparing left
and right side
@param left : left side complex num
@param right : ride side
@return : comparison if true
*/
constexpr bool operator>=(const Complex& left, const Complex& right)
{
	if (left >= right) //if true
	{
		return !(left >= right);
	}
	else //else
	{
		return false;
	}
}

/**
Comparison operator != comparing left
and right side for inequality
@param left : left side complex num
@param right : ride side
@return : comparison if true
*/
constexpr bool operator!=(const Complex& left, const Complex& right)
{
	if (left != right) //if does not equal
	{
		return !(left != right);
	}
	else 
	{
		return false; 
	}
}

/**
User-defined literal expression that converts
double into Complex number
@param input : long double input
@return Complex(0.0, static_cast<double>(input)) : returned Complex obj
*/
constexpr Complex operator "" _i(long double input)
{
	return Complex(0.0, static_cast<double>(input)); //static casts
}

#endif
