include"stdio.h"
void main()
{
	int dayth;
	struct date
	{
		int year;
		int month;
		int day;
	}date;
	printf("please in put date:");
	scanf_s("%d%d%d",&date.year,&date.month,&date.day);
	switch (date.month)
	{
		case 1:dayth=date.day;break;
		case 2:dayth=date.day+31;break;
		case 3:dayth=date.day+59;break;
		case 4:dayth=date.day+90;break;
		case 5:dayth=date.day+120;break;
		case 6:dayth=date.day+151;break;
		case 7:dayth=date.day+181;break;
		case 8:dayth=date.day+212;break;
		case 9:dayth=date.day+243;break;
		case 10:dayth=date.day+273;break;
		case 11:dayth=date.day+304;break;
		case 12:dayth=date.day+334;
	}
	if((date.year%100==0&&date.year%400==0)||(date.year%100!=0&&date.year%4==0))
		if(date.month>2)
			dayth++;
	if(date.month==1&&date.day==1)
		printf("this is the 1st day of the year.");
	else if(date.month==1&&date.day==2)
		printf("this is the 2nd day of the year.");
	else
		printf("this is the %dth day of the year.",dayth);
}