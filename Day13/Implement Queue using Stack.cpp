/*
==>Approach 1
Operation performed:-
 transfer s1 -> s2
 push(x) -> s1
 transfer s2 ->s1
 */

class MyQueue {
public:
    stack<int>s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    
    int pop() {
        int top=s1.top();
        s1.pop();
        return top;
    }
    

    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


 
 
 /*
 ===>Approach 2
 ==> Push =O(1), Pop and top ~ O(1) amotised
 
 */

class MyQueue {
public:
    stack<int>s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        return;
    }
    
    int pop() {
        int top;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        top=s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        int top;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};



