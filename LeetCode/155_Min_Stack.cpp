class MinStack {
  public:
    MinStack() {
      j = 0;
    }

    void push(int val) {
      mn[j] = j? min(mn[j-1], val) : val;
      st[j] = val;
      j++;
    }

    void pop() {
      j--;
    }

    int top() {
      return st[j-1];
    }

    int getMin() {
      return mn[j-1];
    }

  private:
    static const int maxj = 3e4 + 10;
    int j, st[maxj], mn[maxj];
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
