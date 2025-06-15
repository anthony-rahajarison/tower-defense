#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
    private :
        int x = 0;
        int y = 0;
    public:
        void set_x(int value_x);
        void set_y(int value_y);
        int get_x();
        int get_y();
        Position(int x, int y);
        Position();
};

#endif