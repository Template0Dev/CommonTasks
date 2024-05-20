#pragma once

#ifndef CHARCOUNT_H
#define CHARCOUNT_H

#include <string>
#include <utility>

std::pair<int, int> CountCharacters(const std::string& filepath);
static bool IsLatin(wchar_t ch);
static bool IsCyrillic(wchar_t ch);

#endif
