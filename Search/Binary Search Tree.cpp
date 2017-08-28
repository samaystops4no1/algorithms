#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:long long int value;
public:long long int freq;
public:Node* left;
public:Node* right;
public:Node* parent;
public:Node(long long int value){
        this->value=value;
        this->freq=1;
        this->left= nullptr;
        this->right= nullptr;
        this->parent= nullptr;
    }
};

class BST{
public:long long int length;
public:Node* root;
public:BST(){
        this->length=0;
        this->root= nullptr;
    }
public:Node* search(long long int value){
        Node *temp=this->root;
        Node *parent=this->root;
        while(temp!= nullptr){
            if(value>temp->value){
                this->length=this->length+1;
                parent=temp;
                temp=temp->right;
            }
            else if(value<temp->value){
                this->length=this->length+1;
                parent=temp;
                temp=temp->left;
            }
            else{
                parent=temp;
                break;
            }
        }
        return parent;
    }
public:void insert(long long int value){
        if(this->root== nullptr){
            Node *temp=new Node(value);
            this->root=temp;
            this->length=this->length+1;
            return;
        }
        Node *n=this->search(value);
        if(n->value==value){
            n->freq=n->freq+1;
            return;
        }
        else{
            Node *node=new Node(value);
            node->parent=n;
            this->length=this->length+1;
            if(value>n->value){
                n->right=node;
            }
            else{
                n->left=node;
            }
        }
    }
public:void remove(long long int value){
        if(this->root== nullptr){
            return;
        }
        Node *node=this->search(value);
        if(node->value==value){
            //node value found
            if(node->freq>1){
                node->freq=node->freq-1;
                return;
            }
            this->length=this->length-1;
            if(node->left== nullptr && node->right== nullptr){
                if(node->parent!= nullptr) {
                    //no child
                    if (node->value > node->parent->value) {
                        node->parent->right = nullptr;
                    } else {
                        node->parent->left = nullptr;
                    }
                }
                else{
                    this->root= nullptr;
                }
            }
            else if(node->left== nullptr){
                if(node->parent!= nullptr) {
                    if (node->value > node->parent->value) {
                        node->parent->right = node->right;
                        node->right->parent = node->parent;
                    } else {
                        node->parent->left = node->right;
                        node->right->parent = node->parent;
                    }
                }
                else{
                    this->root=node->right;
                    node->right->parent= nullptr;
                }
            }
            else if(node->right== nullptr){
                if(node->parent!= nullptr) {
                    if (node->value > node->parent->value) {
                        node->parent->right = node->left;
                        node->left->parent = node->parent;
                    } else {
                        node->parent->left = node->left;
                        node->left->parent = node->parent;
                    }
                }
                else{
                    this->root=node->left;
                    node->left->parent= nullptr;
                }
            }
            else{
                Node *temp=node->right;
                Node *min=temp;
                while(temp!= nullptr){
                    min=temp;
                    temp=temp->left;
                }

                if(min->value>min->parent->value){
                    //min is the right child
                    min->parent->right=min->right;
                    if(min->right!=nullptr) {
                        min->right->parent = min->parent;
                    }
                }
                else{
                    //min is the left child
                    min->parent->left= min->right;
                    if(min->right!= nullptr) {
                        min->right->parent = min->parent;
                    }
                }
                node->value = min->value;
                node->freq=min->freq;

            }
        }
        else{
            //Node value not found
            return;
        }

    }
};


void printSorted(Node *a){
    if(a != nullptr){
        printSorted(a->left);
        cout<<a->value<<" ";
        printSorted(a->right);
    }
    else{
        return;
    }
}

void sanityTest(Node *a){
    if(a== nullptr){
        return;
    }
    if(a->parent== nullptr && a->left!= nullptr && a->right!= nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<a->left->value<<" right = "<<a->right->value<<" parent = NA"<<endl;
    }
    else if(a->parent==nullptr && a->left== nullptr && a->right!= nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<" NA "<<" right = "<<a->right->value<<" parent = NA"<<endl;
    }
    else if(a->parent==nullptr && a->left== nullptr && a->right== nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<" NA "<<" right = "<<" NA "<<" parent = NA"<<endl;
    }
    else if(a->parent!=nullptr && a->left== nullptr && a->right== nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<" NA "<<" right = "<<" NA "<<" parent = "<<a->parent->value<<endl;
    }
    else if(a->parent!=nullptr && a->left!= nullptr && a->right== nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<a->left->value<<" right = "<<" NA "<<" parent = "<<a->parent->value<<endl;
    }
    else if(a->parent!=nullptr && a->left== nullptr && a->right!= nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<" NA "<<" right = "<<a->right->value<<" parent = "<<a->parent->value<<endl;
    }
    else if(a->parent!=nullptr && a->left!= nullptr && a->right!= nullptr){
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<a->left->value<<" right = "<<a->right->value<<" parent = "<<a->parent->value<<endl;
    }
    else{
        cout<<"Value = "<<a->value<<" freq = "<<a->freq<<" left = "<<a->left->value<<" right = "<<" NA "<<" parent = "<<" NA "<<endl;
    }
    sanityTest(a->left);
    sanityTest(a->right);
}


int main() {
    BST a;
    a.insert(130);
    a.insert(50);
    a.insert(150);
    a.insert(150);
    a.insert(200);
    a.insert(140);
    a.insert(145);
    a.remove(130);
    sanityTest(a.root);
}
