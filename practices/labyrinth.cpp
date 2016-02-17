#include"stdio.h"
#include"stdlib.h"
#define LENTH sizeof(struct stack)
struct step{
	int horiz;
	int vert;
};															//此结构体用于给出方向
struct step move[4]={ 0,1,0,-1,1,0,-1,0 }; 					//(0,1)为向下走一步(0,-1)为向上走一步(1,0)为向右走一步(-1,0)为向左走一步
struct stack{
	int horiz;
	int vert;
	int forks;
	struct stack *next;
};															//此结构体用于记录走过的坐标，构成链栈节点
int maze[10][10] = {{1,1,1,1,1,1,1,1,1,1},{1,2,0,0,1,1,1,1,1,1},{1,1,1,0,1,0,0,0,1,1},{1,1,1,0,1,0,1,0,1,1},{1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,1,1,0,1,1},{1,1,1,0,0,0,0,0,1,1},{1,1,1,0,1,1,1,0,1,1},{1,0,0,0,1,1,1,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
															/* 上面是迷宫的地图画法，以二维数组表示，其中0代表通路，1代表墙，2代表走过的路（起点）下面的row和col代表重点的纵、横坐标*/
int row=8,col=1;
struct stack *push(struct stack *top,int horiz,int vert);	//入栈操作
struct stack *pop(struct stack *top);						//出栈操作
int lenth(struct stack *top);								//求栈长度（用于计算走到终点所需要的步数）
void print(struct stack *top);								//栈的遍历（用于给出最终的路径）
int StackTopHoriz(struct stack *top);						//取栈顶横坐标
int StackTopVert(struct stack *top);						//取栈顶纵坐标
int fork(int i,int j);										//判断下一步可以走的方向数量（判断是否为岔路以及是否为死路）
int main(){
	int i=1,j=1,k,a,m;										//i-纵坐标    j-横坐标    k-下一步方向    a-从入口到出口的步数    m-可以走的方向数量
	struct stack *top1=NULL;								//栈1用于记录所有走过的坐标	
	struct stack *top2=NULL;								//栈2用于记录所有走过但没走完的岔路（方便走到死路的时候退回）
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
		if(!m){												//用于判断是否走到死路
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
		printf("空栈，下溢");
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
		printf("空栈");
		return NULL;
	}
	else
		return top->horiz;
}
int StackTopVert(struct stack *top){
	if(top==NULL){
		printf("空栈");
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