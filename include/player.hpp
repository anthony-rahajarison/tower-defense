#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player {
    private : 
        int remainingLives = 3 ;
        int credit = 300;
        bool gameover = false;
    public :
        Player();
        int returnCredit();
        int returnLives();
        void addCredit(int c);
        void removeCredit(int c);
        void removeLife();
        bool isGameOver();
};

#endif