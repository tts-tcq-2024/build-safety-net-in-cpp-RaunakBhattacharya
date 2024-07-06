#include "Soundex.h"
#include <cctype>
#include <string>
#include <array>

std::string padWithZeros(const std::string& str) {
    auto zerosNeeded = 4 - str.length();
    return str + std::string(zerosNeeded, '0');
}

std::array<char, 26> soundexTable = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

char getSoundexCode(char c) {
    return soundexTable[toupper(c) - 'A'];
}

bool shouldAppendCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

std::string generateSoundexCode(const std::string& name, char& prevCode) {
    std::string soundexCode;
    for (size_t i = 1; i < name.length() && soundexCode.length() < 3; ++i) {
        char code = getSoundexCode(name[i]);
        if (shouldAppendCode(code, prevCode)) {
            soundexCode += code;
            prevCode = code;
        }
    }
    return soundexCode;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    soundex += generateSoundexCode(name, prevCode);

    return padWithZeros(soundex);
}
