/*Approach
1. We also can use single queue
2. Firstly push element to the queue
3. Then pop element from front and push till the size-1
*/



class MyStack {
public:
    queue<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int f;
        if(!q.empty()){
            f=q.front();
            q.pop();
            return f;
        }
        return NULL;
    }
    
    int top() {
        if(!q.empty()) return q.front();
        return NULL;
    }
    
    bool empty() {
        return q.empty();
    }
};
