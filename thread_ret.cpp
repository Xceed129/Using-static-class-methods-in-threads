#include <iostream>
#include <thread>
#include <string>
#include <future>
using namespace std;

class Task1{
  public:
	static void execute(string command1, string command2, promise<int> &&ret_val){
		cout << command1 << " " << command2 << endl;
		//Set the value first
		if(command2 == "Hello World!"){
			ret_val.set_value(0);
      		}else{
        		ret_val.set_value(1);
      		}
      		//then exit thread
	}
};

int main(){

  	//make a promise with the threads you create
  	promise<int> Aprms, Bprms;
  	future<int> Aftr = Aprms.get_future(), Bftr = Bprms.get_future();

  	//Create threads
  	//move the promise to those threads you create
	thread thA(&Task1::execute, "Sample Task1", "Hello World!", move(Aprms));
  	thread thB(&Task1::execute, "Sample Task2", "Hi World!", move(Bprms));

  	//check the future state then join
  	int Aret = Aftr.get(), Bret = Bftr.get(); //.get() locks the main thread and waits until the promise has a set value	
	thA.join();
  	thB.join();

  	cout << "Thread A returned a value of " << Aret << endl;
  	cout << "Thread B returned a value of " << Bret << endl;

	return 0;
}
