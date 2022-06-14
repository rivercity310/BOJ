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
	// 문자열 입력받기 
	// 1. cin.getline(buff, count, delimit)
	char address[100];
	cin.getline(address, sizeof(address), '\n');
	cout << "주소는 " << address << "입니다.\n";

	// 2. string 클래스
	string song("falling in love with you");
	cout << song << endl;
	string addr;
	getline(cin, addr);
	cout << "주소는 " << addr << "입니다.\n";



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

	// boolalpha: bool 출력 (0 -> false, 1 -> true)
	bool a = true;
	bool b = false;
	cout << a << ' ' << b << endl;
	cout << boolalpha << a << ' ' << b << endl;



	// vector 초기화
	vector<int> w(10, 1);
	prt_vector(w);

	w.resize(20);
	prt_vector(w);

	w.erase(w.begin(), w.begin() + 3);
	prt_vector(w);

	int n = 10;
	int x = 1;
	vector<int> v(n);		// 0으로 n개 생성
	vector<int> v2(n, x);	// x로 n개 원소 생성
	v.resize(n * 2);		// vector 사이즈 키우기

	// vector 삭제
	int index = 0;
	int s = 0, e = 2;
	v.erase(v.begin() + index);    // index 위치에 있는 데이터 삭제하기
	v.erase(v.begin() + s, v.begin() + e);   // s부터 e - 1까지의 인덱스 삭제




	// 문자열 자르기
	// 1. string 클래스 사용할 때 (find, substr 함수 사용)
	string lines = "hello,my,name,is";
	size_t previous = 0;
	size_t current = lines.find(',');       // 찾지 못한경우 npos 반환

	while (current != string::npos) {
		string substring = lines.substr(previous, current - previous);
		cout << substring << " ";

		previous = current + 1;
		current = lines.find(',', previous);
	}
	cout << lines.substr(previous, current - previous) << endl;


	// 2. sstream 클래스 사용할 때 (stringstream 사용, sstream 헤더파일)
	// 공백을 기준으로 split한다.
	string lines2 = "hwang seung su";
	string tmp;
	stringstream ss;

	ss.str(lines2);
	while (ss >> tmp) cout << tmp << " ";
	cout << endl;

	stringstream ss2;
	string lines3 = "010 4935 4392";
	string tmp2;			// int형 혹은 string형
	ss2.str(lines3);
	while (ss2 >> tmp2) cout << tmp2 << " ";
	cout << endl;




	// 대소문자 변환 (transform 함수 algorithm 헤더파일)
	string word = "HELLO";
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	cout << word << endl;

	for (int i = 0; i < word.size(); i++)
		word[i] = ::toupper(word[i]);
	cout << word << endl;




	// 특정 문자열 찾기
	string lines4 = "hello my name is seungsu";
	string f_word = "seungsu";

	int pos2 = lines4.find(f_word);
	while (pos2 != string::npos) {
		cout << lines4.substr(pos2, f_word.size()) << "\n";
		pos2 = lines4.find(f_word, pos2 + f_word.size());
	}




	// 알파벳 제외 특수문자 공백으로 바꾸기
	string lines5 = "h{el@@lo \tmy \"namelo<<e is siy{eo>>>n";
	replace_if(lines5.begin(), lines5.end(), wordChange, ' ');
	cout << lines5 << endl;
}

// '이거나 알파벳이 아닌경우 true 리턴 (이스케이프 문자)
bool wordChange(char c) {
	return c == '\'' || !isalpha(c);
}