#include <iostream>
#include <fstream>
//#include <sys/tpes.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{

	ifstream inFile;
	inFile.open("test.txt");
	if(inFile.fail())
	{
	cerr << "error" << endl;
	exit(1);
	}

	std::string s = ""; 
	std::string iv = "";
	vector<bool> TF;
	vector<string>inputvar;
	while(inFile)
	{
		
		if (s == "input_var"){ 
			inFile >> iv;
			cout << iv << endl;}	
		if (s == "T"){
		TF.push_back(true);}
		else if( s == "F"){
		TF.push_back(false);}
		inFile >> s;
	}
	
	for (int x = 0; x < 3; x++) //just to check its working
	{
	cout<< TF.at(x) <<endl;}
	/*int x = 0;
	while(ss.good() )
	{
	getline(ss, s, ',');
	inputvar.push_back(s);
	x++;
	cout<<inputvar.at(x)<<endl;}*/

	


	return 0;
}



