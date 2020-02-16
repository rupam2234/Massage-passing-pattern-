#include <iostream>
#include<vector>
using namespace std;


class INotify // Abstract class
{
	public:
	   virtual void notify(string msg)=0;

};

//Receiver class receives message from Event

class Receiver:public INotify
{
	string message;
	
public:
	void notify(string msg)
        {
		   message=msg;
	}   
	
	void test()
	{
		cout<<"Test Successful";
	}
	
	void display()
	{
		cout<<message;
	}
	
};

class Event:public INotify
{

public:
   Event()
   {
   	
   }

   void notify(string msg)
   {
       container[0]->notify(msg);
   }

   vector<INotify *>container;

   void add(INotify &obj)
   {
       container.push_back(&obj);
   }

};


int main()
{
	Receiver recObj;    //Create receiver object
	
	Event eventObj;     //create event object
	
	eventObj.add(recObj);   //adds reference of receiver object in container
	
	eventObj.notify("Test Test"); //sends message to receiver object's notify method
	
	recObj.display();   //displays the message from receiver
}
