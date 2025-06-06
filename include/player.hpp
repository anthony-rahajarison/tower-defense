#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    private : 
        int remainingLives = 3 ;
        int credit = 0;
        bool gameover = false;
    public :
        void addCredit(int c);
        void removeCredit(int c);
        void removeLife();
        bool isGameOver();
};

#endif