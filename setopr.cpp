
#include<iostream>
using namespace std;

class Set
{
    int set[10];
    int cnt = 0;
    public:
    int i;
    void insert();
    void display();
    int search(int key);
    void size();
    void remove();
    void Union(Set s1, Set s2);
    void intersection(Set s1, Set s2);
    void difference(Set s1, Set s2);
    void subset(Set s1, Set s2);
};

void Set::insert()
{
    int n;
    cout<<"Enter the number of elements in set : ";
    cin>>n;
    cout<<"Enter elements of set: ";
    for(int i=0;i<n;i++)
    {
        cin>>set[i];
    }
    cnt=n;
}

void Set::display()
{
    cout<<"SET={ ";
    for(int i = 0; i < cnt; i++)
    {
        cout<<set[i]<<" ";
    }
    cout<<"}";
}

int Set::search(int x)
{
    for (int i=0; i<cnt;i++)
    {
        if(x==set[i])
        {
            return i;
        }
    }
    return -1;
}

void Set::size()
{
    cout<<"Size of set is: "<< cnt;
}

void Set::remove()
{
    int key, temp;
    cout<<"Enter key to be removed: ";
    cin>>key;
    temp=search(key);
    if(temp != -1)
    {
        for (int i=temp; i<cnt-1;i++)
        {
            set[i] = set[i + 1];
        }
        cnt--;
        cout<<"Key "<<key<<"removed successfully." ;
    } else
    {
        cout<<"Key not found" ;
    }
}

void Set::Union(Set s1,Set s2)
{   int i;
    cnt=0; //reset the element
    for (i = 0; i<s1.cnt; i++) 
    {
        set[cnt++]=s1.set[i];
    }
    for (i = 0; i < s2.cnt; i++) 
    {
        if (s1.search(s2.set[i])==-1) {
            set[cnt++]=s2.set[i];
        }
    }
}
void Set::intersection(Set s1,Set s2)
{
    int i;
    for(i=0;i<s2.cnt;i++)
    {
        if (s1.search(s2.set[i])!=-1)
        {
            set[cnt++]=s2.set[i];
        }
    }
}

void Set::difference (Set s1,Set s2)
{   int i;
    for (int i = 0; i < s1.cnt; i++) 
    {
        if (s2.search(s1.set[i]) == -1) 
        {
            set[cnt++] = s1.set[i];
        }
    }
}

void Set::subset (Set s1,Set s2)
{ 
    for (int i = 0; i < s1.cnt; i++) 
    {
        if (s2.search(s1.set[i]) == -1) 
        {
            cout << "Set A is not a subset of Set B." ;
            return;
        }
    }
    cout << "Set A is a subset of Set B." ;
}

int main()
{
    int choice, num;
    Set s1,s2,s3;
    do
    {
        cout<<"\nMENU";
        cout<<"\n1.Insert the set";
        cout<<"\n2.Display the set";
        cout<<"\n3.Search an element from the set";
        cout<<"\n4.Remove an element from the set";
        cout<<"\n5.Size of set";
        cout<<"\n6.Union of 2 sets ";
        cout<<"\n7.Intersection of 2 sets";
        cout<<"\n8.Difference of 2 sets";
        cout<<"\n9.Subset";
        cout<<"\n10. Exit";
        cout<<"\nEnter your choice: ";
        cin >>choice;
        switch(choice)
    {
    case 1:
        s1.insert();
        break;
    case 2:
        s1.display();
        break;
    case 3:
       cout << "Enter element to be searched: ";
       cin >> num;
       {
        int res = s1.search(num);
        if (res != -1)
           cout << "Number " << num << " is at position " << res ;
        else
           cout << "Number not found in the set" ;
        }
        break;
    case 4: s1.remove();
        break;
    case 5: s1.size();
        break;
    case 6:
            cout << "Insert elements into Set 2:";
            s2.insert();
            cout << "Union of Set 1 and Set 2: ";
            s3.Union(s1, s2);
            s3.display();
        break;
    case 7:
            s2.insert();
            s3.intersection(s1, s2);
            cout << "Intersection of Set 1 and Set 2: ";
            s3.display();
            break;
    case 8:
            cout << "Insert elements into Set 2:";
            s2.insert();
            s3.difference(s1, s2);
            cout << "Difference of Set 1 and Set 2: ";
            s3.display();
            break;
    case 9:   
        cout << "Insert elements into Set 2:";
        s2.insert();
        s3.subset(s1, s2);
        break;
    case 10:cout << "Exit the program " ;
     break;
    default:
        cout << "Invalid choice. Please try again." ;
    break;
    }
   } while(choice != 10);
    return 0;
}
