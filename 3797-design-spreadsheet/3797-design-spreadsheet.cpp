class Spreadsheet {
private:
    vector<vector<int>> grid;
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0]; 
        int col = colChar - 'A';  
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
    int getOperandValue(const string &operand) {
        if (isdigit(operand[0])) {
            return stoi(operand);
        } else {
            auto [row, col] = parseCell(operand);
            if (row >= 0 && row < (int)grid.size() && col >= 0 && col < 26) {
                return grid[row][col];
            }
            return 0;
        }
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0)); 
    }
    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }
    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }
    int getValue(string formula) {
        if (formula[0] == '=') formula = formula.substr(1);
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);
        return val1 + val2;
    }
};

