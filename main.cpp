#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	// 크로아티아 알파벳을 #으로 변경한 뒤 str의 길이를 재면 된다.
	for (int i = 0; i < v.size(); i++) {
		while (true) {
			size_t idx = str.find(v[i]);
			if (idx == string::npos) break;

			str.replace(idx, v[i].length(), "#");
		}
	}

	cout << str.length() << endl;
}