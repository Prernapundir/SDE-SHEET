/*Approach
1. Make either push operation costly or either make pop operation costly.
3. Take two queues q1,q2.
2. If making push operation costly do this:
   (i) Firstly push element to the q2
   (ii) Now push element of q1 to q2
   (iii) Swap q1 and q2
*/




class MyStack {
public:
    queue<int>q1,q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int f;
        if(!q1.empty()){
            f=q1.front();
            q1.pop();
            return f;
        }
        return NULL;
    }
    
    int top() {
        if(!q1.empty()) return q1.front();
        return NULL;
    }
    
    bool empty() {
        return q1.empty();
    }
};
