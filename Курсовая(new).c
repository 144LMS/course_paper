#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int print_fun(int a[2][8][8]);
int print_game(int och[8][8]);
int print_bl(int n, int m, char kom[8][13], int azp[2][8][8], int a1[2][8][8], int a2[2][8][8], int a3[2][8][8]);
int ochki(int array[2][8][8]);
int zbpr(int aSUMz1[2][8][8], int a1[2][8][8], int a2[2][8][8], int a3[2][8][8], int arr[8], int m, int max, int index, int kom[8][13], int x1, int x2);

int main() {
	setlocale(LC_ALL, "RUS");
	
	char kom[8][13] = {
	{"Спортклубы |"},
	{"МРСК-Волги |"},
	{"Мехзавод   |"},
	{"Промсинтез |"},
	{"ЧХТГ       |"},
	{"11 ОФПС    |"},
	{"Здоровье   |"},
	{"ДОСААФ     |"}
	};

	int az[2][8][8], aSUMz[2][8][8], aSUMz1[2][8][8], aSUMp[2][8][8], a1[2][8][8], a2[2][8][8], a3[2][8][8], ochSUM[8], och[8][8], och1[8][8], och2[8][8], och3[8][8];
    int o = 0, one = 1, two = 2, sum = 0, sum1 = 0, sumob = 0, max = 0, min = 0, m = 0, n = 0, ot[8], index = 0, x = 0, x1 = 1, x2 = 2;
	float zabit[8], h = 0, f = 0, u = 0;
	int arr[8], arr1[8], b = 0;
	char k = 1;

	print_fun(a1);//Заполняю массивы случайными числами от 0 до 20 
	print_fun(a2);//Это будут очки за каждую игру в каждом матче
	print_fun(a3);//3 массива использую потому что каждая команда играет 3 игры в 1 матче

	while (1) {
		printf("\nВыберите пукт из предоставленного списка:\n1)Таблица забитых мячей\n2)Таблица пропущенных мячей\n3)Количество набранных очков каждой команды\n4)Разница между суммами забитых и пропущенных мячей\n5)Команда с наибольшим количеством забитых и пропущенных мячей\n6)Отношение суммы забитых мячей к пропущенным\n7)Количество побед в играх\n8)Завершить работу программы\n");
		
		scanf_s("%c", &k);
		getchar();
		switch (k) {

		case'1':
			printf("\n\t\t\t\tОбщее количество забитых мячей в каждой игре\n");
			print_bl(o, one, kom, az, a1, a2, a3);//Суммирую 3 массива с очками и вывожу забитые мячи [0]
			break;

		case '2':
			printf("\n\t\t\t\tОбщее количество пропущенных мячей в каждой игре\n");
			print_bl(one, two, kom, az, a1, a2, a3);//Суммирую 3 массива с очками и вывожу пропущенные мячи [1]
			break;

		case '3':
			printf("\nКоличество набранных очков\n\n");
			print_game(och1, a1);//Считаю очки в зависимости от того как сыграли команды
			print_game(och2, a2);//Если команда забила больше ей начисляется 1 очко
			print_game(och3, a3);//Если команда проиграла или они сыграли в ничью то 0 очков

			for (int i = 0; i < 8; i++) {
				for (int n = 0; n < 13; n++)
				{
					printf("%c", kom[i][n]);
				}
				for (int j = 0; j < 8; j++) {
					och[i][j] = och1[i][j] + och2[i][j] + och3[i][j];
					sum += och[i][j];
				}
				printf("%4d", sum);
				sum = 0;
				printf("\n");
			}
			break;

		case '4':
			printf("\nРазница между суммами забитых и пропущенных мячей\n\n");
			for (int k = 0; k < 1; k++) {//Вычитаю сумму забитых и пропущенных мячей 

				for (int i = 0; i < 8; i++)
				{
					for (int n = 0; n < 13; n++)
					{
						printf("%c", kom[i][n]);
					}
					for (int z = 0; z < 8; z++) {
						aSUMz[k][i][z] = a1[k][i][z] + a2[k][i][z] + a3[k][i][z];
						aSUMp[k][i][z] = a1[1][i][z] + a2[1][i][z] + a3[1][i][z];
						sum += aSUMz[k][i][z];
						sum1 += aSUMp[k][i][z];
						sumob = sum - sum1;
					}
					printf("%4d", sumob);
					sum = 0;
					sum1 = 0;
					printf("\n");
				}
			}
			break;

		case'5':
			printf("\nКоманда с наибольшим количеством забитых мячей\n");
			zbpr(aSUMz1, a1, a2, a3, arr1, m, max, index, kom, x, x1);//Сортирую сумму забитых, пропущенных мячей и вывожу наибольшее кол-во
			printf("\nКоманда с наибольшим количеством пропущенных мячей\n");
			zbpr(aSUMz1, a1, a2, a3, arr1, m, max, index, kom, x1, x2);
			break;

		case'6':
			printf("\nОтношение суммы забитых мячей к пропущенным\n\n");
			for (int i = 0; i < 1; i++) {//Сумму забитых мячей делю на сумму пропущенных 
				for (int j = 0; j < 8; j++) {
					for (int n = 0; n < 13; n++)
					{
						printf("%c", kom[j][n]);
					}
					for (int l = 0; l < 8; l++) {
						aSUMz[i][j][l] = a1[i][j][l] + a2[i][j][l] + a3[i][j][l];
						aSUMp[1][j][l] = a1[1][j][l] + a2[1][j][l] + a3[1][j][l];
						f += aSUMz[0][j][l];
						u += aSUMp[1][j][l];
					}
					h = f / u;
					zabit[j] = h;
					printf("%.2f\n", zabit[j]);
					f = 0;
					u = 0;
				}
			}
			break;

		case'7':
			printf("\nКоличество побед в играх\n");
			print_game(och1, a1);//1 очко = 1 победа в игре
			print_game(och2, a2);//Соответственно просто произвожу подсчёт очков в каждой игре
			print_game(och3, a3);//Суммирую 3 массива с очками и получаю кол-во побед в каждой игре
			printf("\n--------------------------------------------------------------------------------------------------\n");
			printf("\t\tСпортклубы|МРСК-Волги|Мехзавод|Промсинтез| ЧХТГ  | 11 ОФПС | Здоровье | ДОСААФ|\n");
			for (int i = 0; i < 8; i++) {
				for (int n = 0; n < 13; n++)
				{
					printf("%c", kom[i][n]);
				}
				for (int j = 0; j < 8; j++) {
					och[i][j] = och1[i][j] + och2[i][j] + och3[i][j];
					printf("%10d", och[i][j]);
				}
				printf("\n--------------------------------------------------------------------------------------------------\n");
			}
			break;
		case '8':
			exit(EXIT_SUCCESS);
		}
	}
}

