/* 
Autore: Ruben Scopacasa
Data: 02/11/2022
problema: Programma che permetta ad un utente di inserire dei numeri uno dopo l'altro fintanto che desidera inserire numeri. 
Quando decide di non inserire più, il programma stampa il numero di numeri inseriti, la loro somma e stampa anche i valori minimo e massimo.
*/
#include<stdio.h>
int main(){
	int num, somma, c, max, min;
	char risp;
	int valuta; //booleano se considerare numero inserito o terminare
	c=0; //conta inserimenti
	somma=0;
	printf("Questo programma ti permette di inserire quanti numeri vuoi, farne la somma e stampare il valore min e max\n");
	printf("Per fermare il programma devi inserire 0 e confermare\n");
	do{
		valuta = 1;
		scanf("%d",&num);
		if(num == 0){
			printf("Vuoi veramente uscire? [s/n]");
			scanf(" %c", &risp);
			if(risp == 's'){
				valuta = 0; //FALSE
			}
			else{
				valuta = 1; //TRUE
			}
		}
		if(valuta == 1){
			//INIZIALIZZAZIONE min max
			if(c==1){
				max=num;
				min=num;
			}
			//VERIFICA MAX
			if(max<num){
				max=num;
			}
			//VERIFICA MIN
			if(min>num){
				min=num;
			}
			somma += num;
			c++;
		}	
	}while(valuta != 0);
	
	printf("La somma dei numeri e' uguale a %d\n", somma);
	printf("Il numero massimo e' %d\n", max);
	printf("Il numero minimo e' %d\n", min);
	printf("Sono stati inseriti %d valori\n", c);
}
