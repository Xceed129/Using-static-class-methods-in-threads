#include <iostream>
#include <thread>
#include <string>

class Task1{
  public:
	  static int execute(std::string command1, std::string command2){

		  std::cout << command1 << " " << command2 << std::endl;

      return 0;
	  }

};

int main(){
	
	std::thread th1(&Task1::execute, "Sample Task", "Hello World!");

	th1.join();

	return 0;
}
