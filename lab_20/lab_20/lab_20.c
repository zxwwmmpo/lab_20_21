#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#define MAX_N 8
#define MAX_M 10

int arr[MAX_N][MAX_M] = {
	{10, 11, 12, 13},
	{20, 21, 9, 23},
	{30, 31, 32, 33}
};
int n = 3;
int m = 4;

void print() {
	printf("!!!! print() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIx10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fillZero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void fillRand() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void UpTo10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 != 0) {
				arr[i][j] *= 10;
			}
		}
	}
}

void DownTo10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void keyboardInput() {
	printf("введите массив 3x4:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
}

void Save() {
	FILE* fout = fopen("C:\\Users\\vkobi\\OneDrive\\Desktop\\lab_20\\out_20.txt", "wt");
	if (fout == NULL) {
		printf("выходной файл не создался");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
}

void Load() {
	FILE* fin = fopen("C:\\Users\\vkobi\\OneDrive\\Desktop\\lab_20\\in_20.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}
	fclose(fin);
}

void delete(int delRow) {
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}

void addColumn(int add) {
	if (m < MAX_M) {
		for (int i = add; i < n; i++) {
			arr[i][m] = arr[i][add];
		}
		m++;
	}
}

void a10() {
	for (int j = 0; j < m; j++) {
		//int k = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] % 2 != 0) {
				if (i = n - 1) {
					for (int i = 0; i < n; i++) {
						arr[i][j] = 0;
					}
				}
			}
			else {
				break;
				
			}
		}
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int item;
	do {
		printf("\n");
		//printf("!!!! printf() !!!!\n");
		print();

		printf("===============================\n");
		printf("выберите нужную вам операцию:\n");
		printf("1: заполнить значениями i * 10+ j\n");
		printf("2: заполнить нулями\n");
		printf("3: заполнить случайными значениями\n");
		printf("4: все нечетные увеличить в 10 раз\n");
		printf("5: все кратные 10 уменьшить в 10 раз\n");
		printf("6: ввод с клавиатуры\n");
		printf("7: сохранить в файл\n");
		printf("8: загрузить из файла\n");
		printf("9: удалить строку\n");
		printf("10: продублировать столбец\n");
		printf("11: А10\n");
		printf("\n");
		printf("-1: выйти из программы\n");
		printf("выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			fillIx10();
			break;
		case 2:
			fillZero();
			break;
		case 3:
			fillRand();
			break;
		case 4:
			UpTo10();
			break;
		case 5:
			DownTo10();
			break;
		case 6:
			keyboardInput();
			break;
		case 7:
			Save();
			break;
		case 8:
			Load();
			break;
		case 9: {
			int num;
			printf("номер строки: ");
			scanf_s("%d", &num);
			delete(num);
		}
		break;
		case 10: {
			int num;
			printf("номер столбца: ");
			scanf_s("%d", &num);
			addColumn(num);
		}
		break;
		case 11:
			a10();
			break;
		}
	} while (item != -1);
}