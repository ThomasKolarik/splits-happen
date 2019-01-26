#include "SplitsHappen.hpp"

namespace splitshappen
{
    const char BLANK_CHAR  = '-'; //< Character used when no pins are knocked down
    const char SPARE_CHAR  = '/'; //< Character used when a spare is thrown
    const char STRIKE_CHAR = 'X'; //< Character used when a strike is thrown

    // Calculates the game score of the given string
    // @note Does not do error checking for correctness
    // @param[in] GameString The string that you wish to calculate the score of.
    int GetGameScore(const std::string & GameString)
    {
        int score = 0;

        const char * curThrow = GameString.c_str();

        // Get the score for all frames except for the last one which is scored slightly differently.
        for (int curFrame = 0; curFrame < NUM_FRAMES - 1;++curFrame)
        {
            score += GetFrameScore(curThrow);
        }

        score += GetFinalFrameScore(curThrow);

        return score;
    }

    // Calculates the score of a given frame
    // @param[in,out] CurThrow A pointer character of the current throw. The pointer will
    // be updated to point to the first throw of the next frame.
    // @return The score of the current frame.
    int GetFrameScore(const char *& CurThrow)
    {
        int score = 0;

        if (*CurThrow == STRIKE_CHAR)
        {
            score = STRIKE_SCORE + GetThrowScore(CurThrow + 1) + GetThrowScore(CurThrow + 2);
            CurThrow += 1;
        }
        else
        {
            if (*(CurThrow + 1) == SPARE_CHAR)
            {
                score = SPARE_SCORE + GetThrowScore(CurThrow + 2);
            }
            else
            {
                score = GetThrowScore(CurThrow) + GetThrowScore(CurThrow + 1);
            }

            CurThrow += 2;
        }

        return score;
    }

    // Calculates the score of last frame
    // @param[in,out] CurThrow A pointer character of the current throw.
    // @return The score of the current frame.
    int GetFinalFrameScore(const char * CurThrow)
    {
        int score = 0;

        if (*CurThrow == STRIKE_CHAR || *(CurThrow + 1) == STRIKE_CHAR)
        {
            score = GetThrowScore(CurThrow) + GetThrowScore(CurThrow + 1) + GetThrowScore(CurThrow + 2);
        }
        else
        {
            score = GetFrameScore(CurThrow);
        }

        return score;
    }

    // Calculates the score of the given throw
    // @param[in] ThrowChar The character to get the score of
    // @return The score of the given throw character.
    int GetThrowScore(const char * ThrowChar)
    {
        if (*ThrowChar == STRIKE_CHAR)
        {
            return STRIKE_SCORE;
        }

        if (*ThrowChar == SPARE_CHAR)
        {
            return SPARE_SCORE - (*(ThrowChar - 1) - '0');
        }

        if (*ThrowChar == BLANK_CHAR)
        {
            return BLANK_SCORE;
        }

        return *ThrowChar - '0';
    }
}
