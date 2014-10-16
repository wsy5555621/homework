/**************************************************************************************************/
/* Copyright (C)  2014-2015                                                                       */
/*                                                                                                */
/*  FILE NAME             :  Taxcalculate.h                                                       */
/*  PRINCIPAL AUTHOR      :  Wangshenyu                                                           */
/*  SUBSYSTEM NAME        :  Tax                                                                  */
/*  MODULE NAME           :  Tax                                                                  */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/10/15                                                           */
/*  DESCRIPTION           :  This is a tax calculate                                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by wsy,2014/10/15.
 *
 */
 
#ifndef _Taxcalculate_H_

#include<stdio.h>

/*
 * A program for tax calculate.
 */

/*warning:you should set tax's base number and its rate through the functions SetTaxBase() and
 SetTaxRate() when you use funciton TaxCalculatemain(float income);*/


/*an array for tax's base number*/
float TaxBase[5];

/*an array about taxrate for each tax's base number */
float TaxRate[5];

/*an array about part of tax summary for each tax's base number*/
float PartTaxSum[5];

/*follow the prompt you can set tax's base number*/
void SetTaxBase();

/*follow the prompte you can set each rate for each tax's base number*/
void SetTaxRate();

/*get your tax*/
void TaxCalculatemain(float income);

#endif /* _Taxcalculate_H_*/


/**************************************************************************************************/
/* Copyright (C)  2014-2015                                                                       */
/*                                                                                                */
/*  FILE NAME             :  taxtest.c                                                            */
/*  PRINCIPAL AUTHOR      :  Wangshenyu                                                           */
/*  SUBSYSTEM NAME        :  Tax                                                                  */
/*  MODULE NAME           :  Tax                                                                  */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/10/15                                                           */
/*  DESCRIPTION           :  This is a tax calculate test progrom                                 */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by wsy,2014/10/15.
 *
 */

#include<stdio.h>
//#include"Taxcalculate.h"   /*若文件分为.h .c 运行,请把此行注释"//"去掉*/


int main()
{
/*本程序提供用户自定义征税范围和税率接口,本测试程序为方便测试,直接赋予征税范围和税率的值.*/
	TaxBase[0]=0;
	TaxBase[1]=10000;
	TaxBase[2]=20000;
	TaxBase[3]=30000;
	TaxBase[4]=40000;
	TaxRate[0]=0.1;
	TaxRate[1]=0.12;
	TaxRate[2]=0.15;
	TaxRate[3]=0.18;
	TaxRate[4]=0.20;
/*本测试程序测试1000,10000,22000,33333,44444五种收入需交税的值.*/
	printf("*******************************************************\n");
	float test[5]={1000,10000,22000,33333,44444};
	int i;
	for(i=0;i<5;i++)
	{
		printf("For the income %.2f \n",test[i]);
		TaxCalculatemain(test[i]);
	}
	printf("*******************************************************\n");
}




/**************************************************************************************************/
/* Copyright (C)  2014-2015                                                                       */
/*                                                                                                */
/*  FILE NAME             :  Taxcalculate.c                                                       */
/*  PRINCIPAL AUTHOR      :  Wangshenyu                                                           */
/*  SUBSYSTEM NAME        :  Tax                                                                  */
/*  MODULE NAME           :  Tax                                                                  */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/10/15                                                           */
/*  DESCRIPTION           :  This is a tax calculate                                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by wsy,2014/10/15.
 *
 */

#include<stdio.h>
#include<stdlib.h>

/*arrays for store data*/
float TaxBase[5];
float TaxRate[5];
float PartTaxSum[5];

void SetTaxBase();
void SetTaxRate();
void CalculatePartTaxSum();

/*get your tax*/
void TaxCalculatemain(float income)
{
	int i;
	int k;
	float TotalTax;
	CalculatePartTaxSum();
	for(i=0;i<5;i++)
	{
		if(income>=TaxBase[i]&&income<=TaxBase[i+1])
		{
			k=i;
			break;
		}
		k=i;
	}
	TotalTax=(income-TaxBase[k])*TaxRate[k]+PartTaxSum[k];
	printf("The total tax you should pay is:%.2f\n",TotalTax);
}

/*follow the prompt you can set tax's base number*/
void SetTaxBase()
{
	printf("Please set your tax rank,and you should start with the number 0;\n");
	int i;	
	float taxrank;
	for(i=0;i<5;i++)
	{
		printf("For the no.%d's number:\n",i);
		scanf("%f",&taxrank);
		TaxBase[i]=taxrank;
	}
}

/*follow the prompte you can set each rate for each tax's base number*/
void SetTaxRate()
{
	printf("Please set your tax rate for each rank.\n");
	int i;	
	float taxrate;
	for(i=0;i<5;i++)
	{
		printf("For the no.%d's rate:\n",i);
		scanf("%f",&taxrate);
		TaxRate[i]=taxrate;
	}
}

/*calculate part of tax summary for each tax's base number*/
void CalculatePartTaxSum()
{
	int i;
	PartTaxSum[0]=0;
	for(i=1;i<5;i++)
	{
		PartTaxSum[i]=(TaxBase[i]-TaxBase[i-1])*TaxRate[i-1]+PartTaxSum[i-1];
	} 
}























