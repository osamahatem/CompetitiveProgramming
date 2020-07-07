#include<bits/stdc++.h>

using namespace std;

struct node{
    string data;
    int priority;
    node *left,*right;

    node (string data,int priority) : data(data),priority(priority),left(NULL),right(NULL) {}

    static bool sort_priority (const node &a,const node &b){
        return a.priority>b.priority;
    }

    static bool sort_data(const node &a,const node &b){
        return a.data<b.data;
    }
};

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
        vector<node> priority,data;
        while(n--){
            cin>>temp;
            add(temp,priority);
        }
        data=priority;
        sort(priority.begin(),priority.end(),node::sort_priority);
        sort(data.begin(),data.end(),node::sort_data);
        for(int i=0;i<priority.size();i++)
            cout<<priority[i].data<<"/"<<priority[i].priority<<" ";
        cout<<endl;
        for(int i=0;i<data.size();i++)
            cout<<data[i].data<<"/"<<data[i].priority<<" ";
        cout<<endl;
    }
    return 0;
}