int print_bl(int n, int m, char kom[8][13], int azp[2][8][8], int a1[2][8][8], int a2[2][8][8], int a3[2][8][8]) {
	printf("\n--------------------------------------------------------------------------------------------------\n");
	printf("\t\tСпортклубы|МРСК-Волги|Мехзавод|Промсинтез| ЧХТГ  | 11 ОФПС | Здоровье | ДОСААФ|\n");
	for (int k = n; k < m; k++) {
		for (int i = 0; i < 8; i++)
		{
			for (int n = 0; n < 13; n++)
			{
				printf("%c", kom[i][n]);
			}
			for (int z = 0; z < 8; z++) {
				azp[k][i][z] = a1[k][i][z] + a2[k][i][z] + a3[k][i][z];
				printf("%10d", azp[k][i][z]);
			}
			printf("\n--------------------------------------------------------------------------------------------------\n");
		}
	}
}

int print_fun(int a[2][8][8]) {
	for (int e = 0; e < 2; e++) {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				a[e][i][j] = rand() % 20;
				ochki(a);
			}
		}
	}
	return a;
}

int print_game(int och[8][8], int a[2][8][8]) {
	int m = 0, n = 0;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 8; j++) {
			for (int l = 0; l < 8; l++) {
				m = a[0][j][l];
				n = a[1][j][l];
				if (m > n) {
					och[j][l] = 1;
				}
				if (m <= n) {
					och[j][l] = 0;
				}
				m = 0;
				n = 0;
			}
		}
	}
}

int ochki(int array[2][8][8]) {

			array[0][0][0] = 0;
			array[0][1][1] = 0;
			array[0][2][2] = 0;
			array[0][3][3] = 0;
			array[0][4][4] = 0;
			array[0][5][5] = 0;
			array[0][6][6] = 0;
			array[0][7][7] = 0;

			array[1][0][0] = 0;
			array[1][1][1] = 0;
			array[1][2][2] = 0;
			array[1][3][3] = 0;
			array[1][4][4] = 0;
			array[1][5][5] = 0;
			array[1][6][6] = 0;
			array[1][7][7] = 0;
}

int zbpr(int aSUMz1[2][8][8], int a1[2][8][8], int a2[2][8][8], int a3[2][8][8], int arr[8], int m, int max, int index, char kom[8][13], int x1, int x2) {
	for (int i = x1; i < x2; i++) {
		for (int j = 0; j < 8; j++) {
			for (int l = 0; l < 8; l++) {
				aSUMz1[i][j][l] = a1[i][j][l] + a2[i][j][l] + a3[i][j][l];
				m += aSUMz1[i][j][l];
			}
			arr[j] = m;
			m = 0;
			if (max <= arr[j]) {
				max = arr[j];
				index = j;
			}
		}
		printf("%s %d", kom[index], max);
	}
	printf("\n");
}