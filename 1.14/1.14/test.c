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
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = Add(x, y);
//			printf("ret=%d\n", ret);
//			break;
//		case 2:printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = Sub(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 3:printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = Mul(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 4:printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret = Div(x, y);
//			printf("ret=%d\n", ret); 
//			break;
//		case 0:printf("�˳������\n");
//			break;
//		default:printf("�������\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}
//����2

	/*void (  *signal(int, void(*)(int))  )(int);*/
	//����һ������������
	//�����ĺ������ƽ�signal
	//signal������������������һ����int���ͣ��ڶ����Ǻ���ָ�����ͣ��ú���ָ��ָ���Ǹ������Ĳ�����int������ֵΪvoid
	//signal�����ķ���ֵ����Ҳ��һ������ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int����ֵ��void
	//(*(void (*)())0)();
	////���Ǹ���������
	////����0��ַ����һ������
	////���Ƚ�0ǿ������ת���ɣ�void(*)()�����͵ĺ���ָ��2
	////Ȼ��*�����õ���0����ַ�ĺ���
//int main()
//{
//	int input=1;
//	int x, y;
//	int ret = 0;
//	int(*pf[5])(int x ,int y )={0,Add,Sub,Mul,Div};//����ָ�����飬����ź����ĵ�ַ����ͨ���±����ҵ������ĵ�ַ
//	while (input)
//	{
//		menu();
//		printf("��ѡ��:\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("�������������\n");
//			scanf("%d %d", &x, &y);
//			ret=(*pf[input])(x, y);//��������
//			printf("ret=%d\n", ret);
//		}
//		else
//		{
//			printf("�������\n");
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
//	//����ָ��pf
//	void(*pf)(const char*) = test;
//	//����ָ������pf1[]
//	void(*pf1[5])(const char*) = { NULL,test };
//	//ָ����ָ�������ָ��ppf
//	void (* [5])(const char*) = &pf1;
//	return 0;
//}(*ppf)
//��������������
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

//��������������
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
//����ð��˼��ģ��qsort����
//com_int��������Լ����ݱȽ�ʲô���͵����ݶ���ƵıȽϺ���
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
	//����ð������˼��
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//�ȽϺ������Ƚ�����Ԫ�صĴ�С
			if (com_int((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				//����
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
////������������
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