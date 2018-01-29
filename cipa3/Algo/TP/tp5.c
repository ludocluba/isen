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

int main() {
	char* tabTextes[19] = {
		"Avez-vous mal a la tete ?",
		"Avez-vous de la fievre ?",
		"Avez-vous mal au ventre ?",
		"Avez-vous mal a la gorge ?",
		"Souffrez-vous de vomissements ?",
		"Evitez donc les grands repas !",
		"Avez-vous des nausees ?",
		"Vous devriez arreter de fumer !",
		"Allez vous coucher...",
		"Cessez de boire une bonne fois pour toute !",
		"Un bon cachet d’aspirine et puis ça ira...",
		"Seriez-vous une femme ?",
		"Avez-vous consulte votre horoscope ?",
		"Avez-vous des vertiges ?",
		"Sans-doute mangez-vous trop vite !",
		"Votre astrologue aura peut-etre de meilleurs conseils a vous donner.",
		"Vous devriez consulter un bon psychiatre !",
		"Vous etes peut-etre enceinte..."	,
		"Quelques jours de conges et puis..."};

	int tabNums[19] = {
		1,2,3,4,5,6,7,8,9,10,
		11,14,15,28,29,30,31,
		56,57};
    struct noeud* arbre;

	arbre = constructArbre(1, tabNums, tabTextes, 19);
    printf("%ld", sizeof(struct noeud));
		parcours(arbre);

	//printf("%s\n", arbre->texte);
	//printf("%s\n", arbre->filsG->filsG->texte);


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
