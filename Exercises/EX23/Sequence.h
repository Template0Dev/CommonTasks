#pragma once

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <string>

std::vector<double> GenerateSequence(int n);
void WriteSequenceToFile(const std::vector<double>& sequence, const std::string& filename);
void PrintLargeElements(const std::vector<double>& sequence, double epsilon);

#endif
