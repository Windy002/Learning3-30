#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* 
int add(int x,int y)
{
	return x+y;
}

int main()
{
	//ָ������
	int* arr[7];
	//ָ��ָ�������ָ�� 
	int* (*pa)[7]; 
	//����ָ��
	int (*padd)(int,int)=add; //=&add --��������  
	int sum=(*padd)(1,2);  
	//int sum=(padd)(1,2); // �������á�������ַ��*�벻��*��һ�� 
	printf("%d\n",sum); //�������� 
	//����ָ������� 
	 int (*parr[7])(int,int);
	 //ָ����ָ�������ָ��
	 int (*(*pparr)[7](int,int))=&parr;
	 //�ص�����--ͨ������ָ����õĺ�������������õĺ����ͽ����ص�����
	 // qsort ������ԭ�� 
	  
	
	return 0;
}
*/



/*void bubble_sort(int arr[],int sz)
{
	int i=0;
	for(i=0;i<sz-1;i++)
	  {
		int j=0;
		 for(j=0;j<sz-1-i;j++)
		   {
		  	 if(arr[j]> arr[j+1])
		  	    {
		  	   	  int t=arr[j];
		  	   	  arr[j]=arr[j+1];
		  	   	  arr[j+1]=t;
			    }
		   }
	  }  
}*/

struct students 
{
	char name[20];
	int age; 
} stu;


int cmp_int(const void* e1,const void* e2)
{
	//�Ƚ���������ֵ�Ĵ�С 
	return *(int*)e1 - *(int*)e2 ;  


}
void test1()
{
	int arr[10]={9,8,7,6,5,4,3,2,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
		qsort(arr, sz, sizeof(arr[0]), cmp_int);//qsort��һ������Ϊ������Ԫ�ص�ַ 
	
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	putchar('\n');

}


int cmp_f(const void* e1,const void* e2)
{
	//�Ƚ�����������ֵ�Ĵ�С
/*	if( *(float*)e1==*(float*)e2)
		return 0;
	if( *(float*)e1>*(float*)e2)
		return 1;
	if( *(float*)e1<*(float*)e2)
		return -1;
*/
	return ( (int) ( *(float*)e1 - *(float*)e2 ) ) ; //float���԰ѽ����תΪ���ͷ��� �������ͷ��ϱ�׼��
}
void test2()
{
	 float f[]={2.2,1.7,9.7,7.2,3.7,5.7,5.2};
	 int sz=sizeof(f)/sizeof(f[0]);
	 qsort(f, sz, sizeof(f[0]), cmp_f); //qsort��һ������Ϊ������Ԫ�ص�ַ 
	
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%.1f ",f[i]);
	}
	putchar('\n');

}



int cmp_stu_age(const void* e1,const void*e2)
{
	return ( (struct students* ) e1)->age - ( (struct students* )e2 )->age ;
	//����Ƚϵ������䣬nameΪ�ַ������ͣ�������> = < �Ƚ�  Ҫ��strcmp
	//return strcmp( ( (struct students*) e1)->name , ( (struct students*) e2)->name ) ;
}
int cmp_stu_name(const void* e1,const void*e2)
{

	return strcmp( ( (struct students*) e1)->name , ( (struct students*) e2)->name ) ;
}
void test3()
{
	struct students stu[3]={{"wind",19},{"Turing",27},{"Gern Win",20}};
	int sz=sizeof(stu)/sizeof(stu[0]);
	
	qsort(stu, sz, sizeof(stu[0]), cmp_stu_name);
	
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%s %d\n",stu[i].name,stu[i].age);
	}
	
} 


void swap(char* buf1, char* buf2, int width)
{
	int i=0;
	for(i=0;i<width;i++)
	  {
	  	char tmp=*buf1;
	  	*buf1=*buf2;
	  	*buf2=tmp;
	  	buf1++;
	  	buf2++;
	  } 
}
//ʵ��bubble_sort�����ĳ���Ա�����Ƿ�֪��δ�������������͡�����֪��
//�ǳ���ԱҲ��֪�������Ƚϵ�����Ԫ�ص����� 
void bubble_sort(void* base, int sz ,int width, int (*cmp)( void* p1, void* p2) )
{
	int i=0;
	//����
	for(i=0; i<sz-1; i++)
	  {
	  	 int j=0;
	  	 //ÿһ�˴Ӷ���
		 for(j=0; j<sz-1-i; j++) 
		   {
		   	 //��Ԫ�صıȽ�
			 if(cmp( (char*)base +j*width , (char*)base + (j+1)*width) > 0) //���� 
			   {
			   	 //����
					swap( (char*)base +j*width , (char*)base + (j+1)*width ,width );	 
			   } 
		   } 
	  } 
}
void test4()
{
//	int arr[10]={9,8,7,6,5,4,3,2,1,0};	
//	int sz=sizeof(arr)/sizeof(arr[0]);
	//�ٶ�ʹ��bubble����sort����Աһ��֪���Լ��������ʲô����
	//��Ӧ��֪����αȽ����������е�Ԫ�� 
	struct students stu[3]={{"wind",19},{"Turing",27},{"Gern Win",20}};
	int sz=sizeof(stu)/sizeof(stu[0]);
	bubble_sort(stu, sz, sizeof(stu[0]), cmp_stu_age);
	
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%s %d\n",stu[i].name,stu[i].age);
	}
	putchar('\n');
}


int main()
{
	
	//struct stu s[3]={{"wind",19},{"Turing",27},{"Win Germ",19}};
	//bubble_sort(arr,sz);
	
	//test1();
	//test2();
	//test3();
	//test4();
	return 0;
}

/*
qsort:�ܽ�
// ��һ���������������������Ԫ�ص�ַ
// �ڶ��������������������Ԫ�ظ���
// �����������������������ÿ��Ԫ�صĴ�С--��λ���ֽڣ�
// ���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ--�������ʹ�����Լ�ʵ��
//				����ָ������������ǣ����Ƚϵ���������Ԫ�صĵ�ַ
// 
void qsort (void* base, 
			size_t num, 
			size_t size,
            int (*compar)(const void*,const void*)
			);
*/

/* 
int main()
{
	int a=0;
//	printf("%d %d\n",sizeof(char*),sizeof(int*)); //��ַ���ɻ��������ģ�
	//                                             �������޹أ�����char*���Էŵ���int* 
//	int* pa=&a; //
//	char* pc=&a;// ��Ȼchar* �ŵ���int* ���ǻ��о��棬��Ϊ�Ͼ�ָ�����Ͳ�ͬ 
//	char ch='w';
	void* p=&a;
	*p=0; // void*���͵�ָ�룬���ܽ��н����ò��� 
	 p++��// void*���͵�ָ�룬���ܽ��мӼ������Ĳ��� --���� 
//		  p=&ch; 
	//void*���͵�ָ��  ���Խ����������͵ĵ�ַ �����൱��һ��"����Ͱ" ��"����Ͱ" 
	
	return 0;
}
*/


