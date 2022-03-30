#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
int main()
{	//数组名是首元素的地址
	//例外：
	//（1） sizeof（(单独放)数组名）——整个数组
	//（2） &数组名——数组名表示的是整个数组，数组又是首元素的地址 
	//
	//一位数组 
	int a[]={1,2,3,7};
	printf("%d\n",sizeof(a)); //16	
	//sizeof(数组名)--计算的是总数组的大小 
	printf("%d\n",sizeof(a+0)); //16（x） 4 or 8(check)		
	//因为它不是（1）or（2）中的例外，所以里面的a 表示的不是整个数组， 
	// 所以 a+0 表示的是首元素的地址 所以a+0 可能是4 or 8 
	printf("%d\n",sizeof(*a)); // 4 	
	//*a 首元素 
	printf("%d\n",sizeof(a+1)); //4 or 8  
	//因为它不是（1）or（2）中的例外，所以里面的 a 表示的不是整个数组，
	// 所以 a+1 表示的是第二个元素的地址 所以a+1 可能是4 or 8 
	printf("%d\n",sizeof(a[1])); //4
	printf("%d\n",sizeof(&a)); //4 or 8  
	//取数组的地址，二级指针 ，还是指针（地址） 
	printf("%d\n",sizeof(*&a)); //16 	
	//* 与 & 相当于抵消了 sizeof 计算的就是数组的大小 
	printf("%d\n",sizeof(&a+1)); //4 or 8 
	//&a是数组的地址 +1 跳过一个数组 但是仍然是地址 
	printf("%d\n",sizeof(&a[0]));//4 or 8  
	//第一个元素的地址 
	printf("%d\n",sizeof(&a[0]+1));//4 or 8 
	// 第二个元素的地址 
	
	return 0;
}
*/


/* 
int main()
{
	char carr[]={'a','b','c','d','e','f'};
	printf("%d\n",sizeof(carr)); // 6 
	// sizeof计算的是数组的大小 
	printf("%d\n",sizeof(carr+0));//4 or 8
	// 不是（1）or（2）中的例外，所以里面的a 表示的不是整个数组，是首元素地址 
	printf("%d\n",sizeof(*carr));//1
	printf("%d\n",sizeof(carr[1]));//1
	printf("%d\n",sizeof(&carr));//4 or 8
	// & carr 数组的地址，但还是地址嘛 
	printf("%d\n",sizeof(&carr+1));//4 or 8
	// &carr + 1 跳过一个数组的地址，还是地址 
	printf("%d\n",sizeof(&carr[0]+1));//4 or 8
	// &carr[0]+1 是第二个元素的地址 
	return 0;
}
*/

/* 
int main()
{
	char carr[]={'a','b','c','d','e','f'};
	printf("%d\n",strlen(carr)); // rand number
	// 注意strlen和sizeof的区别 strlen 遇到'\0'才停下 
	printf("%d\n",strlen(carr+0));// rand number
	printf("%d\n",strlen(*carr));// erorr
	// 把a=97 当作地址访问，会造成非法访问，报错 
	printf("%d\n",strlen(carr[1]));// eporr
	printf("%d\n",strlen(&carr));// rand number
	printf("%d\n",strlen(&carr+1));// rand number-6
	//&carr +1 后 跳过一个字符数组，所以比之前遇到斜杠零要少6个长度 
	printf("%d\n",strlen(&carr[0]+1));//rand number-1
	//&carr[0] +1 后 跳过一个字符，所以比之前遇到斜杠零要少1个长度 
	return 0;
}
*/


/* 
int main()
{
	char carr[]="abcdef"
	printf("%d\n",sizeof(carr)); // 7
	// sizeof（（单独）数组名）计算的是数组所占用空间的大小 
	printf("%d\n",sizeof(carr+0));//4 or 8
	// 不是（1）or（2）中的例外，所以里面的a 表示的不是整个数组，是首元素地址 
	printf("%d\n",sizeof(*carr));//1
	printf("%d\n",sizeof(carr[1]));//1
	printf("%d\n",sizeof(&carr));//4 or 8
	// & carr 数组的地址，但还是地址嘛 
	printf("%d\n",sizeof(&carr+1));//4 or 8
	// &carr + 1 跳过一个数组的地址，还是地址 
	printf("%d\n",sizeof(&carr[0]+1));//4 or 8
	// &carr[0]+1 是第二个元素的地址 
	return 0;
}
*/


