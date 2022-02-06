#include "LinkedList.h"
#include "fstream"
#include "iostream"
#include "string"

//Note to instructors, in EECS268 we created a templated linked list and templated node class
//I took the templated classes and adapted it to suit our lab needs, and making it only take integers.
int main(int argc, char* argv[])
{
  LinkedList newList;
  std::ifstream inFile;
	inFile.open(argv[1]);
  std::string filename = argv[1];
	if(inFile.is_open())
	{
    //while (inFile >> command)
    std::cout << "infile has been opened\n\n";
    int newNum = 0;
    while(inFile >> newNum){
      newList.insert(1, newNum);
    }
  }
  inFile.close();



  bool keepgoing = true;
  do{
  int option = 0;
  std::cout << "Please choose one of the following commands:\n1) IsEmpty()\n2) Length()\n3) Insert(x)\n4) Delete(x)\n5) Find(x)\n6) AppendList(newLinkedList)\n7) Print()\n8) ReverseList()\n9) Exit\n";
  std::cin >> option;
  switch(option){
  case 1:
  std::cout << "--IsEmpty()\n";
  newList.isEmpty();
  continue;
  case 2:
  std::cout <<"--Length()\n";
  std::cout << "Length of given list is: " << newList.length() << "\n";
  continue;
  case 3:
  std::cout <<"--Insert(x)\n";
  std::cout <<"What number would you like to insert?: ";
  int toadd;
  std::cin >> toadd;
  newList.insert(1, toadd);
  continue;
  case 4:
  std::cout <<"--Delete(x)\n";
  std::cout <<"What number would you like to delete?";
  int deletion;
  std::cin >> deletion;
  newList.findindexfordelete(deletion);
  continue;
  case 5:
  std::cout <<"--Find()\n";
  std::cout <<"What number would you like to search for?: ";
  int targetnum;
  std::cin >> targetnum;
  if(newList.findindex(targetnum) == true){
    std::cout << "Number is present in the array.\n";
  }
  else{
    std::cout << "Number is NOT present in the array.\n";
  }
  continue;
  case 6:
  std::cout <<"--AppendList()\n";
  newList.append(filename);
  continue;
  case 7:
  std::cout <<"--Print()\n";
  newList.print();
  continue;
  case 8:
  std::cout <<"--ReverseList()\n";
  newList.reverse();
  continue;
  case 9:
  std::cout <<"--Exiting...\n";
  keepgoing = false;
  break;
}
}while(keepgoing);
}
