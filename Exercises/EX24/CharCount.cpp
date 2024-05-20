#include <fstream>
#include <stdexcept>
#include <codecvt>
#include <locale>
#include "./CharCount.h"

/// <summary>
/// Function to count Latin and Cyrillic characters in a file.
/// </summary>
/// <param name="filepath"></param>
/// <returns></returns>
std::pair<int, int> CountCharacters(const std::string& filepath) 
{
    std::wifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Unable to open file: " + filepath);

    // Use UTF-8 encoding
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    int latinCount = 0;
    int cyrillicCount = 0;
    wchar_t ch;

    while (file.get(ch)) 
    {
        if (IsCyrillic(ch)) cyrillicCount++;
        else if (IsLatin(ch)) latinCount++;
    }

    file.close();
    return { latinCount, cyrillicCount };
}

/// <summary>
/// Function to check if a character is Cyrillic.
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
static bool IsCyrillic(wchar_t ch)
{
    return ch >= L'А' && ch <= L'я';
}

/// <summary>
/// Function to check if a character is Latin.
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
static bool IsLatin(wchar_t ch)
{
    return ch >= L'A' && ch <= L'z';
}
