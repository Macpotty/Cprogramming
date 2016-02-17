#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define LENGTH sizeof(struct phonenum)
struct phonenum
{
	char name[20];
	long long num;
	struct phonenum *next;
};
struct phonenum *insertnum(struct phonenum *head);
struct phonenum *deletenum(struct phonenum *head);
struct phonenum *modifynum(struct phonenum *head);
struct phonenum *inquiry(struct phonenum *head);
struct phonenum *sequencename(struct phonenum *head);
struct phonenum *sequencenum(struct phonenum *head);
struct phonenum *reversal(struct phonenum *head,int n);
struct phonenum *lastnode(struct phonenum *node,struct phonenum *head);
struct phonenum *creat();
void print(struct phonenum *head);
void printinquiry(struct phonenum *head);
int length(struct phonenum *head);
void main()
{
	struct phonenum *head;
	char done;
	head=creat();
	for(;;)
	{
		printf("请选择您要进行的服务：\n（1）添加联系人\n（2）删除联系人\n（3）显示保存的所有联系人\n（4）修改联系人信息\n（5）按联系人姓名首字母排序\n（6）按联系人电话号码排序\n（7）查询联系人信息\n");
		scanf_s("%d",&done);
		if((done!=1)&&(done!=2)&&(done!=3)&&(done!=4)&&(done!=5)&&(done!=6)&&(done!=7))
		{
			printf("请重新输入");
			continue;
		}
		switch (done)
		{
			case 1:head=insertnum(head);break;
			case 2:head=deletenum(head);break;
			case 3:print(head);break;
			case 4:head=modifynum(head);break;
			case 5:head=sequencename(head);break;
			case 6:head=sequencenum(head);break;
			case 7:printinquiry(head);
		}
		printf("\n");
	}
}
struct phonenum *creat()
{
	struct phonenum *head,*p1,*p2;
	int i;
	head=NULL;
	p1=p2=(struct phonenum *)malloc(LENGTH);
	strcpy_s(p1->name,"yangxiang"),p1->num=13227887598;
	for(i=1;i<6;i++)
	{
		if(i==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct phonenum *)malloc(LENGTH);
		switch(i)
		{
			case 1:strcpy_s(p1->name,"chenxiang"),p1->num=15129296922;break;
			case 2:strcpy_s(p1->name,"xiaozheng"),p1->num=18192420553;break;
			case 3:strcpy_s(p1->name,"lihui"),p1->num=18220483819;break;
			case 4:strcpy_s(p1->name,"qinqin"),p1->num=15273190710;break;
			case 5:strcpy_s(p1->name,"erdan"),p1->num=18049025639;
		}
	}
	p2->next=p1;
	p1->next=NULL;
	return (head);
}
struct phonenum *insertnum(struct phonenum *head)
{
	struct phonenum *p,*p1;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	p1=(struct phonenum *)malloc(LENGTH);
	printf("请输入新的联系人姓名和电话号码：");
	scanf_s("%s%lld",p1->name,&p1->num);
	p->next=p1;
	p1->next=NULL;
	printf("添加完成！\n");
	return (head);
}
struct phonenum *inquiry(struct phonenum *head)
{
	struct phonenum *find;
	int done;
	find=head;
	for(;;)
	{
		printf("姓名查询（输入“1”）或是 电话号码查询（输入“2”）\n");
		scanf_s("%d",&done);
		if((done==1)||(done==2))break;
		printf("请重新输入");
	}
	if(done==1)
	{
		char nametarget[20];
		printf("输入您所要查找的电话号码的联系人姓名：");
		scanf_s("%s",nametarget);
		while(find!=NULL)
		{
			if(!strcmp(find->name,nametarget))
				return (find);
			find=find->next;
		}
	}
	if(done==2)
	{
		long long numtarget;
		printf("请输入您所要查找的联系人的电话号码：");
		scanf_s("%lld",&numtarget);
		while(find!=NULL)
		{
			if(find->num==numtarget)
				return (find);
			find=find->next;
		}
	}
	return NULL;
}
struct phonenum *deletenum(struct phonenum *head)
{
	struct phonenum *p1,*p2,*find1;
	printf("删除联系人\n");
	find1=inquiry(head);
	if(find1==NULL)
	{
		printf("查无此人，请重新输入：\n");
		deletenum(head);
	}
	else if(find1==head)
	{
		head=find1->next;
		printf("联系人已删除！\n");
	}
	else{
		p1=lastnode(find1,head);
		p2=find1->next;
		p1->next=p2;
		printf("联系人已删除！\n");
		return (head);
	}
}
struct phonenum *modifynum(struct phonenum *head)
{
	struct phonenum *find2;
	find2=inquiry(head);
	if(find2==NULL)
	{
		printf("查无此人，请重新输入：\n");
		modifynum(head);
	}
	else
	{
		printf("请输入更正后的联系人姓名和电话号码：");
		scanf_s("%s%lld",find2->name,&find2->num);
		printf("\n修改完成！\n");
		return (head);
	}
}
struct phonenum *sequencename(struct phonenum *head)
{
	struct phonenum *p1,*p2,*p3,*p4;
	int i,n,done;
	p1=p2=p3=p4=head;
	n=length(head);
	for(i=0;i<n;i++)
	{
		done=1;
		while(p1->next!=NULL)
		{
			if(strcmp(p1->name,p1->next->name)<=0&&(p1==head))
			{
				p2=p1->next;
				p3=p2->next;
				p1->next=p3;
				p2->next=p1;
				head=p2;
				p2=p3=p4=p1;
				done=0;
				continue;
			}
			if(strcmp(p1->name,p1->next->name)<=0&&(p1->next->next==NULL))
			{
				p1=lastnode(p1,head);
				p2=p1->next;
				p3=p2->next;
				p1->next=p3;
				p3->next=p2;
				p2->next=NULL;
				p1=p3=p4=p2;
				done=0;
				continue;
			}
			if(strcmp(p1->name,p1->next->name)<=0&&(p1!=head))
			{
				p1=lastnode(p1,head);
				p2=p1->next;
				p3=p2->next;
				p4=p3->next;
				p1->next=p3;
				p3->next=p2;
				p2->next=p4;
				p3=p1=p4=p2;
				done=0;
				continue;
			}
			p1=p1->next;
		}
		p1=p2=p3=p4=head;
		if(done)break;
	}
	head=reversal(head,length(head));
	printf("按照联系人电话号码排序完成！\n");
	return (head);
}
struct phonenum *sequencenum(struct phonenum *head)
{
	struct phonenum *p1,*p2,*p3,*p4;
	int i,n,done;
	p1=p2=p3=p4=head;
	n=length(head);
	for(i=0;i<n;i++)
	{
		done=1;
		while(p1->next!=NULL)
		{
			if((p1->num<p1->next->num)&&(p1==head))
			{
				p2=p1->next;
				p3=p2->next;
				p1->next=p3;
				p2->next=p1;
				head=p2;
				p2=p3=p4=p1;
				done=0;
				continue;
			}
			if((p1->num<p1->next->num)&&(p1->next->next==NULL))
			{
				p1=lastnode(p1,head);
				p2=p1->next;
				p3=p2->next;
				p1->next=p3;
				p3->next=p2;
				p2->next=NULL;
				p1=p3=p4=p2;
				done=0;
				continue;
			}
			if((p1->num<p1->next->num)&&(p1!=head))
			{
				p1=lastnode(p1,head);
				p2=p1->next;
				p3=p2->next;
				p4=p3->next;
				p1->next=p3;
				p3->next=p2;
				p2->next=p4;
				p3=p1=p4=p2;
				done=0;
				continue;
			}
			p1=p1->next;
		}
		p1=p2=p3=p4=head;
		if(done)break;
	}
	head=reversal(head,length(head));
	printf("按照联系人电话号码排序完成！\n");
	return (head);
}
void print(struct phonenum *head)
{
	struct phonenum *p;
	p=head;
	if(p==NULL)printf("通讯录为空！");
	while(p!=NULL)
	{
		printf("联系人姓名：%-20s联系人电话号码：%lld\n",p->name,p->num);
		p=p->next;
	}
}
struct phonenum *lastnode(struct phonenum *node,struct phonenum *head)
{
	struct phonenum *lastnode;
	lastnode=head;
	while(lastnode->next!=node)
		lastnode=lastnode->next;
	return lastnode;
}
struct phonenum *reversal(struct phonenum *head,int n)
{
	struct phonenum *p3,*p0,*p1,*p2;
	int i=0;
	p3=p0=p1=p2=head;
	do
	{
		i++;
		do
		{
			p2=p1;
			p1=p1->next;
		}while(p1->next!=NULL);
		p1->next=p0;
		p2->next=NULL;
		if(i!=1)
			p3->next=p1;	
		p3=p1;
		if(i==1)head=p1;
		p2=p1=p0;
	}while(i!=(n-1));
	return (head);
}
void printinquiry(struct phonenum *head)
{
	struct phonenum *find3;
	find3=inquiry(head);
	if(find3==NULL)
	{
		printf("查无此人，请重新输入：\n");
		printinquiry(head);
	}
	else
		printf("联系人姓名：%s\n联系人电话号码：%lld\n",find3->name,find3->num);
}
int length(struct phonenum *head)
{
	struct phonenum *p;
	int n=0;
	p=head;
	do{
		p=p->next;
		n++;
	}while(p!=NULL);
	return n;
}