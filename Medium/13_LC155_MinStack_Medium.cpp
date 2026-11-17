class MinStack {
private:
    stack<int> mainStack;
    stack<int> minimumStack;

public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);

        if (minimumStack.empty() ||
            val <= minimumStack.top()) {
            minimumStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minimumStack.top()) {
            minimumStack.pop();
        }

        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minimumStack.top();
    }
};
