

#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=NULL;
        prev=NULL;
    }
};


class LinkedList{
    public:
        Node* head=new Node(0,0);
        Node* tail=new Node(0,0);

    LinkedList(){
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    
    void deleteNode(Node* node){
        Node* next=node->next;
        Node* prev=node->prev;
        delete(node);
        prev->next=next;
        next->prev=prev;
        return;
    }
};


class LRUCache{
    public:
    unordered_map<int,Node*> m;
    int capacity;
    LinkedList l;

    LRUCache(int capacity){
        this->capacity=capacity;
    }
    
    void put(int key,int value){

        // if key exists in map
        if(m.find(key)!=m.end()){
           Node* existing_node=m[key];
           m.erase(key);
           l.deleteNode(existing_node);
        }

        //if cache size if full
        if(m.size()==capacity){
            m.erase(l.tail->prev->key);
            l.deleteNode(l.tail->prev);
        }
        //last add the node to list and map
        Node* newNode=new Node(key,value);
        l.addNode(newNode);
        m[key]=l.head->next;
        return;
    }


    int get(int key){
        //If key is present in the map
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            int res=node->value;
            m.erase(key);
            l.deleteNode(node);
            l.addNode(node);
            m[key]=l.head->next;
            return res;
        }

        // if key is not present in the map
        return -1;
    }

    int getMostRecentKey(){
        return l.head->next->value;
    }
};


int main(){
    system("clear");
    LRUCache cache(3);
    
    cache.put(1,10);
    cout<<cache.getMostRecentKey()<<endl;

    cache.put(2,20);
    cout<<cache.getMostRecentKey()<<endl;

    cache.put(3,30);
    cout<<cache.getMostRecentKey()<<endl;

    cache.put(4,40);
    cout<<cache.getMostRecentKey()<<endl;

    cout<<cache.get(2)<<endl;





    return 0;
}
