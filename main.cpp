#include <iostream>

using namespace std;

class EmptyQueue{};

class Queue{
    struct Node{
        int data;
        Node* ptr;
    };
private:
    Node* front_;
    Node* rare_ ;

public:
    Queue(){
        front_ = NULL;
        rare_ = NULL;
    }

    int frontData(){
        if(front_ == NULL){
            return -1;
        }
        else{
            return front_->data;
        }
    }

    int rareData(){
        if(rare_ == NULL){
            return -1;
        }
        else{
            return rare_->data;
        }
    }

    void enqueue(int val){
        Node* node = new Node;
        node->data = val;
        node->ptr = NULL;
        if(front_ == NULL){
            front_ = node;
            rare_ = node;
        }
        else{
            rare_->ptr = node;
            rare_ = node;
        }
    }

    void dequeue(){
        if(front_==NULL){
            throw EmptyQueue();
        }
        else{
            Node* temp = new Node;
            temp = front_;
            front_ = temp->ptr;
            delete(temp);
        }
    }

    void display(){
        Node* temp = new Node;
        temp = front_;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->ptr;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    cout << "front : "<<q1.frontData()<<endl;
    cout << "rare : "<<q1.rareData()<<endl;
    q1.dequeue();
    cout << "front : "<<q1.frontData()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(8);
    q1.enqueue(17);
    q1.enqueue(10);
    q1.display();
    return 0;
}
