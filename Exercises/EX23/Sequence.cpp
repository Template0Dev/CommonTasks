#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "./sequence.h"

const std::string ACCESS_DENIED_WARNING = "Please, check whether your access to folder is enabled for program (if you try to write file in system dir).";

/// <summary>
/// Function to generate the sequence.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
std::vector<double> GenerateSequence(int n) 
{
	std::vector<double> sequence;
	double factorial = 1.0;
	for (int i = 1; i <= n; ++i) 
	{
		factorial *= i;
		double element = pow(-1, i - 1) * (1.0 / factorial);
		sequence.push_back(element);
	}

	return sequence;
}

/// <summary>
/// Function to write the sequence to a file.
/// </summary>
/// <param name="sequence"></param>
/// <param name="filename"></param>
void WriteSequenceToFile(const std::vector<double>& sequence, const std::string& filename) {
	std::ofstream file(filename);
	if (!file) 
		throw std::runtime_error(std::format("Unable to open file: {}.\n{}", filename, ACCESS_DENIED_WARNING));

	for (const auto& elem : sequence) 
		file << std::fixed << std::setprecision(5) << elem << std::endl;
	file.close();
}

/// <summary>
/// Function to print elements larger than epsilon.
/// </summary>
/// <param name="sequence"></param>
/// <param name="epsilon"></param>
void PrintLargeElements(const std::vector<double>& sequence, double epsilon) 
{
	std::cout << std::format("Elements in the sequence larger than {}:", epsilon) << std::endl;
	for (const auto& elem : sequence) 
	{
		if (std::abs(elem) > epsilon) 
			std::cout << std::fixed << std::setprecision(5) << elem << " ";
	}
	std::cout << std::endl;
}
