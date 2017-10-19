
 
#include<bits/stdc++.h>
using namespace std;
bool check(int [], int);
int main(){
	int array[]={60,40,50,80,100};
	int size= sizeof(array)/sizeof(array[0]);
	if(check(array,size)){
		cout<<"CAN REPRESENT";
	}
	else{
		cout<<"CAN'T REPRESENT";
	}
	return 0;
}
bool check(int array[], int size)
{	 
	stack<int> s;
	int root = INT_MIN;
	for (int i=0; i<size; i++)
    {
        if (array[i] < root)
            return false;
 
        while (!s.empty() && s.top()<array[i])
        {
            root = s.top();
            s.pop();
        }
         s.push(array[i]);
    }
    return true;
}
