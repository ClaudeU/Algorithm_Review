#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int game[20][21];
int h, w, test, ch;

int Lshape[4][3][2] = { //L�� ����� ����� ��
    { { 0, 0 }, { 0, 1 }, { 1, 1 } }, // case 1 : (i, j), (i, j+1), (i+1, j+1) // �� ���
    { { 0, 0 }, { 0, 1 }, { 1, 0 } }, // case 2 : (i, j), (i, j+1), (i+1, j)   // �¿���� �� ���
    { { 0, 0 }, { 1, 0 }, { 1, 1 } }, // case 3 : (i, j), (i+1, j), (i+1, j+1) // �� ���
    { { 0, 0 }, { 1, 0 }, { 1, -1 }}  // case 4 : (i, j), (i+1, j-1), (i+1, j) //  �¿���� �� ���
};

bool put(int type, int x, int y) { //�Է¹��� ��ǥ�� ���� ���� �� �ִ� �� Ȯ��.

    int px, py; //��ǥ��
    bool isPut = true;
    for(int i = 0; i < 3; i++) {
        px = x + Lshape[type][i][1];
        py = y + Lshape[type][i][0];
        if (px < 0 || py < 0 || px >= w || py >= h)
            isPut = false;
    }
    return isPut;
}

int cover()
{   int num = 0; // �� ĭ�� ���� ����� ��
    int cover_x = -1;
    int cover_y = -1;
    for (int i = 0; i < h; i++)  {
        for (int j = 0; j < w; j++) {
            if (game[i][j] == 0) { //��ĭ�̶�� ���� ��ġ�� cx,cy�� �����ϰ� break
                cover_x = j;
                cover_y = i;
                goto Continued;
            }
        }
    }
    Continued:
    for(int type = 0; type < 4; type++) { //L ���� �� 4���� ��翡 ���� �����ǿ� ���� �� �ִ��� �˾ƺ���.
        if(put(type,cover_x, cover_y) == true)
            num += cover();
        put(type,cover_x, cover_y);
    }
    return num;
}

int main()
{
    scanf("%d", &test); //�׽�Ʈ���̽� �Է�.
    while(test--) {
        scanf("%d %d", &h, &w); // H X W �Է�
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%c", &ch);   // �������� ���(# . ) �Է�
                if (ch == '.')
                    game[i][j] = 0; //��ĭ
                else if (ch == '#')
                    game[i][j] = 1; //����ĭ
            }
        }
        printf("%d \n", cover()); // L���� �� ĭ�� ��� ���� ����� �� ���
    }
}
