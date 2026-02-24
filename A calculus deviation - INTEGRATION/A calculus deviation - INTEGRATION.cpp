// A calculus deviation - INTEGRATION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


float integrateXSquared(float lowerXBound, float upperXBound, float deltaX)
{
	float sum = 0.0f; 

	for (float x = lowerXBound; x <= upperXBound; x += deltaX)
	{
		float xSquared = x * x; 
		float xSquaredDeltaX = deltaX * xSquared; 

		sum += xSquaredDeltaX; 
	}

	return sum; 
}

/*f is intended to be an arbitary polynomial, exponential, trig, etc. function*/
template <typename Callable> 
float integrate(float a, float b, float dx, Callable f)
{
	float sum = 0.0f;

	for (float x = a; x < b; x += dx)
	{
		sum += f(x) * dx; 
	}

	return sum;
}

float squareX(float x)
{
	return x * x; 
}

int main()
{
	//std::cout << integrateXSquared(-1.0f, 2.0f, 0.0001f) << "\n";

	float dx = 0.001f; 

	float area1 = integrate(0.0f, 4.0f, dx,
		[](float x)
		{
			return x * x * x;
		});

	std::cout << area1 << "\n";

	auto gaussian = 
		[](float x) 
		{ 
			return std::exp(-(x * x)); 
		};

	float area2 = integrate(-3.0f, 3.0f, 0.01f, gaussian);
}

