#include <stack>
#include <stdio.h>
#include <type_traits>
#include <unistd.h>
using namespace std;

class MyQueue {
        stack<int> FI;
        stack<int> FO;
        bool moved;
public:
    MyQueue() {
        moved = false;
    }
    
    void push(int x) {
        if (moved){
            int len = FO.size();
            while(len-- > 0){
                FI.push(FO.top());
                FO.pop();
            }
            moved = false;
        }
        FI.push(x);
    }
    
    int pop() {
        if (moved){
            int data = FO.top();
            FO.pop();
            return data;
        }
        int len = FI.size();
        while(len-- > 0){
            FO.push(FI.top());
            FI.pop();
        }
        int data = FO.top();
        FO.pop();
        moved = true;
        return data;
    }
    
    int peek() {
        if (moved){
            int data = FO.top();
            return data;
        }
        int len = FI.size();
        while(len-- > 0){
            FO.push(FI.top());
            FI.pop();
        }
        int data = FO.top();
        moved = true;
        return data;
    }
    
    bool empty() {
        if (moved){
            return FO.size() == 0;
        }
        return FI.size() == 0;
    }
};

class MyQueue2 {
        stack<int> FI;
        stack<int> FO;
public:
    MyQueue2() {

    }
    
    void push(int x) {
        FI.push(x);
    }
    
    int pop() {
        if (FO.empty()){
            while(!FI.empty()){
                FO.push(FI.top());
                FI.pop();
            }
        }
        int data = FO.top();
        FO.pop();
        return data;
    }
    
    int peek() {
        int data = pop();
        FO.push(data);
        return data;
    }
    
    bool empty() {
        return FI.empty() && FO.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while( !q.empty() ){
        printf("s1# %d,",q.pop());
    } printf("\n");
    q.push(6);
    q.push(7);
    while( !q.empty() ){
        printf("s2# %d,",q.pop());
    } printf("\n");

    q.push(10);
    q.push(11);
    {
        printf("s3# %d,",q.peek());//10
    } printf("\n");
    q.push(12);
    q.push(13);//10,11,12,13
    {
        printf("s4# %d,",q.pop());//10
    } printf("\n");

    q.push(14);//11,12,13,14
    {
        printf("s5# %d,",q.peek());//11
    } printf("\n");
    q.push(15);//11,12,13,14,15
    {
        printf("s6# %d,",q.pop());//11
    } printf("\n");
    {
        printf("s7# %d,",q.pop());//12
    } printf("\n");
    while( !q.empty() ){
        printf("s8# %d,",q.pop());
    } printf("\n");

}