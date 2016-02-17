#include"stdio.h"
#include"stdlib.h"
#define LENTH sizeof(struct table)
#define M 30
struct table{
	int data;
	struct table *next;
};
int m;
struct table *creat();
struct table *delop(struct table *head,int n);
struct table *search(struct table *head,int n);
int main(){
	scanf("%d",&m);
	struct table *head;
	head=creat();
	while(head->next->next!=head->next){
		head->next=delop(head,m);
	}
	printf("%d",head->next->data);
}
struct table *creat(){
	struct table *head,*p1,*p2;
	int i;
	head=(struct table *)malloc(LENTH);
	head->next=NULL;
	p2=(struct table *)malloc(LENTH);
	for(i=1;i<=M;i++){
		p1=(struct table *)malloc(LENTH);
		if(i==1)head->next=p1;
		else p2->next=p1;
		p2=p1;
		p1->data=i;
	}
	p1->next=head->next;
	return (head);
}
struct table *search(struct table *head,int n){
	struct table *p;
	int i;
	p=head;
	for(i=1;i<m;i++)
		p=p->next;
	return (p);
}
struct table *delop(struct table *head,int n){
	struct table *p1,*p2;
	p1=search(head,m);
	p2=p1->next;
	p1->next=p2->next;
	printf("%-4d",p2->data);
	free(p2);
	return (p1);
}