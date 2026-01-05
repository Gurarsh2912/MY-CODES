#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> s1;
    queue<int> s2;

public:
    void push(int data){
        while(!s1.empty()){
            s2.push(s1.front());
            s1.pop();
        }
        s1.push(data);
        while(!s2.empty()){
            s1.push(s2.front());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.front();
    }

    bool empty(){
        return s1.empty();
    }

};