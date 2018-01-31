#pragma once
#include<iostream>
#include<string>
#include<vector>
class encode
{
private:
	 std::vector<int> key;
public:
	encode();
	~encode();
	void filecode(std::string filename,std::string result);
	void fileuncode(std::string filename,std::string result);
	std::string Makecode(std::string pstr);
	std::string Cutecode(std::string pstr);
	char MakecodeChar(char c, int key);
	char CutcodeChar(char c, int key);
};


