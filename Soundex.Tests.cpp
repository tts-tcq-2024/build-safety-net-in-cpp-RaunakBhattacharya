#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesMultipleCharacters) {
    EXPECT_EQ(generateSoundex("ABCD"), "A123");
}

TEST(SoundexTest, HandlesSimilarSoundingCharacters) {
    EXPECT_EQ(generateSoundex("Euler"), "E460");
    EXPECT_EQ(generateSoundex("Ellery"), "E460");
}

TEST(SoundexTest, HandlesDissimilarSoundingCharacters) {
    EXPECT_NE(generateSoundex("Euler"), generateSoundex("Gauss"));
}

TEST(SoundexTest, IgnoresNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("A#B$C%D"), "A123");
}

TEST(SoundexTest, HandlesMixedCaseCharacters) {
    EXPECT_EQ(generateSoundex("AbCd"), "A123");
}
