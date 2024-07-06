#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, ConvertsNamesToUpperCase) {
    EXPECT_EQ(generateSoundex("name"), "N500");
}

TEST(SoundexTest, IgnoresNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("N123"), "N000");
}

TEST(SoundexTest, LimitsLengthToFourCharacters) {
    EXPECT_EQ(generateSoundex("Nemetz"), "N532");
}

TEST(SoundexTest, IgnoresVowelLikeLetters) {
    EXPECT_EQ(generateSoundex("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST(SoundexTest, CombinesDuplicateEncodings) {
    EXPECT_EQ(generateSoundex("Abfcgdt"), "A123");
}

TEST(SoundexTest, UppercasesFirstLetter) {
    EXPECT_EQ(generateSoundex("abcd"), "A123");
}

TEST(SoundexTest, IgnoresCaseWhenEncodingConsonants) {
    EXPECT_EQ(generateSoundex("BCDL"), generateSoundex("Bcdl"));
}
