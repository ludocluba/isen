#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud {
    char* texte;
    int numero;
    struct noeud* filsG;
    struct noeud* filsD;
};

struct noeud* constructArbre(int numero,
							int* tabNums,
							char** tabTextes,
							int nbTextes);

void print_noeud(struct noeud* arbre, int i) ;
//struct noeud* init_arbre(int i);
void parcours(struct noeud* racine);
int read_input(char* file,
	 			int* tabNums,
				char** tabTextes,
				int* nbTextes);

int main() {
	char* tabTextes[100];
	int tabNums[100];
	int nbTextes;
    struct noeud* arbre;

	if (read_input("input.txt",
					tabNums,
					tabTextes,
					&nbTextes) == 1) {
		return EXIT_FAILURE;
	}
	//printf("nb questions: %d\n", nbTextes);
	arbre = constructArbre(1, tabNums, tabTextes, 19);
    //printf("%ld", sizeof(struct noeud));
	parcours(arbre);

	//printf("%s\n", arbre->texte);
	//printf("%s\n", arbre->filsG->filsG->texte);

	return EXIT_SUCCESS;
}

// struct noeud* init_arbre(int i) {
// 	struct noeud* arbre = malloc(sizeof(struct noeud));
// 	if (i == 0) {
// 	    arbre->filsG = NULL;
// 		arbre->filsD = NULL;
// 		arbre->texte = "fin";
// 		arbre->numero = i;
// 	}
// 	else {
// 		arbre->texte="pas fini";
// 		arbre->numero = i;
// 		arbre->filsG = init_arbre(i-1);
// 		arbre->filsD = init_arbre(i-1);
// 	}
// 	return arbre;
// }

void print_noeud(struct noeud* arbre, int i) {
    if (arbre != NULL) {
		if (arbre->numero == i) {
			printf("numéro: %d \n \t texte:%s\n", arbre->numero, arbre->texte);
		}
		else {
			print_noeud(arbre->filsG, i);
			print_noeud(arbre->filsD, i);
		}
	}
}

struct noeud* constructArbre(int numero,
							int* tabNums,
							char** tabTextes,
							int nbTextes) {

	struct noeud* arbre = NULL;
	int i;
	//Vérification de l'existence du numéro
	// dans tabNum
	for(i=0; i<nbTextes; i++) {
		if (tabNums[i] == numero) {
			break;
		}
	}

	if (i != nbTextes) {

		arbre = malloc( sizeof(struct noeud));

		//Initialisation cellule courante
		arbre->numero = numero;
		arbre->texte = tabTextes[i];
		arbre->filsG = constructArbre(2*numero,
								tabNums,
								tabTextes,
								nbTextes);
		arbre->filsD = constructArbre(2*numero+1,
								tabNums,
								tabTextes,
								nbTextes);
	}
	return arbre;

}

void parcours(struct noeud* racine) {
	char reponse[10];
	//on pose la question
	// ou le diagnostique
    printf("%s\n", racine->texte);
	if (racine->filsG != NULL) {
		scanf("%s", reponse);
		//si oui
		if (strcmp(reponse, "oui") == 0) {
			parcours(racine->filsG);
		} else {
			parcours(racine->filsD);
		}
	}
}
int read_input(char* file,
	 			int* tabNums,
				char** tabTextes,
				int* nbTextes) {

	FILE* fin;
	char ligne[101];
	char* res;
	int i=0;
	int j;
	*nbTextes = 0;
	if ((fin=fopen(file, "r")) == NULL) {
		printf("Erreur de lecture\n");
		return 1;
	}
	do {
		res = fgets(ligne, 100, fin);
		//printf("%s", ligne);
        tabNums[i] = atoi(ligne);
		char* ch = strchr(ligne,';');
		tabTextes[i] = malloc(100*sizeof(char));
		strcpy(tabTextes[i], ch+1);
		tabTextes[i][strlen(tabTextes[i])-1]='\0';
		(*nbTextes)++;
		i++;
	} while (res != NULL);
	(*nbTextes)--;
}
