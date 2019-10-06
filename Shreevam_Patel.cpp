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
	vector<string>alllines;
	vector<char>inputvar;
	vector<char>TF;
	vector<string>temp; //vertex variables and values 
	vector<string>in;
	vector<string>out;
 	int x = 0;
	int y = 0;


	getline(inFile, s, ';');
		alllines.push_back(s); //gets first line with variables
	getline(inFile, s, ';');
		alllines.push_back(s); //gets second line with variable values

	while(s != "a") //using infile to seperate out vertex variables anf values into an vector
	{
		inFile >> s;
		temp.push_back(s);
	}
	temp.pop_back();//removes last unwated value from temp

	in.push_back(s); //the first value after vector variables put into in vector
	while(inFile) //seperate remaining file into input and output vector
	{
		getline(inFile, s, ';');
		for(auto c:s){
		y++;
		if(c == '-'){
		in.push_back(s.substr(x,y-1));
		out.push_back(s.substr(y+1,s.length()));
		x=y;}}
		x = 0;
		y = 0;
	}
	
	for(auto c:alllines.at(0)){ //erases input_var from first line
	x++;
	if(c == ' ' ){
	alllines.at(0).erase(0,x);}}
	
	x = 0;
	for(auto c:alllines.at(0)){ //puts input variables into a char vertex inputvar
	if(c != ',' && c != ';'){
	inputvar.push_back(c);
	cout << inputvar.at(x) << endl;;
	x++;}}
	
	x = 0;	
	for(auto c:alllines.at(1)){ // puts all variables True or False value into TF vertex and prints
	if(c != ' '){
	TF.push_back(c);
	cout << TF.at(x) << " " ;
	x++;}}	

	cout << endl;
	in.erase(in.begin()+1); //erases blank space inside vertex
	for(int z = 0; z < out.size();z++){
	cout << in.at(z) << " and " << out.at(z)<< endl;} //prints out in vertex and out vertex
	
	cout << endl;
	for(x = 0; x < temp.size();x++){ //takes filler out of vertex variables and prints it
	if(temp.at(x) == "=" || temp.at(x) == "vertex"){
	temp.erase(temp.begin()+x);}
	cout << temp.at(x) << " ";}
	
	
	


///////////////////////////////////////////////////////////////////////////////////////////////////////// all of this junk parses the text file getting our variables and values


	int pid;
	int id = 0;
	//int fd[3][2];
	








	return 0;
}



