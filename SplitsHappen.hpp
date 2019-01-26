#ifndef SPLITSHAPPEN_SPLITSHAPPEN
#define SPLITSHAPPEN_SPLITSHAPPEN

#include <string>

namespace splitshappen
{
    // Character constants
    extern const char BLANK_CHAR;  //!< Character used when no pins are knocked down
    extern const char SPARE_CHAR;  //!< Character used when a spare is thrown
    extern const char STRIKE_CHAR; //!< Character used when a strike is thrown

    static constexpr int BLANK_SCORE  =  0; //!< Score for knocking down 0 pins
    static constexpr int SPARE_SCORE  = 10; //!< Score for getting a spare
    static constexpr int STRIKE_SCORE = 10; //!< Score for getting a strike

    static constexpr int NUM_FRAMES = 10; //!< The number of frames

    //! Calculates the game score of the given string
    //! @note Does not do error checking for correctness
    //! @param[in] GameString The string that you wish to calculate the score of.
    int GetGameScore(const std::string & GameString);

    //! Calculates the score of a given frame
    //! @param[in,out] CurThrow A pointer character of the current throw. The pointer will
    //! be updated to point to the first throw of the next frame.
    //! @return The score of the current frame.
    int GetFrameScore(const char *& CurThrow);

    //! Calculates the score of last frame
    //! @param[in,out] CurThrow A pointer character of the current throw.
    //! @return The score of the current frame.
    int GetFinalFrameScore(const char * CurThrow);

    //! Calculates the score of the given throw
    //! @param[in] ThrowChar The character to get the score of
    //! @return The score of the given throw character.
    int GetThrowScore(const char * ThrowChar);
}

#endif