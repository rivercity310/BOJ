#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
[크로아티안 알파벳 문제]

풀이: 크로아티안 알파벳에 해당하는 문자열을 replace 함수를 통해 길이 1짜리 문자로 대치 -> 대치된 문자열 길이를 구함
*/

void ex2941() {
	string str;
	cin >> str;

	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	for (int i = 0; i < v.size(); i++) {
		while (true) {
			size_t idx = str.find(v[i]);
			if (idx == string::npos) break;

			str.replace(idx, v[i].length(), "#");
		}
	}

	cout << str.length() << endl;
}

