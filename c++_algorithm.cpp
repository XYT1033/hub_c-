




-- 六种简单算法  https://blog.csdn.net/weixin_36381867/article/details/52939518 


--经典算法  https://blog.csdn.net/duan_jin_hui/article/details/70055042 


 1.链表逆序

#include <iostream>  
using namespace std;  

struct node  
{  
	int value;  
	node * next;  
};  

node* make_link(void);  
node* reverse(node*);  
void display(node *);  

int main()  
{  
	node *head=make_link();  
	display(head);  
	head=reverse(head);  
	display(head);  

	getchar();
	return 0;  
}  

node* make_link(void)  
{  
	node *head=new node();  
	node *cur=head;  
	for(int i=0;i<10;i++)  
	{  
		cur->value=rand()%10;  
		cur->next=new node();  
		cur=cur->next;  
	}  

	return head;  
}  

node* reverse(node *head)  
{  
	node *pre,*post,*cur;  
	if(!head && !head->next)  
		return head;  
	pre=head;  
	cur=pre->next;  
	while(cur)  
	{  
		post=cur->next;  
		cur->next=pre;  
		pre=cur;  
		cur=post;  
	}  
	head->next=NULL;  
	return pre;  
}  

void display(node * head)  
{  
	node * cur=head;  
	while(cur)  
	{  
		cout<<cur->value<<" ";  
		cur=cur->next;  
	}  
	cout<<endl;  
}  


-- 插入排序 

//将一个记录插入到已经排好序的有序表中，从而得到一个新的 、记录数增1的有序表  
#include <iostream>  
using namespace std;  
  
void insertSort(int a[],int size)  
{  
    for(int i=1;i<size;i++)  
        for(int j=i;(j>0)&&(a[j]<a[j-1]);j--)  
        {  
            int temp=a[j];  
            a[j]=a[j-1];  
            a[j-1]=temp;  
        }  
}  
  
int main()  
{  
    int a[]={12,36,24,85,47,30,53,91};  
    for(int i=0;i<8;i++)  
        cout<<a[i]<<" ";  
    cout<<endl;  
  
    insertSort(a,8);  
    for(int i=0;i<8;i++)  
        cout<<a[i]<<" ";  
    cout<<endl;  
  
  	getchar();
    return 0;  
}  


-- 折半插入排序 
#include <iostream>
using namespace std;

void BInsertSort(int a[],int size)
{
	for(int i=1;i<size;i++)
	{
		int temp=a[i];               //暂存a[i]
		int low=0;
		int high=i-1;
		while(low<=high)
		{
			int middle=(low+high)/2;
			if(temp<=a[middle])
				high=middle-1;
			else
				low=middle+1;
		}

		for(int j=i-1;j>=high+1;--j)   //记录后移
			a[j+1]=a[j];
		a[high+1]=temp;                //插入，注意没有补齐的地方要注意，不然是野指针指向莫名的值。
	}
}

int main()
{
	int a[]={12,36,24,53,53,30,53,91};
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	BInsertSort(a,8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	getchar();
	return 0;
}




-- 01背包问题  https://blog.csdn.net/luoweifu/article/details/18509317 

问题描述：

有n个重量和价值分别为wi、vi的物品，现在要从这些物品中选出总重量不超过W的物品，求所有挑选方案中的价值最大值。

限制条件：

1<=N<=100

1<=wi 、vi<=100

1<=wi<=10000



#include <stdio.h>
#include <tchar.h>
#include <queue>
#include "iostream"
using namespace std;
const int N = 4;
const int W = 5;
int weight[N] = {2, 1, 3, 2};
int value[N] = {3, 2, 4, 2};
int solve(int i, int residue)
{
	int result = 0;
	if(i >= N)
		return result;
	if(weight[i] > residue)
		result = solve(i+1, residue);
	else
	{
		result = max(solve(i+1, residue), solve(i+1, residue-weight[i]) + value[i]);
	}
}
int main() {
	int result = solve(0, W);
	cout << result << endl;
	getchar();
	return 0;
}






 OFN_ALLOWMULTISELECT 






 