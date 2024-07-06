#include "Soundex.h"
#include <cctype>
#include <string>

std::string padWithZeros(const std::string& str) {
    auto zerosNeeded = 4 - str.length();
    return str + std::string(zerosNeeded, '0');
}

char getSoundexCode(char c) {
    return soundexTable[toupper(c) - 'A'];
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
        if (soundex.length() == 4) break;
    }

    return padWithZeros(soundex);
}