/*
int main()
{
	char carr[]="abcdef";
	printf("%d\n",strlen(carr)); // 6
	// 注意strlen和sizeof的区别 strlen 遇到'\0'才停下 
	printf("%d\n",strlen(carr+0));// 6
	//是首元素地址，然后往后找，直到找到'\0' 
	//printf("%d\n",strlen(*carr));// erorr
	// 把a=97 当作地址访问，会造成非法访问，报错 
	//printf("%d\n",strlen(carr[1]));// eporr
	printf("%d\n",strlen(&carr));// 6
	// &arr--取数组的地址 ,数组的地址又是首元素的地址 
	printf("%d\n",strlen(&carr+1));// rand number
	//&carr +1 后 跳过一个字符数组后，它要重新找到'\0' 
	printf("%d\n",strlen(&carr[0]+1));//5
	//&carr[0] +1 后 跳过一个字符，所以比之前遇sizeof(carr)少1个长度 
	return 0;
}
*/


/*
int main()
{
	const char *p="abcdef";
	printf("%d\n",sizeof(p)); // 4 or 8
	// 注意strlen和sizeof的区别 sizeof 计算的是占用空间 
	printf("%d\n",sizeof(p+1));// 4 or 8
	//是第二个元素的地址，'b'的地址 
	printf("%d\n",sizeof(*p));// 1
	printf("%d\n",sizeof(p[0]));// 1
	// p[0]==*(p+0) 也就是'a' 
	printf("%d\n",sizeof(&p));// 4 or 8
	// &arr--取数组的地址 
	printf("%d\n",sizeof(&p+1));// 4 or 8
	//&carr +1 后 取跳过一个字符数组后的地址 
	printf("%d\n",sizeof(&p[0]+1));// 4 or 8
	//&carr[0] +1 后 跳过一个字符的地址
	return 0;
}
*/


/* 
int main()
{
	const char* p="abcdef";
	printf("%d\n",strlen(p)); // 6
	// 注意strlen和sizeof的区别 strlen 遇到'\0'才停下 
	printf("%d\n",strlen(p+1));// 5
	//是首元素地址，然后往后找，直到找到'\0' 
//	printf("%d\n",strlen(*p));// erorr
	// 把a=97 当作地址访问，会造成非法访问，报错 
//	printf("%d\n",strlen(p[0]));// eporr
	printf("%d\n",strlen(&p));// 6
	// &arr--取整个数组的地址 
	printf("%d\n",strlen(&p+1));// rand number
	//&carr +1 后 跳过一个字符数组后，它要重新找到'\0' 
	printf("%d\n",strlen(&p[0]+1));//5
	//&carr[0] +1 后 跳过一个字符，所以比之前遇sizeof(carr)少1个长度 
	return 0;
}
*/


int main()
{
	int a[3][4]={0};
	printf("%d\n",sizeof(a) );//48
	printf("%d\n",sizeof( a[0][0]) );//4
	printf("%d\n",sizeof( a[0]) );//16	 a[0]相当于第一行作为一维数组的数组名，sizeof(arr[0])把数组名单独放在 
	//sizeof()内，计算的是第一行的大小 
	printf("%d\n",sizeof( a[0]+1) );//4 or 8
	// sizeof(arr[0])把数组名不单独放在sizeof内，表示的是a[0]中的首元素地址再加一的地址，也就是a[0][1] 
	printf("%d\n",sizeof( *(a[0]+1) ) );//4 
	// a[0] + 1表示的是a[0]中的首元素地址再加一的地址,解引用就是元素a[0][1] 	
	printf("%d\n",sizeof(a+1) );//4 or 8
	// sizeof(a+1)把数组名不单独放在sizeof内，表示的是a中的首元素地址再加一的地址，也就是a[1]的地址 
	printf("%d\n",sizeof(*(a+1) ) );//16
	//表示的是a中的首元素地址再加一的地址再解引用，也就是a[1]的地址解引用，也就是a[1] 
	printf("%d\n",sizeof(&a[0]+1) );//4 or 8
	printf("%d\n",sizeof( *(&a[0]+1) ) );// 16
	printf("%d\n",sizeof(*a) );//16
	printf("%d\n",sizeof(a[3]) );//16
	return 0;
}




