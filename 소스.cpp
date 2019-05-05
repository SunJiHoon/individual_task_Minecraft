#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")


int main() {


	BlockID glass = createBlock(BLOCK_GLASS);
	WoolID red = createWool(COLOR_RED);
	BlockID blue = createBlock(BLOCK_STAINED_GLASS);
	BlockID iron = createBlock(BLOCK_IRON);
	FlowerID TULIP = createFlower(FLOWER_RED_TULIP);
	BlockID air = createBlock(BLOCK_AIR);
	WoodID oak = createWood(WOOD_OAK, STRIP_EAST_WEST);
	BlockID stone = createBlock(BLOCK_STONE);
	BlockID grass = createBlock(BLOCK_GRASS);
	WoolID white = createWool(COLOR_WHITE);

	int x1, y1, z1;
	int x2, y2, z2 = 0;
	int p;
	double a, b, c;
	int xx1, yy1, zz1, xx2, yy2, zz2;

	printf("ù ��° ��ǥ�� �Է��ϼ���. : \n");
	scanf("%d %d %d", &x1, &y1, &z1);
	printf("�� ��° ��ǥ�� �Է��ϼ���. : \n");
	scanf("%d %d %d", &x2, &y2, &z2);

	if (x1 > x2) { p = x1; x1 = x2; x2 = p; }
	if (y1 > y2) { p = y1; y1 = y2; y2 = p; }
	if (z1 > z2) { p = z1; z1 = z2; z2 = p; }


	a = (1.0*x2 - 1.0*x1) / 150;
	b = (1.0*y2 - 1.0*y1) / 50;
	c = (1.0*z2 - 1.0*z1) / 143;



	///////////////////////

	////
	//�عٴ� ����
	////

	xx1 = x1, yy1 = y1, zz1 = z1;
	xx2 = x2, yy2 = y1, zz2 = z2;

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(stone, xx1, yy1, zz1);
			}
			zz1 = z1;
		}
		xx1 = x1;
	}

	////
	//310�� �κ�
	////

	xx1 = x1, yy1 = y1 + 1, zz1 = z2 - 60 * c;
	xx2 = x1 + 134 * a, yy2 = y2, zz2 = z2;

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(iron, xx1, yy1, zz1);
			}
			zz1 = z2 - 60 * c;
		}
		xx1 = x1;
	}

	yy1 = y1 + 1;
	//310�� ���_1_1
	for (; xx1 < xx2; xx1 = xx1 + 5) {//����� ũ�� ��ȭ�� ������ �ʾƼ� c�� ������ �ʴ´�.(������ �Ű澲�� �ʴ´�)
		for (yy1 = y1 + 1; yy1 < (yy1 + yy2) / 4 - 2; yy1++) {//(yy1 + yy2) / 4�� ������ ���̿� ����. ���⼭ ����� ���� ���̱��� �� ���̱� ������ �̰��� ����Ѵ�.
			locateBlock(stone, xx1, yy1, zz1);
			locateBlock(glass, xx1 + 1, yy1, zz1);
			locateBlock(red, xx1 + 2, yy1, zz1);
			locateBlock(glass, xx1 + 3, yy1, zz1);
			locateBlock(stone, xx1 + 4, yy1, zz1);
		}
	}
	yy1 = y1 + 1;
	zz1 = z2 - 60 * c;

	//310�� ���_1_2
	for (; xx1 < xx2; xx1++) {
		locateBlock(stone, xx1, (yy1 + yy2) / 8 + 2 * b, zz1);//���� �Ҽ����� �Ǹ� ���� �پ��� ��Ȯ�� ������ �߾ӿ� ���� �ʾҴ�. ���������� 2*b�� �����ָ� �߾� ���� ��������� �˾Ƽ� 2*b�� ���ߴ�.
	}
	xx1 = x1;

	//310�� ���_2_1(�������)
	for (; xx1 < xx2; xx1 = xx1 + 2) {//����� ũ�� ��ȭ�� ������ �ʾƼ� c�� ������ �ʴ´�.(������ �Ű澲�� �ʴ´�)
		for (yy1 = (y1 + 1 + y2) / 2; yy1 < yy2; yy1++) {//(y1 + 1 + y2) / 2�� ��ü ������ ���̴�. ���⼭ ����� ���� ���̱��� �� ���̱� ������ �̰��� ����Ѵ�.
			locateBlock(iron, xx1, yy1, zz1);
			locateBlock(glass, xx1 + 1, yy1, zz1);
		}
		yy1 = (yy1 + yy2) / 2;
	}
	yy1 = y1 + 1;
	xx1 = x1;

	//310�� ���_2_2(�������)
	for (yy1 = (yy1 + yy2) / 4; yy1 < yy2; yy1 = yy1 + 5) {
		for (xx1 = x1; xx1 < xx2; xx1++) {
			locateBlock(iron, xx1, yy1, zz1);
		}
	}
	xx1 = x1;
	yy1 = y1 + 1;


	//310�� ������ ���ؼ� ���� ���� �κ��� �κ��� �����Ѵ�.(������� ������� �����)

	for (; yy1 <= yy2; yy1++) {
		for (int i = 0; i < 60 * c; i++) {
			for (int j = 0; j <= i; j++) {
				locateBlock(air, xx1 + j, yy1, zz2 - i - 1);

			}
		}
	}

	yy1 = y1 + 1;

	//310�� ������ ���ؼ� ���� ���� �κ��� �κ��� �����Ѵ�.(������� ������� �����)

	for (; yy1 <= yy2; yy1++) {
		for (int i = 0; i < 60 * c; i++) {
			for (int j = 0; j <= i; j++) {
				locateBlock(air, xx2 - j, yy1, zz1 + i + 1);
			}
		}
	}
	yy1 = y1 + 1;

	//310���� ����� ���� ����� ������ ������ �մ´�
	for (; xx1 <= xx2; xx1++) {
		for (; yy1 <= (y1 + y2) / 4; yy1++) {
			locateBlock(air, xx1, yy1 + (y1 + y2) / 4, zz1);
			locateBlock(air, xx1, yy1 + (y1 + y2) / 4, zz1 + 4 * c);
		}
		yy1 = y1 + 1;
	}
	xx1 = x1;

	if (a != 0) { //a�� 0�ϰ�� �� ���� ���ѷ����� ������.
		for (; zz1 < z2 - 60 * c + 4 * c; zz1++) { //z2 - 60 * c;�� zz1�� ���� ����
			for (; xx1 <= xx2; xx1 = xx1 + 6 * a) {
				for (; yy1 <= (y1 + y2) / 4; yy1++) {
					locateBlock(air, xx1, yy1 + (y1 + y2) / 4, zz1);
					locateBlock(air, xx1 + 1, yy1 + (y1 + y2) / 4, zz1);
					locateBlock(air, xx1 + 2, yy1 + (y1 + y2) / 4, zz1);

				}
				yy1 = y1 + 1;
			}
			xx1 = x1;
		}
		zz1 = z2 - 60 * c;
	}


	////
	/*��� �κ�*/
	////

	xx1 = x2 - 95 * a, yy1 = y1, zz1 = z2 - 110 * c;
	xx2 = x2 - 20 * a, yy2 = y1, zz2 = z2 - 60 * c;



	//���

	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(grass, xx1, yy1, zz1);

			}
			zz1 = z2 - 110 * c;
		}
		xx1 = x2 - 95 * a;
	}

	yy1 = y1;



	//�� �߱�



	//�� �߱�_������

	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (75 * a) / 2, yy1, zz1 + 5 * c); }

	zz1 = z2 - 110 * c;



	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 5 * c); }
	zz1 = z2 - 110 * c;


	for (; zz1 <= zz2 - 10 * c; zz1++) { locateBlock(white, xx1 + (9 * 75 * a) / 10, yy1, zz1 + 5 * c); }
	zz1 = z2 - 110 * c;


	//�� �߱�_������

	for (; xx1 < xx2 - 2 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 5 * c); }
	xx1 = x2 - 95 * a;

	for (; xx1 < xx2 - 2 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz2 - 5 * c); }
	xx1 = x2 - 95 * a;


	//�� �߱�_���_����

	for (; zz1 <= zz2 - 30 * c; zz1++) { locateBlock(white, xx1 + 3 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	zz1 = z2 - 110 * c;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz1 + 15 * c); }
	xx1 = x2 - 95 * a;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + (75 * a) / 10, yy1, zz2 - 15 * c); }
	xx1 = x2 - 95 * a;

	//�� �߱�_���_������

	for (; zz1 <= zz2 - 30 * c; zz1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	zz1 = z2 - 110 * c;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz1 + 15 * c); }
	xx1 = x2 - 95 * a;
	for (; xx1 < xx2 - 8 * (75 * a) / 10; xx1++) { locateBlock(white, xx1 + 7 * (75 * a) / 10, yy1, zz2 - 15 * c); }
	xx1 = x2 - 95 * a;





	////
	/*���κп� �پ��ִ� (���� �� �ִ� ��)*/
	////

	xx1 = x2 - 95 * a, yy1 = y1, zz1 = z2 - 115 * c;
	xx2 = x2 - 20 * a, yy2 = y2, zz2 = z2 - 110 * c;


	for (; xx1 <= xx2; xx1++) {
		for (; zz1 <= zz2; zz1++)
		{
			locateBlock(grass, xx1, yy1, zz1);
		}
		zz1 = z2 - 115 * c;
	}
	xx1 = x2 - 95 * a;


	if (y2 > (y1 + 3)) {
		for (; xx1 < xx2 - 10 * a; xx1++)

		{
			yy1++;
			int z = z2 - 115 * c; //zz1�� ��
			for (zz1 = z + 2 * c; zz1 < z + 5 * c; zz1++)
			{
				locateBlock(oak, xx1 + 5 * a, yy1, zz1);
			}
			zz1 = z;
			yy1++;
			for (zz1 = z + 2 * c; zz1 < z + 4 * c; zz1++)
			{
				locateBlock(oak, xx1 + 5 * a, yy1, zz1);
			}
			zz1 = z;
			yy1++;
			for (zz1 = z + 2 * c; zz1 < z + 3 * c; zz1++)
			{
				locateBlock(oak, xx1 + 5 * a, yy1, zz1);
			}
			zz1 = z;
			yy1 = y1;
		}
	}

	zz1 = z2 - 115 * c;
	yy1 = y1;


	////
	/*��忡 �پ��ִ� ������ ������ �κ�*/
	////
	xx1 = x2 - 20 * a, yy1 = y1 + 1, zz1 = z2 - 110 * c;
	xx2 = x2, yy2 = y2, zz2 = z2 - 60 * c;


	//�����κ�

	for (; yy1 <= (yy2 + y1 + 1) / 4; yy1++) { //y1+1�̶� �� ���� yy1�̴�.
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(stone, xx1, yy1, zz1);
			}
			zz1 = z2 - 110 * c;
		}
		xx1 = x2 - 20 * a;
	}
	yy1 = y1 + 1;

	//���� ���_1
	for (; zz1 < zz2; zz1 = zz1 + 5) {//����� ũ�� ��ȭ�� ������ �ʾƼ� c�� ������ �ʴ´�.(������ �Ű澲�� �ʴ´�)

		for (yy1 = y1 + 1; yy1 < (yy1 + yy2) / 4 - 2; yy1++) {//(yy1 + yy2) / 4�� ������ ���̴�.
			locateBlock(stone, xx1, yy1, zz1);
			locateBlock(glass, xx1, yy1, zz1 + 1);
			locateBlock(red, xx1, yy1, zz1 + 2);
			locateBlock(glass, xx1, yy1, zz1 + 3);
			locateBlock(stone, xx1, yy1, zz1 + 4);
		}
	}
	yy1 = y1 + 1;
	zz1 = z2 - 110 * c;

	//���� ���_2
	for (; zz1 < zz2; zz1++) {
		locateBlock(stone, xx1, (yy1 + yy2) / 8 + 2 * b, zz1);//���� �Ҽ����� �Ǹ� ���� �پ��� ��Ȯ�� ������ �߾ӿ� ���� �ʾҴ�. ���������� 2*b�� �����ָ� �߾� ���� ��������� �˾Ƽ� 2*b�� ���ߴ�.

	}
	zz1 = z2 - 110 * c;



	//������ �κ�

	for (; xx1 <= xx2; xx1++) {
		for (; zz1 <= zz2; zz1++) {
			locateBlock(grass, xx1, (yy2 + yy1) / 4, zz1);
		}
		zz1 = z2 - 110 * c;
	}
	xx1 = x2 - 20 * a;

	if ((x2 - x1) > 5) {
		//������_������
		for (; zz1 < zz2 - 6; zz1 = zz1 + 4) {
			locateBlock(white, xx1 + 1, (yy2 + yy1) / 4, zz1 + 1);
			locateBlock(white, xx1 + 2, (yy2 + yy1) / 4, zz1 + 1);
			locateBlock(white, xx1 + 3, (yy2 + yy1) / 4, zz1 + 1);

			locateBlock(white, xx2 - 1, (yy2 + yy1) / 4, zz1 + 1);
			locateBlock(white, xx2 - 2, (yy2 + yy1) / 4, zz1 + 1);
			locateBlock(white, xx2 - 3, (yy2 + yy1) / 4, zz1 + 1);
		}
		zz1 = z2 - 110 * c;


		for (; zz1 < zz2 - 6; zz1++) {
			locateBlock(white, xx1, (yy2 + yy1) / 4, zz1 + 1);
			locateBlock(white, xx2, (yy2 + yy1) / 4, zz1 + 1);
		}
	}
	////
	/*208�� �κ�*/
	////
	xx1 = x1 + 22 * a, yy1 = y1 + 1, zz1 = z1 + 13 * c;
	xx2 = x2 - 20 * a, yy2 = y2, zz2 = z1 + 28 * c;

	for (; yy1 <= (y1 + y2) / 2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(white, xx1, yy1, zz1);
			}
			zz1 = z1 + 13 * c;
		}
		xx1 = x1 + 22 * a;
	}
	yy1 = y1 + 1;



	//208�� â�� ��� �ޱ�
	int i = 0;
	int j = 0;
	for (xx1 = xx1 + 4 * a; xx1 < xx2; xx1 = xx1 + 6 * a)
	{
		for (i = 0; i < 4 * a; i++)
		{
			for (j = 0; j < 3 * b; j++)
			{
				locateBlock(blue, xx1 + i, yy1 + j + b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 6 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 6 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 11 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 11 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 16 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 16 * b, zz2);

				locateBlock(blue, xx1 + i, yy1 + j + 21 * b, zz1);
				locateBlock(blue, xx1 + i, yy1 + j + 21 * b, zz2);


			}
		}
	}
	//208�� ��� �ձ�
	for (; yy1 <= (y1 + y2) / 4; yy1++) {
		for (; xx1 <= x1 + 22 * a + 16 * a; xx1++) {//x1 + 22 * a�� xx1�� ����
			for (; zz1 <= zz2; zz1++) {
				locateBlock(air, xx1 + 16 * a, yy1, zz1);
			}
			zz1 = z1 + 13 * c;
		}
		xx1 = x1 + 22 * a;
	}
	yy1 = y1 + 1;


	//208�� ��� �ȿ� �� �ձ�
	for (i = 0; i < 4 * b; i++) {
		for (j = 0; j < 3 * c; j++) {
			locateBlock(air, x1 + 39 * a + 16 * a, yy1 + i, (zz1 + zz2) / 2 + j);
			locateBlock(air, x1 + 21 * a + 16 * a, yy1 + i, (zz1 + zz2) / 2 + j);
		}
	}



	//208�� ������
	xx1 = x2 - 20 * a, yy1 = y1 + 1, zz1 = z1;
	xx2 = x2 - 10 * a, yy2 = y2, zz2 = z1 + 28 * c;

	for (; yy1 <= (y1 + y2) / 2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(white, xx1, yy1, zz1);
			}
			zz1 = z1;
		}
		xx1 = x2 - 20 * a;
	}
	yy1 = y1 + 1;




	//��� ȭ�� �κ�
	xx1 = x2 - 100 * a, yy1 = y1, zz1 = z2 - 100 * c;
	xx2 = x2 - 95 * a, yy2 = y1, zz2 = z2 - 70 * c;
	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(grass, xx1, yy1, zz1);
				if (y1 < y2) {
					locateBlock(TULIP, xx1, yy1 + 1, zz1);
				}
			}
			zz1 = z2 - 100 * c;
		}
		xx1 = x2 - 110 * a;
	}


	//���� �κ� (�̴Ͻ����� ����)

	xx1 = x1, yy1 = y1, zz1 = z1 + 28 * c;
	xx2 = x1 + 22 * a, yy2 = y1, zz2 = z1 + 73 * c;
	for (; yy1 <= yy2; yy1++) {
		for (; xx1 <= xx2; xx1++) {
			for (; zz1 <= zz2; zz1++) {
				locateBlock(grass, xx1, yy1, zz1);
				if (y1 < y2) {
					locateBlock(TULIP, xx1, yy1 + 1, zz1);
				}
			}
			zz1 = z1 + 28 * c;
		}
		xx1 = x1;
	}
	/*

	WoolID three = createWool(COLOR_GREEN);
	//�౸��
	BlockID grass = createBlock(BLOCK_GRASS);
	int x1 = 0, y1 = 4, z1 = 0, x2 = 0, y2 = 4, z2 = 0;
	for(;yy1<=yy2; yy1++){
	for (; xx1 <= xx2; xx1++) {

		for (; zz1 <= zz2; zz1++) {
			locateBlock(grass, xx1, yy1, zz1);
		}
	}
	}
	*/
	return 0;

}