#include <stdio.h>
#include <stdlib.h>

struct slinklist{
	int data;
	struct slinklist * next;
};

typedef struct slinklist node;
node * start=NULL;
node * getnode1(){
	node * newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Data giriniz\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}
node * getnode2(getdata){
	node * newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=getdata;
	newnode->next=NULL;
	return newnode;
}

void enqueue(node * newnode){
	node * temp;
	temp=start;
	if(temp==NULL){
		start=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

node * dequeue(){
	node * temp;
	temp=start;
	start=start->next;
	return temp;
}

void display(){
	node * temp;
	temp = start;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}


int main() {
	int secim,getdata;
	node * addnode;
	while(1){
		menu:
		system("cls");
		display();
		printf("\n");
		printf("_________________________________________________\n");
		printf("KUYRUGA ELEMAN EKLEME MENUSUNE HOS GELDINIZ\n");
		printf("_________________________________________________\n");
		printf("1- Kuyruga Fonksiyonda Eleman Ekleme\n");
		printf("2- Kuyruga Main Fonksiyonda Eleman Ekleme\n");
		printf("3- Kuyruktan Eleman Cikarma\n");
		printf("4- Cikis\n");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				addnode=getnode1();
				enqueue(addnode);
				break;
			case 2:
				printf("Data giriniz\n");
				scanf("%d",&getdata);
				addnode=getnode2(getdata);
				enqueue(addnode);
				break;
			case 3:
				addnode=dequeue();
				free(addnode);
				break;
			case 4:
				exit(0);
			default:
				goto menu;
		}
}
}






























