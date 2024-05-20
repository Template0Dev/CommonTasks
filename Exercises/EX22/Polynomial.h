#pragma once

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <utility>

std::vector<std::pair<double, double>> InputFunctionValues();
void PrintFunction(const std::vector<std::pair<double, double>>& values);
double Znach(const std::vector<std::pair<double, double>>& values, double x);

#endif
