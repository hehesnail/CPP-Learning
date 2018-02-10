#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;

complex& __doapl(complex* ths, const complex& rhs);
complex& __doapmi(complex* ths, const complex& rhs);

class complex
{
public:
	complex(double r = 0, double i = 0): re(r), im(i){}
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	double real() const {return re;}
	double imag() const {return im;}

private:
	double re, im;

	friend complex& __doapl(complex*, const complex&);
	friend complex& __doapmi(complex*, const complex&);
};

inline complex& complex::operator += (const complex& r)
{
	return __doapl(this, r);
}

inline complex& complex::operator -=(const complex& r)
{
	return __doapmi(this, r);
}

complex& __doapl(complex* ths, const complex& rhs)
{
	ths->re += rhs.re;
	ths->im += rhs.im;
	
	return *ths;
}

complex& __doapmi(complex* ths, const complex& rhs)
{
	ths->re -= rhs.re;
	ths->im -= rhs.im;

	return *ths;
}

inline double real(const complex& x)
{
	return x.real();
}

inline double imag(const complex& x)
{
	return x.imag();
}

inline complex operator + (const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator + (const complex& x, const double& y)
{
	return complex(real(x) + y, imag(x));
}

inline complex operator + (const double& x, const complex& y)
{
	return complex(x + real(y), imag(y));
}

inline complex operator + (const complex&  x)
{
	return x;
}

inline complex operator - (const complex& x)
{
	return complex(-real(x), -imag(x));
}

inline bool operator == (const complex& x, const complex& y)
{
	return (real(x) == real(y)) && (imag(x) == imag(y)); 
}

#endif