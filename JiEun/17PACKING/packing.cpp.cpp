#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> //max
#include <vector>
#include <string>  

using namespace std;

int c, n, capacity; //�׽�Ʈ���̽�, ���ǰ���, �뷮 �Է¹ޱ�
string name[100]; int volume[100], need[100]; //���� ����
int cache[1001][100];

int pack(int capacity, int item) { //�ִ밡��ġ�� ���ϱ� pack(capacity, 0) 
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	ret = pack(capacity, item + 1);// ������ ���� ���� ��� 
	if (capacity >= volume[item]) 	// ������ ��� ��� 
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) { //���õ� �����۱��ϱ� reconstruct(capacity, 0, picked); 
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else { //�������� ���õǾ��� ��. 
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	scanf("%d", &c);
	while (c--) {
		scanf(" %d %d", &n, &capacity);
		for (int j = 0; j < n; ++j)
			cin >> name[j] >> volume[j] >> need[j];
		memset(cache, -1, sizeof(cache)); //cache�迭 �ʱ�ȭ
		vector<string> picked;
		reconstruct(capacity, 0, picked); //���õ� ������ picked vector�� ���
		cout << pack(capacity, 0) <<" "<< picked.size() << endl; // maxCapacity�� maxItemNum���� ���
		for (int j = 0; j < picked.size(); ++j)
			cout << picked[j] << endl; // ���õ� �����۵� �̸� ���
	}
	return 0;
}


