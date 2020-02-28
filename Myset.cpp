#include<iostream>
#include<math.h>
using namespace std;
template< typename T>
class Myset
{
    private:
    T *setarr;
    int size;

    public:
    Myset()
    {   size=0;
        setarr = new T[size];
    }
    Myset (int s)
    {
        size=s;
        setarr =new T[size];
        
    }
    Myset (const Myset<T> &oldset)
    {
    	size=oldset.size;
    	for(int i=0;i<size;i++)
    	{
    		setarr[i]=oldset.setarr[i];
		}
	}
	void removeDuplicates()
	{
		for(int i=0;i<size;i++)
        { 
        	for(int j=i+1;j<size;j++)
        	{
        		if(setarr[i]==setarr[j])
        		{
        			for(int k=j;k<size;k++)
        			{
        				setarr[k]=setarr[k+1];
        			}
					size--;
					j--;
				}
			}
		}
		
		
	}

    void setElements()
    {
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<size;i++)
            cin>>setarr[i];
            this->removeDuplicates();
    }
    Myset<T> operator +(const Myset<T>& set2)
    {    int temparrsize=size+set2.size;
         Myset<T> temp(temparrsize);
        
        int k=0;
        for(int i=0;i<size;i++,k++)
        temp.setarr[k]=setarr[i];
        
        for(int j=0;j<set2.size;j++,k++)
        temp.setarr[k]=set2.setarr[j];
        temp.removeDuplicates();
		 return temp;
      

}
    Myset<T> operator -(const Myset<T>& set2)
    {   
      
	   	Myset<T> temp(size);
	    
        
	int flag=0,k,newsize=0;
		for(int j=0;j<size;j++)
		{
			flag=0;
			for(k =0;k<set2.size;k++)
			{
				if(this->setarr[j]==set2.setarr[k])
				flag=1;
			}
			if(flag==0)
			{
			  temp.setarr[newsize]=this->setarr[j];
			  newsize++;	
						
			}
			
		}
		temp.size=newsize;
	
		
       return temp;

    }
    Myset<T> operator *(const Myset<T>& set2)
    {  int newsize=0; 
       Myset<T> temp(size);
       for(int i=0;i<size;i++)
       { 
         for(int j=0;j<set2.size;j++)
         {
         	if(setarr[i]==set2.setarr[j])
         	{
         		temp.setarr[newsize]=setarr[i];
         		newsize++;
			 }
		 }
	   }
	   temp.size=newsize;
       
       return temp;
   }
   
   Myset<T> operator ^(const Myset<T>& set2)
    {   
       Myset<T> temp1(size);
       Myset<T> temp2(set2.size);
       for(int i=0;i<size;i++ ){temp1.setarr[i]=setarr[i];}
       for(int i=0;i<set2.size;i++ ){temp2.setarr[i]=set2.setarr[i];}
       return ((temp1+temp2)-(temp1*temp2));
      }
      
      
    void operator =(const Myset<T>& set)
    {
    	size=set.size;
    	for(int i=0;i<set.size;i++)
    	{
    		this->setarr[i]=set.setarr[i];
		}
		  }      
      bool operator ==(const Myset<T>& set2)
      {
      	if(size==set2.size)
      	{int flag=0;
      		for(int i=0;i<size;i++)
      		{
      			for(int j=0;j<set2.size;j++)
      			{
      				if(setarr[i]==set2.setarr[j])
      				{
      					flag++;
					  }
				  }
      			
			  }
			  if(flag==size)
			  return true;
			  else
			  return false;
		  }
      	else
      	return false;
      	
	  }
	  void powerset()
	  {cout<<"{ ";
	  	for(int i=0;i<pow(2,size);i++)
	  	{
	  		if(i>0)
	  	    cout<<" , { ";
	  	    else
	  	    cout<<" {";
	  	    int count =0;
	  	    for(int t=i,j=0;j<size;j++)
	  	    {
	  	    	if(t&1)
	  	    	{
				  if(count>=1)
				  cout<" , ";
				  cout<<setarr[j]<<" ";
				  count++;
				  }
				  t=t>>1;
			  }cout<<" } ";
		  }
		  cout<<" }";
	  }
      
      void display()
      {
      	
      	cout<<"{ ";
      	for(int i=0;i<size;i++)
      	{cout<<setarr[i]<<" ,";
		  }
		  cout<<"\b"<<"}"<<endl;
	  }
      
     };
