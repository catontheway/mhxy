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
	const int LINE_LENGTH = 10000;//�������ݳ��ȿ��ܱȽϳ� ��ʱ��10000���ȶ�ȡ��������߼��ܽ��ܲ����� ���»���
	char str[LINE_LENGTH];
	//�Ƚ����е����ݼ���д��oss
	while (fin.getline(str, LINE_LENGTH))
	{
		res = Makecode(str);
		oss << res<<endl;
	}
	//�ٽ�oss����������һ����д���ļ�
	fout << oss.str() << endl;
}
void encode::fileuncode(string filename, string result)
{
	ifstream fin(filename);
	ofstream fout(result);
	string res;
	const int LINE_LENGTH = 10000;//�������ݳ��ȿ��ܱȽϳ� ��ʱ��10000���ȶ�ȡ��������߼��ܽ��ܲ����� ���»���
	char str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		res = Cutecode(str);
		fout << res << endl;
	}
}

//����
string encode::Makecode(string pstr) {
	return pstr;
	int len = pstr.length();//��ȡ����
	for (int i = 0; i<len; i++)
		pstr[i] = MakecodeChar(pstr[i], key[i % 5]);
	return pstr;
}

//����
string encode::Cutecode(string pstr) {
	return pstr;
	int len = pstr.length();
	for (int i = 0; i<len; i++)
		pstr[i] = CutcodeChar(pstr[i], key[i % 5]);
	return pstr;
}

//�����ַ��������
char encode::MakecodeChar(char c, int key) {
	return c = c^key;
}
//�����ַ�����
char encode::CutcodeChar(char c, int key) {
	return c^key;
}
