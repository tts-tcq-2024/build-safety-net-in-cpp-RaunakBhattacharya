#include "Soundex.h"
#include <gtest/gtest.h>

TEST(SoundexTest, ReturnsEmptyStringWhenInputIsEmpty) {
    ASSERT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, ReturnsPaddedZerosWhenInputIsSingleCharacter) {
    ASSERT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, ConvertsLowerCaseCharactersToUpperCase) {
    ASSERT_EQ(generateSoundex("a"), "A000");
}

TEST(SoundexTest, ReplacesConsonantsWithAppropriateDigits) {
    ASSERT_EQ(generateSoundex("Ab"), "A100");
}

TEST(SoundexTest, IgnoresVowelLikeLetters) {
    ASSERT_EQ(generateSoundex("Aa"), "A000");
}

TEST(SoundexTest, CombinesDuplicateEncodings) {
    ASSERT_EQ(generateSoundex("Acdl"), "A234");
}

TEST(SoundexTest, LimitsLengthToFourCharacters) {
    ASSERT_EQ(generateSoundex("Dcdlb"), "D234");
}

TEST(SoundexTest, IgnoresVowelLikeLettersAfterFirstLetter) {
    ASSERT_EQ(generateSoundex("BaAeiouhycdl"), "B234");
}

TEST(SoundexTest, CombinesDuplicateCodesWhen2ndLetterDuplicates1st) {
    ASSERT_EQ(generateSoundex("Bbcd"), "B230");
}
