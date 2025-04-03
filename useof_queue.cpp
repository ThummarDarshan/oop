#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;  //10
    cout<<q.back()<<endl; //30
    cout<<q.size()<<endl; //3

    q.pop();  //for the remove elments

    cout<<q.front()<<endl; //20
    cout<<q.size()<<endl; //2





}
