#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
[ũ�ξ�Ƽ�� ���ĺ� ����]

Ǯ��: ũ�ξ�Ƽ�� ���ĺ��� �ش��ϴ� ���ڿ��� replace �Լ��� ���� ���� 1¥�� ���ڷ� ��ġ -> ��ġ�� ���ڿ� ���̸� ����
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

