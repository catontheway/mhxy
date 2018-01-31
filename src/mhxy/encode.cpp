#include "encode.h"
#include<fstream>
#include "global.h"

using namespace std;

encode::encode()
{
	for (int i = 0; i < 10; i++)
		key.push_back(i);
}


encode::~encode()
{
}

void encode::filecode(string filename, string result)
{
	ifstream fin(filename);
	ofstream fout(result);
	string res;
	ostringstream oss;
	const int LINE_LENGTH = 10000;//道具数据长度可能比较长 暂时用10000长度读取，否则道具加密解密不完整 导致坏档
	char str[LINE_LENGTH];
	//先将所有的数据加密写入oss
	while (fin.getline(str, LINE_LENGTH))
	{
		res = Makecode(str);
		oss << res<<endl;
	}
	//再将oss中所有数据一次性写入文件
	fout << oss.str() << endl;
}
void encode::fileuncode(string filename, string result)
{
	ifstream fin(filename);
	ofstream fout(result);
	string res;
	const int LINE_LENGTH = 10000;//道具数据长度可能比较长 暂时用10000长度读取，否则道具加密解密不完整 导致坏档
	char str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		res = Cutecode(str);
		fout << res << endl;
	}
}

//加密
string encode::Makecode(string pstr) {
	return pstr;
	int len = pstr.length();//获取长度
	for (int i = 0; i<len; i++)
		pstr[i] = MakecodeChar(pstr[i], key[i % 5]);
	return pstr;
}

//解密
string encode::Cutecode(string pstr) {
	return pstr;
	int len = pstr.length();
	for (int i = 0; i<len; i++)
		pstr[i] = CutcodeChar(pstr[i], key[i % 5]);
	return pstr;
}

//单个字符异或运算
char encode::MakecodeChar(char c, int key) {
	return c = c^key;
}
//单个字符解密
char encode::CutcodeChar(char c, int key) {
	return c^key;
}
