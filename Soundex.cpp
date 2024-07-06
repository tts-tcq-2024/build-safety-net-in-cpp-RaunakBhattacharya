#include "Soundex.h"
#include <cctype>
#include <string>

std::string generateSoundexCode(const std::string& name, char& prevCode) {
    std::string soundexCode;
    for (size_t i = 1; i < name.length() && soundexCode.length() < 3; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
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

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
