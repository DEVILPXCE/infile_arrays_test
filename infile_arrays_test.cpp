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
	string idd;
	string password;
public:
	//Users();
	//~Users();
	void setUser(string nm, string id, string psw);
	void display();
	//void registe();
};

string randomID()
{
	string r;
	srand(int(time(0)));
	r = rand() % 10000 + 10000;
	return r;
};

int main()
{
	string nm;
	string id;
	string psw;
	int n = 0;

	ofstream outfile("infile_arrays_test", ios::app);

	Users *p_user = new Users[n];

	cout << "Please Complete Information:" << endl;
	cout << "Enter Your Name:\nEnd With 'Enter'" << endl;
	while (!getline(cin, nm))
		cout << "NAME ERROR" << endl;
	id = randomID();
	cout << "This is Your ID:\n" << id << "\n" << "PLEASE TAKE DOWN" << endl;
	cout << "Set Your PassWord:\n" << endl;
	while (!getline(cin, psw))
		cout << "PSW ERROR" << endl;
	outfile << nm << id << psw;


	outfile.close();

	ifstream infile("infile_arrays_test", ios::in);

	if (!infile)
		cout << "OPEN ERROR" << endl;

	while (getline(infile, nm) && getline(infile, id) && getline(infile, psw))
		p_user[n++].setUser(nm, id, psw);

	for (int i = 0; i <= n; i++)
		p_user[i].display();

	cout << "READ SUCCESS" << endl;

	delete[]p_user;

	infile.close();

	return 0;

};

void Users::setUser(string nm, string id, string psw)
{
	name = nm;
	idd = id;
	password = psw;

};
void Users::display()
{
	cout << name << idd << password << endl;
};