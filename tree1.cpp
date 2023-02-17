#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* buildtree(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of"<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data for inserting in right of"<<data<<endl;
    root->right = buildtree(root->right);
    return root;

}
// node* buildfromlevelorder

void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = NULL;

    root = buildtree(root);
    levelordertraversal(root);
    return 0;
}