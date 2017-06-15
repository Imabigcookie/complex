#include "сomplex_t.hpp"
complex_t::complex_t() : real_(0.0), img_(0.0)
{}
complex_t::complex_t(double x, double y) : real_(x), img_(y)
{}
complex_t::complex_t(const complex_t&cop)
{
	real_ = cop.real_;
	img_ = cop.img_;
}
double complex_t::a() const
{
	return real_;
}

double complex_t::b() const
{
	return real_;
}
bool complex_t::operator == (const complex_t& c2) const
{
	if ((real_ == c2.real_) && (img_ == c2.img_))
		return true;
	else
		return false;
}
complex_t& complex_t::operator = (const complex_t& result)
{
	if (this != &result) 
	{
	real_ = result.real_;
	img_ = result.img_;
	return *this;
	}

}
istream& operator >> (istream&cin, complex_t& result) 
{
	cout << "real complex part:" << endl;
	cin >> result.real_;
	cout << "imaginary complex part:" << endl;
	cin >> result.img_;
	cout << endl;
	return cin;
}

ostream& operator << (ostream&cout,const complex_t& result) 
{
	if (result.img_ < 0)
	{
		cout << result.real_ << result.img_ << "i" << endl;
	}
	else
		cout << result.real_ << "+" << result.img_ << "i" << endl;
	return cout;
}

complex_t complex_t::operator * (const complex_t& c2) const
{
	return complex_t(real_*c2.real_ - img_*c2.img_, real_*c2.img_ + c2.real_*img_);
}

complex_t complex_t::operator / (const complex_t& c2) const
{
	return complex_t((real_*c2.real_ + img_*c2.img_) / (c2.real_*c2.real_ + c2.img_*c2.img_), (c2.real_*img_ - real_*c2.img_) / (c2.real_*c2.real_ + c2.img_*c2.img_));
}

complex_t& complex_t::operator += (const complex_t& c2) 
{
	real_ += c2.real_;
	img_ += c2.img_;
	return *this;
}

complex_t& complex_t::operator -= (const complex_t& c2) 
{
	real_ -= c2.real_;
	img_ -= c2.img_;
	return *this;
}
complex_t& complex_t::operator /= (const complex_t& c2) 
{
	double a = (real_*c2.real_ + img_*c2.img_) / (c2.real_*c2.real_ + c2.img_*c2.img_);
	img_ = (c2.real_*img_ - real_*c2.img_) / (c2.real_*c2.real_ + c2.img_*c2.img_);
	real_ = a;
	return *this;
}

complex_t& complex_t::operator *= (const complex_t& c2) 
{
	double a = real_*c2.real_ - img_*c2.img_;
	img_ = real_*c2.img_ + c2.real_*img_;
	real_ = a;
	return *this;
}
