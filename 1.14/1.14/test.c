#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int Add(int x,int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("*************************\n");
//	printf("****  1.Add  2.Sub   ****\n");
//	printf("****  3.Mul  4.Div   ****\n");
//	printf("*************************\n");
//}
//int main()
//{
//	int input;
//	int x, y;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 3:printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 4:printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 0:printf("退出计算机\n");
//			break;
//		default:printf("输入错误\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}
//代码2

	/*void (  *signal(int, void(*)(int))  )(int);*/
	//这是一个函数声明；
	//声明的函数名称叫signal
	//signal函数有两个参数，第一个是int类型，第二个是函数指针类型，该函数指针指向那个函数的参数是int，返回值为void
	//signal函数的返回值类型也是一个函数指针，该函数指针指向的函数的参数是int返回值是void
	//(*(void (*)())0)();
	////这是个函数调用
	////调用0地址处的一个函数
	////首先将0强制类型转化成（void(*)()）类型的函数指针2
	////然后*解引用调用0处地址的函数
//int main()
//{
//	int input=1;
//	int x, y;
//	int ret = 0;
//	int(*pf[5])(int x ,int y )={0,Add,Sub,Mul,Div};//函数指针数组，存放着函数的地址可以通过下标来找到函数的地址
//	while (input)
//	{
//		menu();
//		printf("请选择:\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入操作数：\n");
//			scanf("%d %d", &x, &y);
//			ret=(*pf[input])(x, y);//函数调用
//			printf("ret=%d\n", ret);
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//		
//	}
//}
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	test("hello,tao");
//	//函数指针pf
//	void(*pf)(const char*) = test;
//	//函数指针数组pf1[]
//	void(*pf1[5])(const char*) = { NULL,test };
//	//指向函数指针数组的指针ppf
//	void (* [5])(const char*) = &pf1;
//	return 0;
//}(*ppf)
//对整数数组排序
//#include <stdlib.h>

//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), com_int);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
struct Stu
{
	char name[20];
	int age;
};

//按照姓名来排序
//#include <string.h>
//int com_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//int main()
//{
//	struct Stu s[3] = { {"zhangsan",19},{"lisi",32},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), com_by_name);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].name);
//	}
//	return 0;
//}
//利用冒泡思想模拟qsort函数
//com_int是设计者自己根据比较什么类型的数据而设计的比较函数
int com_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void Swap( char* e1, char* e2,size_t width)
{
	int i;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void bubble_qsort(void* base, size_t num, size_t width, int(*com_int)(const void* e1, const void* e2))
{
	int i, j;
	//利用冒泡排序思想
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//比较函数，比较两个元素的大小
			if (com_int((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}

		}
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), com_int);
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#include <string.h>
int com_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
//int main()
//{
//	struct Stu s[3] = { {"zhangsan",19},{"lisi",32},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_qsort(s, sz, sizeof(s[0]), com_by_name);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].name);
//	}
//	return 0;
//}
////按照年龄排序；
//int com_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int main()
//{
//	struct Stu s[3] = { {"zhangsan",19},{"lisi",32},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), com_by_age);
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", s[i].age);
//	}
//	return 0;
//}