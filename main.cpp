#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	// ũ�ξ�Ƽ�� ���ĺ��� #���� ������ �� str�� ���̸� ��� �ȴ�.
	for (int i = 0; i < v.size(); i++) {
		while (true) {
			size_t idx = str.find(v[i]);
			if (idx == string::npos) break;

			str.replace(idx, v[i].length(), "#");
		}
	}

	cout << str.length() << endl;
}