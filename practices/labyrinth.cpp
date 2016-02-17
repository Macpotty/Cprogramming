#include"stdio.h"
#include"stdlib.h"
#define LENTH sizeof(struct stack)
struct step{
	int horiz;
	int vert;
};															//�˽ṹ�����ڸ�������
struct step move[4]={ 0,1,0,-1,1,0,-1,0 }; 					//(0,1)Ϊ������һ��(0,-1)Ϊ������һ��(1,0)Ϊ������һ��(-1,0)Ϊ������һ��
struct stack{
	int horiz;
	int vert;
	int forks;
	struct stack *next;
};															//�˽ṹ�����ڼ�¼�߹������꣬������ջ�ڵ�
int maze[10][10] = {{1,1,1,1,1,1,1,1,1,1},{1,2,0,0,1,1,1,1,1,1},{1,1,1,0,1,0,0,0,1,1},{1,1,1,0,1,0,1,0,1,1},{1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,1,1,0,1,1},{1,1,1,0,0,0,0,0,1,1},{1,1,1,0,1,1,1,0,1,1},{1,0,0,0,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
															/* �������Թ��ĵ�ͼ�������Զ�ά�����ʾ������0����ͨ·��1����ǽ��2�����߹���·����㣩�����row��col�����ص���ݡ�������*/
int row=8,col=1;
struct stack *push(struct stack *top,int horiz,int vert);	//��ջ����
struct stack *pop(struct stack *top);						//��ջ����
int lenth(struct stack *top);								//��ջ���ȣ����ڼ����ߵ��յ�����Ҫ�Ĳ�����
void print(struct stack *top);								//ջ�ı��������ڸ������յ�·����
int StackTopHoriz(struct stack *top);						//ȡջ��������
int StackTopVert(struct stack *top);						//ȡջ��������
int fork(int i,int j);										//�ж���һ�������ߵķ����������ж��Ƿ�Ϊ��·�Լ��Ƿ�Ϊ��·��
int main(){
	int i=1,j=1,k,a,m;										//i-������    j-������    k-��һ������    a-����ڵ����ڵĲ���    m-�����ߵķ�������
	struct stack *top1=NULL;								//ջ1���ڼ�¼�����߹�������	
	struct stack *top2=NULL;								//ջ2���ڼ�¼�����߹���û����Ĳ�·�������ߵ���·��ʱ���˻أ�
	while((i!=row)||(j!=col)){
		for(k=0,m=0;k<4;k++){
			if(maze[i+move[k].vert][j+move[k].horiz]==0){
				m=1;
				if(fork(i,j)>1){
					top2=push(top2,j,i);
					m=fork(i,j);
				}
				i+=move[k].vert;
				j+=move[k].horiz;
				maze[i][j]=2;
				top1=push(top1,j,i);
			}
		}
		if(!m){												//�����ж��Ƿ��ߵ���·
			i=StackTopVert(top2);
			j=StackTopHoriz(top2);
			if(fork(i,j)==1)
				top2=pop(top2);
		}
	}
	a=lenth(top1);
	printf("%-2d\n",a);
	print(top1);
}
struct stack *push(struct stack *top,int horiz,int vert){
	struct stack *p;
	p=(struct stack *)malloc(LENTH);
	p->horiz=horiz;
	p->vert=vert;
	p->next=top;
	maze[vert][horiz]=2;
	return p;
}
struct stack *pop(struct stack *top){
	struct stack *p;
	if(top==NULL){
		printf("��ջ������");
		return NULL;
	}
	else{
		p=top->next;
		maze[top->vert][top->horiz]=1;
		free(top);
		return p;
	}
}
void print(struct stack *top){
	struct stack *p;
	p=top;
	do{
		printf("%2d%2d\n",p->horiz,p->vert);
		p=p->next;
	}while(p!=NULL);
}
int StackTopHoriz(struct stack *top){
	if(top==NULL){
		printf("��ջ");
		return NULL;
	}
	else
		return top->horiz;
}
int StackTopVert(struct stack *top){
	if(top==NULL){
		printf("��ջ");
		return NULL;
	}
	else
		return top->vert;
}
int lenth(struct stack *top){
	struct stack *p;
	int n=0;
	p=top;
	while(p->next!=NULL){
		p=p->next;
		n++;
	};
	return n;
}
int fork(int i,int j){
	int k,m;
	for(k=0,m=0;k<4;k++){
		if(maze[i+move[k].vert][j+move[k].horiz]==0){
			m++;
		}
	}
	return m;
}