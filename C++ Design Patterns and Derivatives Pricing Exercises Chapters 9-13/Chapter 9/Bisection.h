// C++ Design Patterns and Derivatives Pricing, Listing 9.3, page 164

template<class T>
double Bisection(double Target, double Low, double High, double Tolerance, const T& TheFunction)
{
	double x = Low + 0.5 * (High - Low);
	double y = TheFunction(x);

	int cycle = 0;
	do {
		cycle++;
		if (y < Target)
			Low = x;
		if (y > Target)
			High = x;
		x = Low + 0.5 * (High - Low);
		y = TheFunction(x);
		std::cout << "No. of iteration cycle: " << cycle 
		     << ", current vol = " << x 
		     << ", current price = " << y << "\n";
	} while (fabs(y - Target) > Tolerance);

	return x;
}