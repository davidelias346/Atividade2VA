#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
 int PIDP;
 char nomeP [40];
 struct Node *proxP;
};

struct Node2{
 int PIDN;
 char nomeN [40];
 struct Node2 *proxN;
};

typedef struct Node node;
typedef struct Node2 node2;

int tamP, tamN;

int menu(void);
void opcao(node *FILAP, node2 *FILAN, int op);

//Protótipos das Funções da Lista Preferencial
void iniciaP(node *FILAP);
int vaziaP(node *FILAP);
node *alocaP();
void insereP(node *FILAP);
node *retiraP(node *FILAP);
void exibeP(node *FILAP);
void liberaP(node *FILAP);

//Protótipos das Funções da Lista Normal
void iniciaN(node2 *FILAN);
int vaziaN(node2 *FILAN);
node2 *alocaN();
void insereN(node2 *FILAN);
node2 *retiraN(node2 *FILAN);
void exibeN(node2 *FILAN);
void liberaN(node2 *FILAN);


int main(void)
{
 node *FILAP = (node *) malloc(sizeof(node));
 node2 *FILAN = (node2 *) malloc(sizeof(node2));

 if(!FILAP || !FILAN){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 iniciaP(FILAP);
 iniciaN(FILAN);
 int opt;
	
 do{
  opt=menu();
  opcao(FILAP, FILAN, opt);
 }while(opt);

 free(FILAP);
 return 0;
 }
}


int menu(void)
{
 int opt;

 printf("Escolha a opcao\n");
 printf("\n0: Sair\n");
 printf("1: Zerar fila\n");
 printf("2: Exibir fila\n");
 printf("3: Adicionar Elemento na Fila\n");
 printf("4: Retirar Elemento da Fila\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
 
}

void opcao(node *FILAP, node2 *FILAN,  int op)
{
 int PouN, RetirarPouN;
 node *tmpP;
 node2 *tmpN;
 switch(op){
  case 0:
   liberaP(FILAP);
   liberaN(FILAN);
   break;

  case 1:

   	liberaP(FILAP);
   	iniciaP(FILAP);
   	liberaN(FILAN);
   	iniciaN(FILAN);
   	 break;

  case 2:
   printf("\n------ Fila Preferencial ------\n ");
   exibeP(FILAP);
   printf("\n------ Fila Normal ------\n ");
   exibeN(FILAN);
   break;
   

  case 3:
   printf("\nDigite 9 para Fila Preferencial ou 10 para Fila Normal:\t");
   scanf("%i", &PouN);
   
   if(PouN == 9){
   	insereP(FILAP);
   }else{
   	insereN(FILAN);
   }
   break;
   
   case 4:
   	printf("Para retirar o processo da Fila Preferencial digite 7 Para retirar da Normal digite 8:\t");
   	scanf("%i", &RetirarPouN);
   	
   	if(RetirarPouN==7){ //Retira o elemento da Fila Prioritária
	   tmpP= retiraP(FILAP);
   	   if(tmpP != NULL){
          liberaP(tmpP);
	   }
   }else{ //Retira o elemnto da Fila Normal
   	tmpN= retiraN(FILAN);
   	   if(tmpN != NULL){
		  liberaN(tmpN);
   }
}
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

void iniciaP(node *FILAP) //Fila Preferencial
{
 FILAP->proxP = NULL;
 tamP=0;
}

int vaziaP(node *FILAP)
{
 if(FILAP->proxP == NULL)
  return 1;
 else
  return 0;
}

node *alocaP()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("\nPID: "); scanf("%d", &novo->PIDP);
  printf("Nome do processo: "); scanf("%s", &novo->nomeP);
  system("cls");

  
  return novo;
 }
}

void insereP(node *FILAP)
{
 node *novo=alocaP();
 novo->proxP = NULL;

 if(vaziaP(FILAP))
  FILAP->proxP=novo;
 else{
  node *tmpP = FILAP->proxP;

  while(tmpP->proxP != NULL)
   tmpP = tmpP->proxP;

  tmpP->proxP = novo;
 }
 tamP++;
}


node *retiraP(node *FILAP)
{
 if(FILAP->proxP == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  node *tmpP = FILAP->proxP;
  FILAP->proxP = tmpP->proxP;
  tamP--;
  return tmpP;
 }

}


void exibeP(node *FILAP)
{
 if(vaziaP(FILAP)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node *tmpP;
 tmpP = FILAP->proxP;
 while( tmpP != NULL){
  printf("Pid:%d\tNome:%s\n", tmpP->PIDP, tmpP->nomeP);
  tmpP = tmpP->proxP;
 }
}

void liberaP (node *FILAP){
 if(!vaziaP(FILAP)){
  node *proxNodeP, *atualP;

  atualP = FILAP->proxP;
  while(atualP != NULL){
   proxNodeP = atualP->proxP;
   free(atualP);
   atualP = proxNodeP;
  }
 }
}

void iniciaN(node2 *FILAN) //Fila Normal
{
 FILAN->proxN = NULL;
 tamN=0;
}

int vaziaN(node2 *FILAN)
{
 if(FILAN->proxN == NULL)
  return 1;
 else
  return 0;
}

node2 *alocaN()
{
 node2 *novoN=(node2 *) malloc(sizeof(node2));
 if(!novoN){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("\nPID: "); scanf("%d", &novoN->PIDN);
  printf("Nome do processo: "); scanf("%s", &novoN->nomeN);
  system("cls");

  
  return novoN;
 }
}

void insereN(node2 *FILAN)
{
 node2 *novoN=alocaN();
 novoN->proxN = NULL;

 if(vaziaN(FILAN))
  FILAN->proxN=novoN;
 else{
  node2 *tmpN = FILAN->proxN;

  while(tmpN->proxN != NULL)
   tmpN = tmpN->proxN;

  tmpN->proxN = novoN;
 }
 tamN++;
}


node2 *retiraN(node2 *FILAN)
{
 if(FILAN->proxN == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  node2 *tmpN = FILAN->proxN;
  FILAN->proxN = tmpN->proxN;
  tamN--;
  return tmpN;
 }

}


void exibeN(node2 *FILAN)
{
 if(vaziaN(FILAN)){
  printf("Fila vazia!\n\n");
  return ;
 }

 node2 *tmpN;
 tmpN = FILAN->proxN;

 while( tmpN != NULL){
  printf("Pid:%d\tNome:%s\n", tmpN->PIDN, tmpN->nomeN);
  tmpN = tmpN->proxN;
 }
}

void liberaN(node2 *FILAN){
 if(!vaziaN(FILAN)){
  node2 *proxNodeN, *atualN;

  atualN = FILAN->proxN;
  while(atualN != NULL){
   proxNodeN = atualN->proxN;
   free(atualN);
   atualN = proxNodeN;
  }
 }
}



	
	


