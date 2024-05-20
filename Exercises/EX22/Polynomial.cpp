#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <sstream>
#include "polynomial.h"

/// <summary>
/// Function to input and validate the function values.
/// </summary>
/// <returns></returns>
std::vector<std::pair<double, double>> InputFunctionValues() 
{
    std::vector<std::pair<double, double>> values;
    // First value will be infinite, the following iterations will apply corresponding numbers.
    double previousSecondNum = std::numeric_limits<double>::infinity();

    std::string input;
    std::cout << "Enter numbers in the format {Num1}-{Num2}, or a single {Num1} to finish." << std::endl;

    while (true) {
        std::getline(std::cin, input);

        if (input.empty())
            continue;

        std::istringstream singleStream(input);
        double singleNum;
        if (singleStream >> singleNum && singleStream.eof()) 
        {
            // This happens if you send singular value.
            values.emplace_back(singleNum, 1);
            break;
        }

        size_t dashPos = input.find('-');
        if (dashPos != std::string::npos) 
        {
            try 
            {
                double num1 = std::stod(input.substr(0, dashPos));
                double num2 = std::stod(input.substr(dashPos + 1));

                if (num2 >= previousSecondNum) 
                {
                    std::cerr << "Error: Each next second number must be lower than the previous second number." << std::endl;
                    continue;
                }

                values.push_back(std::make_pair(num1, num2));
                previousSecondNum = num2;
            }
            catch (const std::invalid_argument& e) 
            {
                std::cerr << "Invalid input format. Please enter numbers in the format {Num1}-{Num2}." << std::endl;
            }
            catch (const std::out_of_range& e) 
            {
                std::cerr << "Number out of range. Please enter valid doubles." << std::endl;
            }
        }
        else 
        {
            std::cerr << "Invalid input format. Please enter numbers in the format {Num1}-{Num2}." << std::endl;
        }
    }

    return values;
}

/// <summary>
/// Prints generated polynomial function to User Console.
/// </summary>
/// <param name="values"></param>
void PrintFunction(const std::vector<std::pair<double, double>>& values) 
{
	std::ostringstream oss;
	for (size_t i = 0; i < values.size() - 1; ++i) 
	{
		const auto& [num1, num2] = values[i];
		if (i > 0) 
			oss << "+";

		oss << num1 << "x^" << num2;
	}

	std::cout << "\nFunction: " << oss.str() << std::format("+({}).", values.back().first) << std::endl;
}

/// <summary>
/// Function to calculate the value of the polynomial.
/// </summary>
/// <param name="values"></param>
/// <param name="x"></param>
/// <returns></returns>
double Znach(const std::vector<std::pair<double, double>>& values, double x)
{
	double result = 0.0;
	for (const auto& [num1, num2] : values)
		result += num1 * pow(x, num2);
	
	return result - values.back().first;
}
