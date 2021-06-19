#include<iostream>
using namespace std;
int move_backward(int s, int d, int b)
{
	int position = s;
	int temp = s;
	int count=0;
	while(temp>d)
	{
		position = position-b;
		count++;
		temp=temp-b;
		if(position<d)
		{
			return 0;
		}
	}
	return count;
}
int move_forward(int s, int d, int f)
{
	int position = s;
	int temp = s;
	int count=0;
	while(temp<d)
	{
		position = position+f;
		count++;
		temp=temp+f;
		if(position>d)
		{
			return 0;
		}
	}
	return count;
}
int main()
{
	int t,source,forward,backward,total,destination,res;
	cin>>t;
	while(t--)
	{
		cout<<"Total:\n";
		cin>>total;
		cout<<"Source Block: \n";
		cin>>source;
		cout<<"Destination Block:\n";
		cin>>destination;
		cout<<"Forward Steps:\n";
		cin>>forward;
		cout<<"Backward Steps:\n";
		cin>>backward;
		if(source>destination)
		{
		 res= move_backward(source,destination,backward);
		if(res==0)
		{
			cout<<"Not reachable\n";
		}
		else
		{
			cout<<"\nMinimum Steps taken:"<<res<<endl;
		}
	}
		else if(source<destination)
		{
		res = move_forward(source,destination,forward);
		if(res == 0)
		cout<<"Not reachable\n";
		else
		cout<<"Minimum steps taken: "<<res<<endl;
		}
		else
		cout<<"Minimum steps taken : 0"<<endl;
	}
}
