#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"calendar.h"
#include <ctype.h>
#include<string.h>
#include<conio.h>
//#include"curses.h"//getch need library in linux
#define LEAP 366
#define NONLEAP 365
//int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int input()
{
	char s[100];
	printf("\t\t\t\t������Ҫ��ѯ����ݣ�1-3000):\n");
	int flag = 0, i, year;

	scanf("%s", s);
	for (i = 0; i < strlen(s); ++i)
	{
		if (!isdigit(s[i]))
			flag = -1;
	}
	if (flag == -1)
		year = flag;
	else
		year = atoi(s);
	year = estimate_input(year);
	//getchar();
	return year;
}

int estimate_input(const int year)
{
	if (year < 1 || year>3000)
	{
		printf("error\n");
		return input();
	}
	else
		return year;
}
int estimate_years(const int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return LEAP;
	}
	else
		return NONLEAP;
}
int first_day(const int year)
{
	int sum_year = 0;
	for (int i = 1; i <= year; ++i)
	{
		sum_year += estimate_years(i);
	}
	return ((sum_year) % 7);    //��һ�µ����һ��
}
cal init(const int year)
{
	cal info;
	info.year = year;
	info.leap = estimate_years(year);
	info.firstdayofmonth = first_day(year);//�ϸ��µ����һ��
	info.daysofmonth = 31;
	info.month = Jan;
	return info;
}
/* enum to string */
void enum2String(cal info)
{
	const char *string = " ";
	switch (info.month)
	{
	case Jan: string = "һ��";
		break;
	case Feb: string = "����";
		break;
	case Mar: string = "����";
		break;
	case Apr: string = "����";
		break;
	case May: string = "����";
		break;
	case Jun: string = "����";
		break;
	case Jul: string = "����";
		break;
	case Aug: string = "����";
		break;
	case Sept: string = "����";
		break;
	case Oct: string = "ʮ��";
		break;
	case Nov: string = "ʮһ��";
		break;
	case Dec: string = "ʮ����";
		break;
	default:printf("err");
		break;
	}
	printf("\t\t\t\t%d��\t\t %s\n", info.year, string);
}
cal setMonthInfo(cal info)
{
	int m;
	info.firstdayofmonth = (info.firstdayofmonth + info.daysofmonth) % 7;
	info.month = info.month + 1;
	info.daysofmonth = 30;
	m = info.month;
	if (m == Jan || m == Mar || m == May || m == Jul || m == Aug || m == Oct || m == Dec)
		info.daysofmonth = 31;
	if (m == Feb)
	{
		if (info.leap == LEAP)
			info.daysofmonth = 29;
		else
			info.daysofmonth = 28;
	}
	return info;
}
void printMonth(cal info)
{
	//  for(int i=Jan;i<=Dec;++i)
	//  {
	printf("\t\t\t");
	for (int date = 0; date != info.firstdayofmonth; ++date)
	{
		printf("%s\t ", "");
	}
	for (int day = 1; day <= info.daysofmonth; ++day)
	{
		printf("%d\t ", day);
		if ((info.firstdayofmonth + day) % 7 == 0)
			printf("\n\t\t\t");
	}
	printf("\n\t\t\t------------------------------------------------------\n\n");
	printf("��ESC�˳�����������\n");
	if (_getch() == 27)
		isContinueSearch();

	//    }
}
/*
void FebMonth(const int year)
{
	if(estimate_years(year))
		month_day[2]=29;
}


void output()
{
  int year;
  year=input();
  FebMonth(year);
   int first=first_day(year);
   for(int i=Jan;i<=Dec;++i)
   {
	// printf("%dmonth\n",i+1);
	// printf("%s\n",month2String[i]);
	 enum2String(i);
	 printf("%3.5s %3.5s %3.5s %3.5s %3.5s %3.5s %3.5s\n"," �?,"一","�?,"�?,"�?,"�?,"�?);
	 for(int date=0;date!=first;++date)
	 {
		 printf("%3s","");

	 }
	 for(int day=1;day<=month_day[i];++day)
	 {
		printf("%3d",day);
		if((first+day)%7==0)
	 //   if((sum+first)%7==0)
		 printf("\n");
	   //  printf("%3d",day);


	 }
	 first=(first+month_day[i])%7;
	 printf("\n");
   //  system("pause");
	 getchar();
   }
}
*/
void print()
{
	int year;
	year = input();
	info = init(year);
	//   while(info.month!=Dec+1)
	for (; info.month <= Dec;)
	{

		enum2String(info);
		printf("\t\t\t------------------------------------------------------\n");
		printf("\t\t\t\%s\t %s\t %s\t %s\t %s\t %s\t %s\t\n", "��", "һ", "��", "��", "��", "��", "��");
		printMonth(info);
		info = setMonthInfo(info);
	}
}
int output()
{
	print();
	isContinueSearch();
	return 0;

}
int isContinueSearch()
{
	//system("pause");
	//_getch();
	fflush(stdin);
	printf("�Ƿ��ѯ�������y or n:\n");
	char ch;
	ch = getchar();
	//  printf("%s",ch);
	if (ch == 'Y' || ch == 'y')
		output();
	else if (ch == 'N' || ch == 'n')
	{
		exit(0);
	}
	else
	{
		printf("error\n");
		//_getch();
		isContinueSearch();

	}
	/*char ch=getchar();
	 switch(ch)
	 {
	 case'Y':output_1();break;
	 case'N':exit(0);break;
	 default:printf("error");break;

	 }*/
}
/*    ����д��ʼ�˵��� ,landuo /(��o��)/~~*/
/*
 void startmenu()
{
   printf("\t\t��ӭʹ��������\t\t")
   printf("��ѯ-1\n");
   printf("�˳�-Esc");
   printf("********************************end****************************************\n");

   if(getchar()==27)
   exit(0);
   if(getchar()==1)
	input();
   }
*/
int  main()
{
	// if(getchar()=='Y'||getchar()=='y')
	output();

}
