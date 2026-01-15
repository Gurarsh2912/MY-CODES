#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void zigZagLL(Node* head) {
    if (!head || !head->next) return;


    Node* mid = findMiddle(head);

    Node* second = mid->next;
    mid->next = NULL;

    second = reverse(second);

    Node* first = head;
    while (first && second) {
        Node* temp1 = first->next;
        Node* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    print(head);
    cout<<endl;
    zigZagLL(head);
    print(head);
}
