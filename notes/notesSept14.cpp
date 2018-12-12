#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv []) // argv is a pointer to a char array // argc number of args themselves
{
	ifstream in(argv[1]);
	
	if (in.fail())
	  {
	    cout << "File with name " << argv[1] << "was not found." << endl;
	  }
	
	if (argc < 2)
	{
	  cout << "Usage: " << argv[0] << "<filename>" << endl;
		cout << "Number of args: " << argc << endl;
		exit(1);
	}
	
	int count = 0;
	string word;
	
	while(in >> word)
	{
		count++;
	}

	string * words = new string[count];

    	cout << "Number of words: " << count << endl;
	
	in.clear(); // Clears the fail flag
	in.seekg(0, ios::beg); // Gets you back to the beginning of the file

	int index = 0;

	while (in >>word)
	  {
	    words[index] = word;
	    index++;
	  }
	for (int i = 0; i < count; i++)
	  {
	    cout << words[i] << endl;
	  }
	
	
