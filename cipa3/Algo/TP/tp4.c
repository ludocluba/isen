#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char chiffrement(char c,int cle);
char dechiffrement(char c,int cle);
float* analyseFreq(char* texte, int N);
int calculCle(float* tabFreq);

int main()
{
	char chaine[100]={0};
	char chaine_cryptee[100]={0};
	char chaine_decryptee[100]={0};

	char* chaine_cryptee2="ZNVGER PBEORNH, FHE HA NEOER CREPUR, GRANVG RA FBA ORP HA SEBZNTR. ZNVGER ERANEQ CNE Y'BQRHE NYYRPUR, YHV GVAG N CRH CERF PR YNATNTR : RG OBAWBHE ZBAFVRHE QH PBEORNH. DHR IBHF RGRF WBYV! DHR IBHF ZR FRZOYRM ORNH! FNAF ZRAGVE, FV IBGER ENZNTR FR ENCCBEGR N IBGER CYHZNTR IBHF RGRF YR CURAVK QRF UBGRF QR PRF OBVF. N PRF ZBGF YR PBEORNH AR FR FRAG CNF QR WBVR; RG CBHE ZBAGERE FN ORYYR IBVK, VY BHIER HA YNETR ORP YNVFFR GBZORE FN CEBVR. YR ERANEQ F'RA FNVFVG RG QVG : ZBA OBA ZBAFVRHE, NCERARM DHR GBHG SYNGGRHE IVG NH QRCRAF QR PRYHV DHV Y'RPBHGR : PRGGR YRPBA INHG OVRA HA SEBZNTR FNAF QBHGR. YR PBEORNH UBAGRHK RG PBASHF WHEN ZNVF HA CRH CYHF GNEQ, DH'BA AR Y'L CERAQENVG CYHF.";
	char chaine_decryptee2[1000]={0};
	int cle, i;
	char c;
	float *freq;

	//printf("Entrez une cle:\n");
	//scanf("%d",&cle);


	//while ((c=getchar()) != '\n');


	//printf("Entrez un texte:\n");
	//fgets(chaine,100,stdin);
	//Supression du retour chariot
	//chaine[strlen(chaine)-1] = '\0';
	
	//chiffrement
	//for (i=0; i<100;i++)
	//{
	//	chaine_cryptee[i] = chiffrement(chaine[i],cle);
	//	printf("%d\n", chaine_cryptee[i]);
	//}
	
	printf("%s\n", chaine_cryptee2);
	printf("taille de la chaine %d\n",(int)strlen(chaine_cryptee2));
	freq = analyseFreq(chaine_cryptee2, strlen(chaine_cryptee2));

	cle = calculCle(freq);

	//Liberation
	free(freq);
	
	

	//dechiffrement
	for (i=0; i<1000;i++)
	{
		chaine_decryptee2[i] = dechiffrement(chaine_cryptee2[i],cle);
	}
	
	printf("%s\n", chaine_decryptee2);


	return EXIT_SUCCESS;
}

char chiffrement(char c,int cle)
{
	if ((c<65) || (c>90))
		return c;
	else return (c+cle-65)%26+65;
}


char dechiffrement(char c,int cle)
{
	if ((c<65) || (c>90))
		return c;
	else return (c-cle-90)%26+90;
}


float* analyseFreq(char* texte, int N)
{
	int i;
	float* frequence = NULL;
	
	//Allocation dynamique
	frequence = (float*) malloc(26*sizeof(float));

	for (i=0; i<N; i++)
	{
		//On ne prend en compte que les majuscules
		if ((texte[i] >= 65) && (texte[i]<=90))
		{
			frequence[texte[i]-65]++;
		}
	}
	//En pourcentage
	for (i=0; i<26; i++)
	{
		
		frequence[i]=frequence[i]/N;
	}
	
	return frequence;
}


int calculCle(float* tabFreq)
{
	int i;
	int cle=0;
	float max=0;
	for (i=0;i<26;i++)
	{
		if (tabFreq[i] > max)
		{
			max=tabFreq[i];
			cle = i;
		}
	} 
	return cle-4;
}






