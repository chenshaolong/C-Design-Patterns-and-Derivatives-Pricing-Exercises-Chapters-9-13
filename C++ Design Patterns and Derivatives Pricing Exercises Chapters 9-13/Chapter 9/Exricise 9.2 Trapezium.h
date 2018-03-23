// C++ Design Patterns and Derivatives Pricing, Exercise 9.2, page 174

template<class T>
double Trapezium(double Low, double High, unsigned long Steps, const T& TheFunction)
{
	double delta = (High - Low) / Steps;
	double area = (TheFunction(Low) + TheFunction(High)) / 2;
	for (unsigned long i = 1; i < Steps; i++)
		area += TheFunction(Low + i * delta);

	area *= delta;
	return area;
}