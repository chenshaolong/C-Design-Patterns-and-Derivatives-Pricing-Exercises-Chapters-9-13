// C++ Design Patterns and Derivatives Pricing, Exercise 9.2, page 174

#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
public:
	Function() {}; // optional
	virtual ~Function() ;
	//virtual ~Function() = 0; // pure virtual destructor must provide its definition 
	
	virtual double operator()(double x) const = 0; // pure virtual method doesn't have to be defined except pure virtual destructor
};

class Linear : public Function
{
public:
	Linear() {}; // optional
	~Linear() {}; // optional

	virtual double operator()(double x) const;
};

class Exponential : public Function
{
public:
	Exponential() {};
	~Exponential() {};

	virtual double operator()(double x) const;
};

class Logarithmic : public Function
{
public:
	Logarithmic() {};
	~Logarithmic() {};

	virtual double operator()(double x) const;
};


class NormalDensity : public Function
{
public:
	NormalDensity() {};
	~NormalDensity() {};

	virtual double operator()(double x) const;
};

#endif