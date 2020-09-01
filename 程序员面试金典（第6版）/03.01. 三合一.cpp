class TripleInOne {
private:
    vector<int> nums;
    vector<int> peek_index;
    int stackSize;
public:
    TripleInOne(int stackSize) {
        this->stackSize = stackSize;
        for (int i = 0; i < 3; i++) {
            peek_index.push_back(stackSize * i);
        }
        nums = vector<int>(stackSize * 3, 0);
    }

    void push(int stackNum, int value) {
        if (peek_index[stackNum] < (stackNum + 1) * stackSize)
            nums[peek_index[stackNum]++] = value;
    }

    int pop(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        int num = nums[--peek_index[stackNum]];
        return num;
    }

    int peek(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        return nums[peek_index[stackNum] - 1];
    }

    bool isEmpty(int stackNum) {
        return peek_index[stackNum] == stackNum * stackSize;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */