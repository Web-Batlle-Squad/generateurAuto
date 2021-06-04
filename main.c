#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Header.h"


struct Coord {
	int xxx;
	int yyy;
};

int rollm(int max) {
	int tmpf = rand() % max;
	return tmpf;
}

struct Coord pickvoid(int tableau[10][15]) {
	int tmpppx = rollm(10);
	int tmpppy = rollm(15);
	if ((tableau[tmpppx][tmpppy]) != 0) {
		pickvoid(tableau);
	}

	struct Coord Crd;
	Crd.xxx = tmpppx;
	Crd.yyy = tmpppy;

	return Crd;
}


int main() {
	bool finito = false;
	srand(time(NULL));
	while(finito == false){
	int tmp;
	int tab[10][15];
	int i;
	int y;
	for (i = 0; i < 10; i++) {
		for (y = 0; y < 15; y++) {
			tab[i][y] = 0;
		}
	}

	//génération des obstacles

	//note : la géné des obstacles 1, 2, 3, 4 aurait pu être condensé en une énorme fonction mais ce serai chiant à implémenter
	//note2 : surtout que ca marche dans l'état
	tmp = rollm(3) + 10; //afin d'avoir entre 10 et 12 amas d'obstacles
	for (int suptemp = 0; suptemp < tmp; suptemp++) {
		int tmppl; //taille obstacle
		int tmpx = rollm(7) + 1; //coord x ~hasard
		int tmpy = rollm(12) + 1; //coord y ~hasard
		int tmptype = rollm(6); //type de génération d'obstacle

		//------------------------------//
		if (tmptype == 0 || tmptype == 5) { //amas (2x + de chance de tirage)
			int tmptaille = rollm(3) + 1; //taille de l'amas
			if (tmptaille == 1) {
				int tmproll;
				tmproll = rollm(5);
				if (tmproll != 0){
					tab[tmpx][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+1][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy + 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy + 1];
				}
			}
			if (tmptaille == 2) {
				int tmproll;
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy + 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy + 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy + 1];
				}
			}
			if (tmptaille == 3) {
				int tmproll;
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy + 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy + 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx + 1][tmpy - 1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx - 1][tmpy + 1];
				}


				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+2][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+2][tmpy-1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+2][tmpy+1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx-2][tmpy+1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx-2][tmpy-1];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx-2][tmpy];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy+2];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx-1][tmpy+2];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+1][tmpy+2];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx+1][tmpy-2];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx][tmpy-2];
				}
				tmproll = rollm(5);
				if (tmproll != 0) {
					tab[tmpx-1][tmpy-2];
				}
			}
		}

		//------------------------------//
		if (tmptype == 1) { //ligne horizontale
			tmppl = rollm(4) + 2;
			for (y = 0; y < tmppl; y++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpx + y < 15) {  //une chance sur 5 de ne pas passer
					tab[tmpx + y][tmpy] = 7;
					int tmproll2 = rollm(20);  // 1 chance/10 de générer un obstacle de coté
					if (tmproll2 == 0 && tmpy+1 < 15) {
						tab[tmpx + y][tmpy + 1] = 7;
					}
					if (tmproll2 == 1 && tmpy - 1 >= 0) {
						tab[tmpx + y][tmpy - 1] = 7;
					}
				}
			}
			tmppl = rollm(4) + 2;
			for (y = 0; y < tmppl; y++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpx - y >= 0) {  //une chance sur 5 de ne pas passer
					tab[tmpx - y][tmpy] = 7;
					int tmproll2 = rollm(20); // 1 chance/10 de générer un obstacle de coté
					if (tmproll2 == 0 && tmpy+1 < 15) {
						tab[tmpx - y][tmpy + 1] = 7;
					}
					if (tmproll2 == 1 && tmpy-1 >= 0) {
						tab[tmpx - y][tmpy - 1] = 7;
					}
				}
			}
		}

		//------------------------------//
		if (tmptype == 2) { //ligne verticale
			tmppl = rollm(4) + 2;
			for (y = 0; y < 4; y++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpy + y < 10) {  //une chance sur 5 de ne pas passer
					tab[tmpx][tmpy + y] = 7;
					int tmproll2 = rollm(20);  // 1 chance/10 de générer un obstacle de coté
					if (tmproll2 == 0 && tmpx + 1 < 10) {
						tab[tmpx + 1][tmpy + y] = 7;
					}
					if (tmproll2 == 1 && tmpx - 1 >= 0) {
						tab[tmpx - 1][tmpy + y] = 7;
					}
				}
			}
			tmppl = rollm(4) + 2;
			for (y = 0; y < tmppl; y++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpy - y >= 0) {  //une chance sur 5 de ne pas passer
					tab[tmpx][tmpy - y] = 7;
					int tmproll2 = rollm(20);  // 1 chance/10 de générer un obstacle de coté
					if (tmproll2 == 0 && tmpx + 1 < 10) {
						tab[tmpx+1][tmpy-y] = 7;
					}
					if (tmproll2 == 1 && tmpx - 1 >= 0) {
						tab[tmpx-1][tmpy-y] = 7;
					}
				}
			}
		}

		//------------------------------//
		if (tmptype == 3) { //diagonale SO - NE
			tmppl = rollm(4) + 2;
			for (i = 0; i < tmppl; i++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpy + i < 15 && tmpx + i < 10) {
					tab[tmpx + i][tmpy + i] = 7;
					int tmproll2 = rollm(20);
					if (tmproll2 == 0) {
						tab[tmpx + i - 1][tmpy + i] = 7;
					}
					if (tmproll2 == 1) {
						tab[tmpx + i][tmpy + i - 1] = 7;
					}
				}
			}
			tmppl = rollm(4) + 2;
			for (i = 0; i < tmppl; i++) {
				int tmproll = rollm(5);
				if(tmproll != 0 && tmpx - i >= 0 && tmpy - i >= 0){
					tab[tmpx - i][tmpy - i] = 7;
				}
				int tmproll2 = rollm(20);
				if (tmproll2 == 0 && (tmpx - i - 1) >= 0) {
					tab[tmpx - i - 1][tmpy - i] = 7;
				}
				if (tmproll2 == 1 && (tmpy - i - 1) >= 0) {
					tab[tmpx - i][tmpy - i - 1] = 7;
				}
			}
		}

		//------------------------------//
		if (tmptype == 4) { //diagonale NO - SE
			tmppl = rollm(4) + 2;
			for (i = 0; i < tmppl; i++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmpy + i < 15 && tmpx + i < 10) {
					tab[tmpx + i][tmpy - i] = 7;
					int tmproll2 = rollm(20);
					if (tmproll2 == 0) {
						tab[tmpx + i - 1][tmpy - i] = 7;
					}
					if (tmproll2 == 1) {
						tab[tmpx + i][tmpy - i - 1] = 7;
					}
				}
			}
			tmppl = rollm(4) + 2;
			for (i = 0; i < tmppl; i++) {
				int tmproll = rollm(5);
				if (tmproll != 0 && tmp) {
					tab[tmpx - i][tmpy + i] = 7;
				}
				int tmproll2 = rollm(20);
				if (tmproll2 == 0 && (tmpx - i - 1) >= 0) {
					tab[tmpx - i - 1][tmpy + i] = 7;
				}
				if (tmproll2 == 1 && (tmpy - i - 1) >= 0) {
					tab[tmpx - i][tmpy + i - 1] = 7;
				}
			}
		}
		
	}

	//génération des soldats
	struct Coord perso;
	struct Coord tabperso[10]; //mise à 000
	for (i = 0; i < 10; i++) {
		tabperso[i].xxx = 0;
		tabperso[i].yyy = 0;
	}

	int tmptabpersoA = 0;
	int tmptabpersoE = 0;
	for (int nperso = 0; nperso < rollm(2) + 2; nperso++) {
		perso = pickvoid(tab);
		tab[perso.xxx][perso.yyy] = rollm(3) + 1;
		tabperso[tmptabpersoA] = perso; //save dans un tabl utilisé + tard
		tmptabpersoA += 1;
	}
	for (int nperso = 0; nperso < 2; nperso++) {
		perso = pickvoid(tab);
		tab[perso.xxx][perso.yyy] = rollm(3) + 4;
		tabperso[tmptabpersoA + tmptabpersoE] = perso; //save dans un tabl utilisé + tard
		tmptabpersoE += 1;
	}
	int tmptabperso = tmptabpersoA + tmptabpersoE;

	//génération des obstacles passables
	//sur la map indépendament 
		perso = pickvoid(tab);
		for (int supertmpx = 0; supertmpx < 10; supertmpx++) {
			if (tab[supertmpx][perso.yyy] == 7) {
				tab[supertmpx][perso.yyy] = 8;
			}
		}
		for (int supertmpy = 0; supertmpy < 15; supertmpy++) {
			if (tab[perso.xxx][supertmpy] == 7) {
				tab[perso.xxx][supertmpy] = 8;
			}
		}
		perso.xxx = 10 - perso.xxx;
		perso.yyy = 15 - perso.yyy;

	//sur les persos  //a finir

		for (int iiiii = 0; iiiii < tmptabperso; iiiii++) { //jsp pourquoi j'ai mis autant de i
			int tmpppx = tabperso[iiiii].xxx;
			int tmpppy = tabperso[iiiii].yyy;
			for (int supertmpx = -3; supertmpx < 4; supertmpx++) {
				if (tmpppx + supertmpx >= 0 && tmpppx + supertmpx < 10) {
					if (tab[tmpppx + supertmpx][tmpppy] == 7) {
						tab[tmpppx + supertmpx][tmpppy] = 8;
					}
				}
			}
			for (int supertmpy = -3; supertmpy < 4; supertmpy++) {
				if (tmpppy + supertmpy >= 0 && tmpppy + supertmpy < 15) {
					if (tab[tmpppx][tmpppy + supertmpy] == 7) {
						tab[tmpppx][tmpppy + supertmpy] = 8;
					}
				}
			}
		}

	//print tab (tests)

	//for (i = 0; i < 10; i++) {
	//	for (y = 0; y < 15; y++) {
	//		printf("%d", tab[i][y]);
	//		printf(" ");
	//	}
	//	printf("\n");
	//}
	//_sleep(10000); //zzz 10sec

			//sauvegarde
		FILE* fp;
		fp = fopen("autoSave.txt", "w");
		for (i = 0; i < 10; i++) {
			for (y = 0; y < 15; y++) {
				fprintf(fp, "'%d'", tab[i][y]);
				if (i != 9 || y != 14) {
					fprintf(fp, ",");
				}
			}
		}
		fclose(fp);

		if (verification() == EXIT_SUCCESS) {
			finito = true;
			int nombre = 0;
			int res;
			res = scanf("%d", &nombre);
		}

}
}