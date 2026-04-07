class Robot {
private:
    int x = 0, y = 0, gridWidth, gridHeight, O, moveCount = 0;
    char direction = 0;
    bool moved = false;

public:
    Robot(int width, int height) {
        this->gridWidth = width - 1;
        this->gridHeight = height - 1;

        this->O = (width + height - 2) << 1;
    }
    
    void step(int num) {
        num = num % O;
        moved = true;

        moveCount += num;
        moveCount = moveCount % O;
    }
    
    std::vector<int> getPos() {
        while(moveCount) {
            switch(direction) {
                case 0:
                    if(moveCount > gridWidth - x) {
                        moveCount -= gridWidth - x;
                        x = gridWidth;
                        direction = 1;
                    } else {
                        x += moveCount;
                        moveCount = 0;
                    }
                    break;
                case 1:
                    if(moveCount > gridHeight - y) {
                        moveCount -= gridHeight - y;
                        y = gridHeight;
                        direction = 2;
                    } else {
                        y += moveCount;
                        moveCount = 0;
                    }
                    break;
                case 2:
                    if(moveCount > x) {
                        moveCount -= x;
                        x = 0;
                        direction = 3;
                    } else {
                        x -= moveCount;
                        moveCount = 0;
                    }
                    break;
                case 3:
                    if(moveCount > y) {
                        moveCount -= y;
                        y = 0;
                        direction = 0;
                    } else {
                        y -= moveCount;
                        moveCount = 0;
                    }
                    break;
            }
        }

        return {x, y};
    }
    
    std::string getDir() {
        getPos();
        if(moved && x == 0 && y == 0) {
            return "South";
        }
    
        switch(direction) {
            case 0:
                return "East";
                break;
            case 1:
                return "North";
                break;
            case 2:
                return "West";
                break;
            default:
                return "South";
        }
    }
};
