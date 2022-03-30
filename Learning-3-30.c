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
	//指针数组
	int* arr[7];
	//指向指针数组的指针 
	int* (*pa)[7]; 
	//函数指针
	int (*padd)(int,int)=add; //=&add --函数声明  
	int sum=(*padd)(1,2);  
	//int sum=(padd)(1,2); // 函数调用、函数地址加*与不加*都一样 
	printf("%d\n",sum); //函数调用 
	//函数指针的数组 
	 int (*parr[7])(int,int);
	 //指向函数指针数组的指针
	 int (*(*pparr)[7](int,int))=&parr;
	 //回调函数--通过函数指针调用的函数，这个被调用的函数就叫做回调函数
	 // qsort 函数的原理 
	  
	
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
	//比较两个整型值的大小 
	return *(int*)e1 - *(int*)e2 ;  


}
void test1()
{
	int arr[10]={9,8,7,6,5,4,3,2,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
		qsort(arr, sz, sizeof(arr[0]), cmp_int);//qsort第一个参数为数组首元素地址 
	
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	putchar('\n');

}


int cmp_f(const void* e1,const void* e2)
{
	//比较两个浮点型值的大小
/*	if( *(float*)e1==*(float*)e2)
		return 0;
	if( *(float*)e1>*(float*)e2)
		return 1;
	if( *(float*)e1<*(float*)e2)
		return -1;
*/
	return ( (int) ( *(float*)e1 - *(float*)e2 ) ) ; //float可以把结果再转为整型返回 ，这样就符合标准了
}
void test2()
{
	 float f[]={2.2,1.7,9.7,7.2,3.7,5.7,5.2};
	 int sz=sizeof(f)/sizeof(f[0]);
	 qsort(f, sz, sizeof(f[0]), cmp_f); //qsort第一个参数为数组首元素地址 
	
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
	//这里比较的是年龄，name为字符串类型，不能用> = < 比较  要用strcmp
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
//实现bubble_sort函数的程序员，他是否知道未来排序数据类型——不知道
//那程序员也不知道，待比较的两个元素的类型 
void bubble_sort(void* base, int sz ,int width, int (*cmp)( void* p1, void* p2) )
{
	int i=0;
	//趟数
	for(i=0; i<sz-1; i++)
	  {
	  	 int j=0;
	  	 //每一趟从对数
		 for(j=0; j<sz-1-i; j++) 
		   {
		   	 //两元素的比较
			 if(cmp( (char*)base +j*width , (char*)base + (j+1)*width) > 0) //精华 
			   {
			   	 //交换
					swap( (char*)base +j*width , (char*)base + (j+1)*width ,width );	 
			   } 
		   } 
	  } 
}
void test4()
{
//	int arr[10]={9,8,7,6,5,4,3,2,1,0};	
//	int sz=sizeof(arr)/sizeof(arr[0]);
	//假定使用bubble——sort程序员一定知道自己排序的是什么数据
	//就应该知道如何比较排序数组中的元素 
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
qsort:总结
// 第一个参数：待排序数组的首元素地址
// 第二个参数：待排序数组的元素个数
// 第三个参数：待排序数组的每个元素的大小--单位（字节）
// 第四个参数：是函数指针，比较两个元素的所用函数的地址--这个函数使用者自己实现
//				函数指针的两个参数是：待比较的两个两个元素的地址
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
//	printf("%d %d\n",sizeof(char*),sizeof(int*)); //地址是由机器决定的，
	//                                             与类型无关，所以char*可以放得下int* 
//	int* pa=&a; //
//	char* pc=&a;// 虽然char* 放得下int* 但是会有警告，因为毕竟指针类型不同 
//	char ch='w';
	void* p=&a;
	*p=0; // void*类型的指针，不能进行解引用操作 
	 p++；// void*类型的指针，不能进行加减整数的操作 --报错 
//		  p=&ch; 
	//void*类型的指针  可以接收任意类型的地址 ——相当于一个"垃圾桶" 、"万能桶" 
	
	return 0;
}
*/


