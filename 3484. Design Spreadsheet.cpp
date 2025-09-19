class Spreadsheet {
private:
    std::vector<std::vector<int>> spreadsheet;

public:
    Spreadsheet(int rows) {
        spreadsheet = std::vector<std::vector<int>>('Z' - 'A' + 1, std::vector<int>(rows, 0));
    }
    
    void setCell(const std::string& cell, int value) {
        spreadsheet[cell[0] - 'A'][std::stoi(cell.substr(1)) - 1] = value;
    }
    
    void resetCell(const std::string& cell) {
        spreadsheet[cell[0] - 'A'][std::stoi(cell.substr(1)) - 1] = 0;     
    }
    
    int getValue(const std::string& formula) {
        int index = std::find(formula.begin(), formula.end(), '+') - formula.begin();
        int sum;

        if('A' <= formula[1]) {
            sum = spreadsheet[formula[1] - 'A'][std::stoi(formula.substr(2, index - 2)) - 1];
        } else {
            sum = std::stoi(formula.substr(1, index - 1));
        }

        if('A' <= formula[index + 1]) {
            sum += spreadsheet[formula[index + 1] - 'A'][std::stoi(formula.substr(index + 2)) - 1];
        } else {
            sum += std::stoi(formula.substr(index + 1));
        }

        return sum;
    }
};
