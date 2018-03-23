// C++ Design Patterns and Derivatives Pricing, Listing 9.5, page 168

template<class T, double (T::*Value)(double) const, double  (T::*Derivative)(double) const>
double NewtonRaphson(double Target, double Start, double Tolerance, const T& TheObject)
{
	double y = (TheObject.*Value)(Start);
	double x = Start;

	const unsigned long limit = 100;
	unsigned long i = 0;
	while (fabs(y - Target) > Tolerance && i++ < limit) {
		//std::cout << "i: " << i << std::endl;
		double d = (TheObject.*Derivative)(x);
		x += (Target - y) / d;
		y = (TheObject.*Value)(x);
	}

	return x;
}