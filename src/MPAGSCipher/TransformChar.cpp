#include <string>
#include <cctype>
#include "TransformChar.hpp"

//Charater transforming function
std::string transformChar(const char in_char) {
    std::string result;

    if (std::isalpha(in_char)) {
        result += std::toupper(in_char);
    } else {
        switch (in_char) {
            case '0':
                result += "ZERO";
                break;
            case '1':
                result += "ONE";
                break;
            case '2':
                result += "TWO";
                break;
            case '3':
                result += "THREE";
                break;
            case '4':
                result += "FOUR";
                break;
            case '5':
                result += "FIVE";
                break;
            case '6':
                result += "SIX";
                break;
            case '7':
                result += "SEVEN";
                break;
            case '8':
                result += "EIGHT";
                break;
            case '9':
                result += "NINE";
                break;
        }
    }
        return result;
}