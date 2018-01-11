/**
* ���ݷ���N�ʺ�����
* ʹ��һ��һά�����ʾ�ʺ��λ��
* ����������±��ʾ�ʺ����ڵ���
* ����Ԫ�ص�ֵ��ʾ�ʺ����ڵ���
* ������Ƶ����̣����лʺ�ض�����ͬһ�У������г�ͻ�Ͳ�������
* date  : 2011-08-03 
* author: liuzhiwei
**/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUEEN 8     //�ʺ����Ŀ
#define INITIAL -10000   //���̵ĳ�ʼֵ

int a[QUEEN];    //һά�����ʾ����

void init()  //�����̽��г�ʼ��
{
	int *p;
	for (p = a; p < a + QUEEN; ++p) 
	{
		*p = INITIAL;
	}
} 

int valid(int row, int col)    //�жϵ�row�е�col���Ƿ���Է��ûʺ�
{
	int i;
	for (i = 0; i < QUEEN; ++i)   //�����̽���ɨ��
	{
		if (a[i] == col || abs(i - row) == abs(a[i] - col))   //�ж��г�ͻ��б���ϵĳ�ͻ
			return 0;
	}
	return 1;
} 

void print()    //��ӡ���N�ʺ��һ���
{
	int i, j;
	for (i = 0; i < QUEEN; ++i)
	{
		for (j = 0; j < QUEEN; ++j)
		{
			if (a[i] != j)      //a[i]Ϊ��ʼֵ
				printf("%c ", '.');
			else                //a[i]��ʾ�ڵ�i�еĵ�a[i]�п��Է��ûʺ�
				printf("%c ", '#');
		}
		printf("\n");
	}
	for (i = 0; i < QUEEN; ++i)
		printf("%d ", a[i]);
	printf("\n");
	printf("--------------------------------\n");
}

void queen()      //N�ʺ����
{
	int n = 0;
	int i = 0, j = 0;
	while (i < QUEEN)
	{
		while (j < QUEEN)        //��i�е�ÿһ�н���̽�⣬���Ƿ���Է��ûʺ�
		{
			if(valid(i, j))      //��λ�ÿ��Է��ûʺ�
			{
				a[i] = j;        //��i�з��ûʺ�
				j = 0;           //��i�з��ûʺ��Ժ���Ҫ����̽����һ�еĻʺ�λ�ã����Դ˴���j���㣬����һ�еĵ�0�п�ʼ����̽��
				break;
			}
			else
			{
				++j;             //����̽����һ��
			}
		}
		if(a[i] == INITIAL)         //��i��û���ҵ����Է��ûʺ��λ��
		{
			if (i == 0)             //���ݵ���һ�У���Ȼ�޷��ҵ����Է��ûʺ��λ�ã���˵���Ѿ��ҵ����еĽ⣬������ֹ
				break;
			else                    //û���ҵ����Է��ûʺ���У���ʱ��Ӧ�û���
			{
				--i;
				j = a[i] + 1;        //����һ�лʺ��λ��������һ��
				a[i] = INITIAL;      //����һ�лʺ��λ�����������̽��
				continue;
			}
		}
		if (i == QUEEN - 1)          //���һ���ҵ���һ���ʺ�λ�ã�˵���ҵ�һ���������ӡ����
		{
			printf("answer %d : \n", ++n);
			print();
			//�����ڴ˴�����������Ϊ����Ҫ�ҵ���N�ʺ���������н⣬��ʱӦ��������еĻʺ󣬴ӵ�ǰ���ûʺ���������һ�м���̽�⡣
			//_sleep(600);
			j = a[i] + 1;             //�����һ�з��ûʺ���������һ�м���̽��
			a[i] = INITIAL;           //������һ�еĻʺ�λ��
			continue;
		}
		++i;              //����̽����һ�еĻʺ�λ��
	}
}

int main(void)
{
	init();
	queen();
	system("pause");
	return 0;
}