int main()
{  int ch, size1,size2;;
   cout<<"Which datatype do you want to enter for set elements."<<endl<<"1.Int"<<endl<<"2.char"<<endl;
   cout<<"3.Double"<<endl<<"4.Float"<<endl;
   cin>>ch;
   switch(ch)
   {
   	case 1 :{
   	cout<<"Enter the number of elements in first set"<<endl;
   	cin>>size1;
   	cout<<"Enter the number of elements in second set "<<endl;
   	cin>>size2;
	   Myset<int> set1(size1);
	   Myset<int> set2(size2);
	   set1.setElements();
	   set2.setElements();
	   cout<<"Union of these two sets is -";
	    Myset<int> Union(set1+set2);
		
	    Union.display();
	    cout<<"Difference of these two sets is -";
	    Myset<int> Diff(set1-set2);
		
	    Diff.display();
	    cout<<"Intersection of these two sets is -";
	    Myset<int> intersct(set1*set2);
		
	    intersct.display();
	    cout<<"Symetric difference of these two sets is -";
	     Myset<int> symdiff(set1^set2);
		
	    symdiff.display();
	    cout<<"Checking equality of two sets."<<endl;
	    if(set1==set2)
	    cout<<"Yes, sets are equal."<<endl;
	    else
	    cout<<"No sets are not equal."<<endl;
	    cout<<"Values of which set you want to assign to set3"<<endl<<"Enter 1 or 2.";
	    int c;
	    Myset<int> set3; 
	    cin>>c;
	    if(c==1)
	    {
	    	set3=set1;
	    	set3.display();
	    	cout<<"All values of set1 are assigned to set 3.";
	    	
		}
		else
		{set3=set2;
	    	set3.display();
	    	cout<<"All values of set2 are assigned to set 3.";
			
		}
		cout<<endl<<"Power set of set1."<<endl;
		set1.powerset();
		cout<<endl;
		cout<<"power set of set2."<<endl;
   		set2.powerset();
		break;
	   }
	   case 2:{
	   	cout<<"Enter the number of elements in first set"<<endl;
   	cin>>size1;
   	cout<<"Enter the number of elements in second set "<<endl;
   	cin>>size2;
	   Myset<char> set1(size1);
	   Myset<char> set2(size2);
	   	   set1.setElements();
	   set2.setElements();
	   cout<<"Union of these two sets is -";
	    Myset<char> Union(set1+set2);
		
	    Union.display();
	    cout<<"Difference of these two sets is -";
	    Myset<char> Diff(set1-set2);
		
	    Diff.display();
	    cout<<"Intersection of these two sets is -";
	    Myset<char> intersct(set1*set2);
		
	    intersct.display();
	    cout<<"Symetric difference of these two sets is -";
	    Myset<char> symdiff(set1^set2);
		
	    symdiff.display();
	    cout<<"Checking equality of two sets."<<endl;
	    if(set1==set2)
	    cout<<"Yes, sets are equal."<<endl;
	    else
	    cout<<"No sets are not equal."<<endl;
	    cout<<"Values of which set you want to assign to set3"<<endl<<"Enter 1 or 2.";
	    int c;
	    Myset<char> set3; 
	    cin>>c;
	    if(c==1)
	    {
	    	set3=set1;
	    	set3.display();
	    	cout<<"All values of set1 are assigned to set 3.";
	    	
		}
		else
		{set3=set2;
	    	set3.display();
	    	cout<<"All values of set2 are assigned to set 3.";
			
		}
		cout<<endl<<"Powerset of set1."<<endl;
		set1.powerset();
		cout<<endl<<"powerset of set2."<<endl;
   		set2.powerset();
		
   		
		break;
	   }
	   case 3:{
	   	cout<<"Enter the number of elements in first set"<<endl;
   	cin>>size1;
   	cout<<"Enter the number of elements in second set "<<endl;
   	cin>>size2;
	   Myset<double> set1(size1);
	   Myset<double> set2(size2);
	   	   set1.setElements();
	   set2.setElements();
	   cout<<"Union of these two sets is -";
	    Myset<double> Union(set1+set2);
		
	    Union.display();
	    cout<<"Difference of these two sets is -";
	    Myset<double> Diff(set1-set2);
	    Diff.display();
	    cout<<"Intersection of these two sets is -";
	    Myset<double> intersct(set1*set2);
	    intersct.display();
	    cout<<"Symetric difference of these two sets is -";
	    Myset<double> symdiff(set1^set2);
	    symdiff.display();
	    cout<<"Checking equality of two sets."<<endl;
	    if(set1==set2)
	    cout<<"Yes, sets are equal."<<endl;
	    else
	    cout<<"No sets are not equal."<<endl;
	    cout<<"Values of which set you want to assign to set3"<<endl<<"Enter 1 or 2.";
	    int c;
	    Myset<double> set3; 
	    cin>>c;
	    if(c==1)
	    {
	    	set3=set1;
	    	set3.display();
	    	cout<<"All values of set1 are assigned to set 3.";
	    	
		}
		else
		{set3=set2;
	    	set3.display();
	    	cout<<"All values of set2 are assigned to set 3.";
			
		}
		cout<<endl<<"Power set of set1."<<endl;
		set1.powerset();
		cout<<endl<<"power set of set2."<<endl;
   		set2.powerset();
		
   		
		break;
	   }
	   case 4:{
	   	cout<<"Enter the number of elements in first set"<<endl;
   	cin>>size1;
   	cout<<"Enter the number of elements in second set "<<endl;
   	cin>>size2;
	   Myset<float> set1(size1);
	   Myset<float> set2(size2);
	   	   set1.setElements();
	   set2.setElements();
	   cout<<"Union of these two sets is -";
	    Myset<float> Union(set1+set2);
		
	    Union.display();
	    cout<<"Difference of these two sets is -";
	    Myset<float> Diff(set1-set2);
	    Diff.display();
	    cout<<"Intersection of these two sets is -";
	    Myset<float> intersct(set1*set2);
	    intersct.display();
	    cout<<"Symetric difference of these two sets is -";
	    Myset<float> symdiff(set1^set2);
	    symdiff.display();
	    cout<<"Checking equality of two sets."<<endl;
	    if(set1==set2)
	    cout<<"Yes, sets are equal."<<endl;
	    else
	    cout<<"No sets are not equal."<<endl;
	    cout<<"Values of which set you want to assign to set3"<<endl<<"Enter 1 or 2.";
	    int c;
	    Myset<float> set3; 
	    cin>>c;
	    if(c==1)
	    {
	    	set3=set1;
	    	set3.display();
	    	cout<<"All values of set1 are assigned to set 3.";
	    	
		}
		else
		{set3=set2;
	    	set3.display();
	    	cout<<"All values of set2 are assigned to set 3.";
			
		}
		cout<<endl<<"Power set of set1."<<endl;
		set1.powerset();
		cout<<endl<<"power set of set2."<<endl;
   		set2.powerset();
		
   		
		break;
	   }
   }
   	
   	
   
	return 0;
}


