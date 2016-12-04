#include<iostream>
#include<map>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int C, N;

map<int, int> applicants;

void remove(int p, int q) {
	map<int, int>::iterator it_f, it_b;
	it_f = it_b = applicants.find(p);

	while (it_b != applicants.begin()) {
		--it_b;
		if (it_b->second < q) {
			it_b = applicants.erase(it_b);
		}
		else
			break;

	}

	// index�� 1�� �ٿ����� q�� ���� ���Ҹ� ��� �����.

	//index�� 1�� �÷����� q�� ū ���Ұ� �ϳ��� ������ ���� �߰��� ���Ҹ� �����.
	if (++it_f != applicants.end() && it_f->second > q)
		applicants.erase(p);
}

int main() {

	scanf("%d", &C);

	for (int i = 0; i < C; ++i) {

		scanf("%d", &N);
		int sum = 0;

		for (int j = 0; j < N; ++j) {

			int p, q; scanf("%d%d", &p, &q);
			applicants[p] = q; //map Ư���� ���� �Ϸ�.
			remove(p, q);
			sum += applicants.size();
		}

		cout << sum << endl;
		applicants.clear();

	}
}