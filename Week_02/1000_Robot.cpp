struct Position {
    int x;
    int y;
};

class Robot {
    public:
        Robot(); /* default constructor, initialize at (0,0) */
        Robot(Position pos); /* initialize at pos */
        void Move(char Dir); /* Dir could be 'N', 'E', 'S', 'W' */
        Position GetPosition(); /* return current position */
    private:
        Position currentPos_;
};

Robot::Robot() {
    currentPos_.x = 0;
    currentPos_.y = 0;
}

Robot::Robot(Position pos) {
    currentPos_ = pos;
}

void Robot::Move(char dir) {
    int dir_num;
    switch (dir) {
        case 'N': dir_num = 0; break;
        case 'E': dir_num = 1; break;
        case 'S': dir_num = 2; break;
        case 'W': dir_num = 3; break;
    }
    const int dx[ 4 ] = {0, 1, 0, -1};
    const int dy[ 4 ] = {1, 0, -1, 0};
    currentPos_.x += dx[dir_num];
    currentPos_.y += dy[dir_num];
}

Position Robot::GetPosition() {
    return currentPos_;
}
