#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "GameSession.hpp"

// Simple terminal interface. All game rules remain in GameSession.
class GameController {
    GameSession game;
    void showElements() const;
    void combineElements();
    void showHint();
    void showAchievements() const;
    void showElementInfo() const;
    void startNewGame();
    void saveGame() const;
    void loadGame();
public:
    void run();
};

#endif
