#pragma once

class Player
{
private:
    int max_rows = 10;
    int max_columns = 10;
    int current_row = 0;
    int current_column = 0;

public:
    int row();
    int column();
    void move_up();
    void move_left();
    void move_right();
    void move_down();
};