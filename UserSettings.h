#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


using namespace std;

namespace bl
{

class UserSettings
{
public:
	UserSettings();
	~UserSettings();

private:
	string filePath_;
	ifstream fin_;
	ofstream fout_;

};

}