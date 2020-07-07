#include<bits/stdc++.h>

using namespace std;

struct node{
    string data;
    int priority;
    node *left,*right;

    node (string data,int priority) : data(data),priority(priority),left(NULL),right(NULL) {}

    bool operator < (const node &n) const{
        return priority>n.priority;
    }
};

void ins(node *&tree,node &toAdd){
    if(tree==NULL){
        node *p=new node(toAdd.data,toAdd.priority);
        tree=p;
        return;
    }
    if(toAdd.data>tree->data)
        ins(tree->right,toAdd);
    else
        ins(tree->left,toAdd);
    return;
}

void display(node *tree){
    if(tree==NULL)
        return;
    cout<<"(";
    display(tree->left);
    cout<<tree->data<<"/"<<tree->priority;
    display(tree->right);
    cout<<")";
    return;
}

void add(string temp,vector<node> &all){
    int sep=0,priority=0;
    while(temp[sep]!='/')
        sep++;
    for(int i=sep+1;i<temp.size();i++){
        priority*=10;
        priority+=temp[i]-'0';
    }
    all.push_back(node(temp.substr(0,sep),priority));
    return;
}

int main(){
    int n;
    while(cin>>n,n){
        string temp;
        vector<node> all;
        while(n--){
            cin>>temp;
            add(temp,all);
        }
        sort(all.begin(),all.end());
        node *tree=NULL;
        for(int i=0;i<all.size();i++)
            ins(tree,all[i]);
        display(tree);
        cout<<endl;
    }
    return 0;
}
