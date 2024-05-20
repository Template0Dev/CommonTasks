#include "./Entering.h"
#include "./EX22/Polynomial.h"
#include "./EX23/Sequence.h"
#include "./EX24/CharCount.h"

using namespace std;

/// <summary>
/// Entering Point of the Program.
/// </summary>
/// <returns></returns>
int main(int argc, char* argv[])
{
	int exercise;
	cout << "Choose exercise to run (22..24): ";
	std::cin >> exercise;

	if (exercise == 22) Exercise22();
	else if (exercise == 23) Exercise23();
	else if (exercise == 24) Exercise24();

	system("PAUSE");
	return 0;
}

/// <summary>
/// Exercise 22 function.
/// </summary>
/// <returns></returns>
static int Exercise22()
{
	try
	{
		std::vector<std::pair<double, double>> values = InputFunctionValues();
		double x;

		PrintFunction(values);

		std::cout << "Enter the value of X: ";
		std::cin >> x;

		double result = Znach(values, x);
		std::cout << "The result of the polynomial function is: " << result << '.' << std::endl;

		return 0;
	}
	catch (const std::exception& exc)
	{
		std::cerr << "Exception was thrown: " << exc.what() << std::endl;
		return 1;
	}
}

/// <summary>
/// Exercise 23 function.
/// </summary>
/// <returns></returns>
static int Exercise23()
{
	int n;
	std::cout << "Enter the value of n: ";
	std::cin >> n;

	if (n <= 0)
	{
		std::cerr << "Error: n must be a positive integer." << std::endl;
		return 1;
	}

	std::vector<double> sequence = GenerateSequence(n);
	std::cout << "Sequence is generated successfully!" << std::endl << std::endl;

	std::string filepath;
	std::cout << "Enter the file path to save the sequence: ";
	std::cin >> filepath;
	try
	{
		WriteSequenceToFile(sequence, filepath);
		std::cout << std::format("File is successfully written in {}.", filepath) << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	double epsilon;
	std::cout << "Enter the value of E: ";
	std::cin >> epsilon;

	if (epsilon < 0)
	{
		std::cerr << "Error: E must be a non-negative value." << std::endl;
		return 1;
	}

	PrintLargeElements(sequence, epsilon);
	return 0;
}

/// <summary>
/// Exercise 24 function.
/// </summary>
/// <returns></returns>
static int Exercise24() 
{
	std::string filepath;
	std::cout << "Enter the file path: ";
	std::cin >> filepath;

	try 
	{
		auto [latinCount, cyrillicCount] = CountCharacters(filepath);

		std::cout << std::endl << "Latin Characters: " << latinCount << std::endl;
		std::cout << "Cyrillic Characters: " << cyrillicCount << std::endl;

		if (latinCount > cyrillicCount) 
			std::cout << std::format("File contains more Latin characters (difference: {}).\n", latinCount - cyrillicCount);
		else if (cyrillicCount > latinCount) 
			std::cout << std::format("File contains more Cyrillic characters (difference: {}).\n", cyrillicCount - latinCount);
		else 
			std::cout << "File contains an equal number of Latin and Cyrillic characters.\n";

		return 0;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
