#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
    private : 
        int remainingLives = 3 ;
        int credit = 300;
        bool gameover = false;
        int score = 0;
    public :
        Player();
        int returnCredit();
        int returnLives();
        int returnScore();
        void addCredit(int c);
        void addScore(int s);
        void removeCredit(int c);
        void removeLife();
        bool isGameOver();
        static int loadHighScore(const std::string& filename = "highscore.json");
        static void saveHighScore(int score, const std::string& filename = "highscore.json");
};

#endif