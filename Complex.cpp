#include "Complex.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

Complex::Complex(std::string& input) //string constructor NEEDS REVISION
{
	std::istringstream ss1(input);
	std::string numHolder;
	std::string firstChunk;

	if (!ss1) //if stringstream read fails
	{
		ss1.clear(); //clear
		throw std::logic_error("ERROR!\n"); //throw error
	}
	else {
		while (!ss1.eof()) //while ss1 is not EOF
		{
			getline(ss1, firstChunk, '+'); //gets first part of complex number until the + sign and stores in ss1
			
			std::istringstream ss2(firstChunk); //creating second stringstream

			if (!ss2) //if ss2 fails
			{
				ss2.clear();
				throw std::logic_error("ERROR!\n"); //throws exception
			}
			else 
			{
				while (ss2) //till end of ss2
				{
					while (ss2.peek() != '-') //while next character is not - sign
					{
						ss2 >> numHolder; //store characters into numHolder string
					}

					if (!ss2.eof()) //if ss2 is not at the end
					{
						numHolder.push_back(ss2.get()); //push back character to numHolder
					}

					if (numHolder.find('i') == std::string::npos) //if the character is real
					{
						real += std::stod(numHolder); //converts numHolder to double and adds to real
					}
					else if (numHolder.find('i') && (numHolder.size() == 1)) //if character is imaginary
					{
						++imag; //increments imag
					}
					else if (numHolder.find("-i")) //if it finds -i 
					{
						--imag; //decrements imag;
					}
					else //if some number and i
					{
						imag += std::stod(numHolder); //converts numHolder to double and adds to imag
					}
				}
			}
		}
	}
}

double& Complex::operator[](const std::string& str) 
{
	if (str == "real") //if string holds real
	{
		double& refreal = real; //create reference to real
		return refreal; //return reference
	}
	else if (str == "imag")
	{
		double& refimag = imag;
		return refimag; //return reference to imag
	}
	else
	{
		throw std::out_of_range("invalid index: " + str); //throws exception otherwise
	}
}

const double Complex::operator[](const std::string& str) const //overloaded on const version
{
	if (str == "real") 
	{
		return real; //returns member variable real
	}
	else if (str == "imag") 
	{
		return imag; //returns imag
	}
	else 
	{
		throw std::out_of_range("invalid index: " + str);
	}
}

std::ostream& operator<<(std::ostream& out, const Complex& num) 
{
	if (num["imag"] == 1) //if imaginary number is 1
	{
		out << num["real"] << "i"; //returns real number and i
	}
	else if (num["imag"] == -1) //if imag is -1
	{
		out << num["real"] << "-i"; //returns real and -i
	}
	else if (num["imag"] > 0) //if imag > 0
	{
		out << num["real"] << "+" << num["imag"] << "i"; //returns real, imag, i
	}
	else if(num["imag"] < 0)
	{
		out << num["real"] << num["imag"] << "i";
	}

	if (num["real"] == 0) 
	{
		out << "0"; //display empty constructor
	}

	return out;
}

std::istream& operator>>(std::istream& in, Complex& num) 
{
	in >> num.real; //puts input into real
	std::cout << " ";
	in >> num.imag; //puts input into imag

	if (in.fail()) //if istream in fails throw exception
	{
		throw std::runtime_error("read error");
	}

	return in;
}

//conversion to string operator
Complex::operator std::string() const
{
	std::ostringstream oss; //creates ostringstream
	oss << *this; //outs to *this
	return oss.str(); //returns string version of oss
}
