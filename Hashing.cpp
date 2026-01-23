#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;
        for(int i = 0; i<key.size(); i++){
            idx = idx + (key[i]*key[i])%totSize;
        }

        return idx%totSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totSize;
        currSize = 0;
        totSize *=2;
        table = new Node*[totSize];

        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }

        for(int i = 0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5){
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];

        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);
        Node * newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda>1){
            rehash();
        }
    }

    void print(){
        for(int i = 0; i<totSize; i++){
            cout<<"idx"<<"->"<<i;
            Node* temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<","<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<endl;
            
        }
    }

    int search(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while(temp!=NULL){
            if(temp->key == key){
                if(prev==temp){
                    table[idx] = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }

};

int main(){
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("Nepal", 30);
    ht.insert("UK", 70);
    ht.insert("US", 60);
    ht.insert("Canada", 45);
    ht.insert("Russia", 155);

    ht.remove("UK");
    ht.print();

}