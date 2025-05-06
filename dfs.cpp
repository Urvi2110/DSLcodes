
#include<iostream>
using namespace std;

class graph
{ public:
int vcnt,rcnt;
int a[20][20];
int v[20];
graph()
{
vcnt=0;
}
void adj_matrix();
void bfs();
void dfs();
void dis_adj_matrix();
int search(int key);
};

void graph::adj_matrix()
{
cout<<"Enter no.of vertices:";
cin>>vcnt;
cout<<"Enter adjacency matrix:";
for(int i=0;i<vcnt;i++)
{ for(int j=0;j<vcnt;j++)
{
cin>>a[i][j];
}
}
}

void graph::dis_adj_matrix()
{
 cout<<"Adjacency Matrix is:\n";
 for(int i=0;i<vcnt;i++)
 { 
  for(int j=0;j<vcnt;j++)
  { 
   cout<<a[i][j]<<"  ";
   }
  cout<<endl;
  }
 }

class queue
{ 
 public:
 int front,rear;
 int q[20];
 queue()
 {
  front=0;
  rear=0;
 }
 void insert(int key);
 int Delete();
};

void queue::insert(int key)
{ 
 if (rear<20)
 {
  q[rear++]=key;
  }
 else
 {
  cout<<"Queue is full";
  }
}

int queue::Delete()
{
 if (rear!=front)
 { 
  return q[front++];
 }
 else
 {
 cout<<"Queue is empty";
 }
}

class stack
{ 
 public:
 int top;
 int s[20];
 stack()
 {
 top= -1;
 }
 void push (int key);
 int pop();
};

void stack::push(int key)
{ 
 if (top!=20)
 {
 s[++top]=key;
 }
 else
 {
 cout<<"Stack is full";
 }
}

int stack::pop()
{
 if(top!= -1)
 {
  return s[top--];
 }
 else
 {
  cout<<"Stack is empty";
 }
}
void graph :: bfs()
{
 int sv, curr;
 cout<<"Enter start vertex:";
 cin>>sv;
 v[rcnt++]=sv;
 queue q;
 q.insert(sv);
 for (int i=1;i<=vcnt;i++)
 {
  curr=q.Delete();
  for (int c=1; c<=vcnt;c++)
  {
   if (a[curr][c]==1)
   {
   q.insert(c);
   }
  if (search(c)==0)
  {
   v[rcnt++]=c;
  }
 }
}
cout<<"BFS";
for(int i=0;i<rcnt;i++)
{ 
 cout<<v[i];
}
}

int graph::search(int key)
{ 
 int i;
 for(i=0;i<rcnt;i++)
 {
  if (v[i]==key)
  {
   return 1;
  }
 }
  if (i==rcnt)
 {
 return 0;
 }
}

void graph :: dfs()
{
int sv, curr;
cout<<"enter start vertex:";
cin>>sv;
v[rcnt++]=sv;
stack s ;
s.push(sv);
for (int i=1;i<=vcnt;i++)
{
 curr=s.pop();
 for (int c=1;c<=vcnt;c++)
 {
  if (a[curr][c]==1)
  {
   s.push(c);
  }
 if (search(c)==0)
 {
  v[rcnt++]=c;
  }
 }
}
cout<<"DFS";
for(int i=0;i<rcnt;i++)
{
 cout<<v[i];
}
}

int main()
{ 
graph g;
int ch;

do
{
cout<<"\n*****MENU*****";
cout<<"\n1.Enter adjacency matrix";
cout<<"\n2.Display Adjacency matrix";
cout<<"\n3.BFS";
cout<<"\n4.DFS";
cout<<"\n5.Exit";

cout<<"\nEnter your choice:";
cin>>ch;
switch (ch)
{
case 1:
g.adj_matrix();
break;
case 2:
g.dis_adj_matrix();
break;
case 3:
g.bfs();
break;
case 4:
g.dfs();
break;
case 5:
cout<<"EXIT PROGRAM";
default :
cout<<"Enter correct option : ";
break;
}
} while (ch!=5);
return 0;
}
