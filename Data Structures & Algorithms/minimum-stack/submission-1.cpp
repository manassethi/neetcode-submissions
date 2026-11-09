class MinStack {
   public:
    multiset<int> sett;

    stack<int> st;

    MinStack() {}

    void push(int val) {
        sett.insert(val);
        st.push(val);
    }

    void pop() {
        int target = st.top();
        sett.erase(sett.find(target));
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return *sett.begin(); }
};
