#include<iostream>
using namespace std;
FILE* fopen(const char* filename, const char* mode);
int main()
{
	int scan(string str1[],string str2[],string str3[]);
	int turn_to_num(string str2[],string str3[],string str14,int i);
	int check_variable(string str12,string str1[],int i);
	void transfer(int j);
	void num_to_str(int num1);
	FILE* fp;
	fp = fopen("1.txt", "r");
	string str1[1000],str2[1000],str3[1000],str11,str12,str13,str14;int i,j,sum,num1[100],n;
	if( (fp=fopen("filename","r+b")) == NULL )
{
printf("open file error!\n");
return 0;
}
	cin>>str11>>str12>>str13>>str14;
	i=scan(str1,str2,str3);    //实现数据输入，并把总数据行数存进i中 
	if(check_variable(str12,str1,i))
	{
		sum=turn_to_num(str2,str3,str14,i);
		for(i=0,j=0;sum>0;i++)
		{
			num1[i]=sum%10;
			sum=sum/10;
			
		}
		for(j=0;j<i;j++)
		{
			if(num1[j]!=0)
			break;
		}
		n=j;
		for(j=i-1;j>=n;j--)
		{
			//把阿拉伯数字零到九转成汉字的函数
			num_to_str(num1[j]);
			if(num1[j]!=0)
			//汉字十、百、千、万的输出 
			transfer(j);
		}
	}
	getchar();
	return 0; 
}


//定义输入函数
int scan(string str1[],string str2[],string str3[])
{
	int i=0;
	while(1)
	{
		cin>>str1[i];
		if(str1[i]=="看看")
		{
			cin>>str2[i];
			break;
		}
		else
		cin>>str2[i]>>str3[i];
		i++;
	}
	return(i);
}
 

//对输入的汉字数值进行转化并进行运算 
int turn_to_num(string str2[],string str3[],string str14,int i)
{
	int character_to_num(string str);
	int operation(int sum,int num,string str2); 
	int sum,num;
	sum=character_to_num(str14);
	for(int j=0;j<=i;j++)
	{
		num=character_to_num(str3[j]);    //把汉字转成数字存进num中 
		sum=operation(sum,num,str2[j]);   //进行加减运算，把最终结果存进sum中 
	}
	return sum;
}


//设置汉字零到十与阿拉伯数字的一一对应关系 
int character_to_num(string str)
{
	int a;
	if(str=="零")a=0;
	else if(str=="一")a=1;
	else if(str=="二")a=2;
	else if(str=="三")a=3;
	else if(str=="四")a=4;
	else if(str=="五")a=5;
	else if(str=="六")a=6;
	else if(str=="七")a=7;
	else if(str=="八")a=8;
	else if(str=="九")a=9;
	else if(str=="十")a=10;
	return a;	
}


//判断是否出现未定义的变量
int check_variable(string str12,string str1[],int i)
{
	int flag=1;
	for(int j=0;j<i;j++)
	{
		if(str1[j]!=str12)
		{
			flag=0;
			cout<<str1[j]<<" was not declared in this scope"<<endl;
		}
	}
	return flag;
}


//定义汉字所对应的运算法则
int operation(int sum,int num,string str2)
{
	if(str2=="增加")
	sum=sum+num;
	else if(str2=="减少")
	sum=sum-num;
	return sum; 
}


//把阿拉伯数字0-9转化成汉字输出 
void num_to_str(int num1)
{
	switch(num1)
	{
		case 0:cout<<"零";break;
		case 1:cout<<"一";break;
		case 2:cout<<"二";break;
		case 3:cout<<"三";break;
		case 4:cout<<"四";break;
		case 5:cout<<"五";break;
		case 6:cout<<"六";break;
		case 7:cout<<"七";break;
		case 8:cout<<"八";break;
		case 9:cout<<"九";break;
	}
}


//汉字单位 
void transfer(int j)
{
	switch(j)
	{
		case 0:break;
		case 1:cout<<"十";break;
		case 2:cout<<"百";break;
		case 3:cout<<"千";break;
		case 4:cout<<"万";break;
		case 5:cout<<"十万";break;	
	}
 } 
 

 
