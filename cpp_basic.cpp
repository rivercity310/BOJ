#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
bool wordChange(char c);

void prt_vector(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}


void cpp_basic() {
	// ���ڿ� �Է¹ޱ� 
	// 1. cin.getline(buff, count, delimit)
	char address[100];
	cin.getline(address, sizeof(address), '\n');
	cout << "�ּҴ� " << address << "�Դϴ�.\n";

	// 2. string Ŭ����
	string song("falling in love with you");
	cout << song << endl;
	string addr;
	getline(cin, addr);
	cout << "�ּҴ� " << addr << "�Դϴ�.\n";



	// int->str
	int num1 = 10;
	string str = to_string(num1);
	cout << "int->str ";
	cout << str << endl;

	// str->int
	string str2 = "100";
	int num2 = atoi(str2.c_str());
	cout << "str->int ";
	cout << num2 << endl;

	// str->char
	string str4 = "hello";
	char cst1[6];
	strcpy_s(cst1, sizeof(cst1), str4.c_str());
	cout << cst1 << endl;

	// char->str
	char cst2[] = "hello";
	string str3 = cst2;
	cout << str3 << endl;

	// boolalpha: bool ��� (0 -> false, 1 -> true)
	bool a = true;
	bool b = false;
	cout << a << ' ' << b << endl;
	cout << boolalpha << a << ' ' << b << endl;



	// vector �ʱ�ȭ
	vector<int> w(10, 1);
	prt_vector(w);

	w.resize(20);
	prt_vector(w);

	w.erase(w.begin(), w.begin() + 3);
	prt_vector(w);

	int n = 10;
	int x = 1;
	vector<int> v(n);		// 0���� n�� ����
	vector<int> v2(n, x);	// x�� n�� ���� ����
	v.resize(n * 2);		// vector ������ Ű���

	// vector ����
	int index = 0;
	int s = 0, e = 2;
	v.erase(v.begin() + index);    // index ��ġ�� �ִ� ������ �����ϱ�
	v.erase(v.begin() + s, v.begin() + e);   // s���� e - 1������ �ε��� ����




	// ���ڿ� �ڸ���
	// 1. string Ŭ���� ����� �� (find, substr �Լ� ���)
	string lines = "hello,my,name,is";
	size_t previous = 0;
	size_t current = lines.find(',');       // ã�� ���Ѱ�� npos ��ȯ

	while (current != string::npos) {
		string substring = lines.substr(previous, current - previous);
		cout << substring << " ";

		previous = current + 1;
		current = lines.find(',', previous);
	}
	cout << lines.substr(previous, current - previous) << endl;


	// 2. sstream Ŭ���� ����� �� (stringstream ���, sstream �������)
	// ������ �������� split�Ѵ�.
	string lines2 = "hwang seung su";
	string tmp;
	stringstream ss;

	ss.str(lines2);
	while (ss >> tmp) cout << tmp << " ";
	cout << endl;

	stringstream ss2;
	string lines3 = "010 4935 4392";
	string tmp2;			// int�� Ȥ�� string��
	ss2.str(lines3);
	while (ss2 >> tmp2) cout << tmp2 << " ";
	cout << endl;




	// ��ҹ��� ��ȯ (transform �Լ� algorithm �������)
	string word = "HELLO";
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	cout << word << endl;

	for (int i = 0; i < word.size(); i++)
		word[i] = ::toupper(word[i]);
	cout << word << endl;




	// Ư�� ���ڿ� ã��
	string lines4 = "hello my name is seungsu";
	string f_word = "seungsu";

	int pos2 = lines4.find(f_word);
	while (pos2 != string::npos) {
		cout << lines4.substr(pos2, f_word.size()) << "\n";
		pos2 = lines4.find(f_word, pos2 + f_word.size());
	}




	// ���ĺ� ���� Ư������ �������� �ٲٱ�
	string lines5 = "h{el@@lo \tmy \"namelo<<e is siy{eo>>>n";
	replace_if(lines5.begin(), lines5.end(), wordChange, ' ');
	cout << lines5 << endl;
}

// '�̰ų� ���ĺ��� �ƴѰ�� true ���� (�̽������� ����)
bool wordChange(char c) {
	return c == '\'' || !isalpha(c);
}