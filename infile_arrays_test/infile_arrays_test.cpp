#include"pch.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class Users
{
private:
	string name;
	string userid;
	string password;
public:
	void setUser(string nm, string id, string psw);
	void display();
};

//string randomID()
//{
//	string r;
//	srand(int(time(0)));
//	r = rand() % 100 + 100;
//	return r;
//};

int main()
{
	string nm;
	string id;
	string psw;
	int n = 0;

	ofstream outfile("infile_arrays_test", ios::app);

	while (!outfile)
		cout << "ERROR" << endl;

	Users *p_user = new Users[n];

	cout << "Please Complete Information:" << endl;
	cout << "Enter Your Name:\nEnd With 'Enter'" << endl;
	while (!getline(cin, nm))
		cout << "NAME ERROR" << endl;
	//id = randomID();
	//cout << "This is Your ID:\n" << id << "\n" << "PLEASE TAKE DOWN" << endl;
	cout << "Set Your ID:\n" << endl;
	while (!getline(cin, id))
		cout << "ID ERROR" << endl;
	cout << "Set Your PassWord:\n" << endl;
	while (!getline(cin, psw))
		cout << "PSW ERROR" << endl;
	outfile << nm << " ";
	outfile << id << " ";
	outfile << psw << "\n";


	outfile.close();

	ifstream infile("infile_arrays_test", ios::in);

	if (infile)
		cout << "OPEN SUCCEED" << endl;

	//while (getline(infile, nm) && getline(infile, id) && getline(infile, psw))
	while(infile>>nm>>id>>psw)
	{
		p_user[n++].setUser(nm, id, psw);
		cout << "READ SUCCEED" << endl;
	}
	for (int i = 0; i <= n; i++)
		p_user[i].display();

	cout << "DISPLAY SUCCEED" << endl;

	delete[]p_user;

	infile.close();

	return 0;

};
void Users::display()
{
	cout << name<<" "<< userid <<" "<< password <<" "<< endl;
};

void Users::setUser(string nm, string id, string psw)
{
	name = nm;
	userid = id;
	password = psw;

};

