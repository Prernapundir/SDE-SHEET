/* Approach
1. Sort the stack using temporary stack
*/



/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void SortedStack :: sort()
{
   stack<int>st;
   int temp;
   
   while(!s.empty()){
       int temp=s.top();
       s.pop();
       
       while(!st.empty() and st.top()<temp){
           s.push(st.top());
           st.pop();
       }
       st.push(temp);
   }
   while(!st.empty()){
       s.push(st.top());
       st.pop();
   }
   return;
}
