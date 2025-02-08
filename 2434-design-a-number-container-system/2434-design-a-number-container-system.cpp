class NumberContainers {
private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
public:
    NumberContainers() {}
    void change(int index, int number) {
        if (indexToNumber.count(index)) {
            int num = indexToNumber[index];
            numberToIndices[num].erase(index);
            if (numberToIndices[num].empty()) {
                numberToIndices.erase(num);
            }
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    int find(int number) {
        if (numberToIndices.count(number) && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }
};