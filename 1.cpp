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
	i=scan(str1,str2,str3);    //ʵ���������룬�����������������i�� 
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
			//�Ѱ����������㵽��ת�ɺ��ֵĺ���
			num_to_str(num1[j]);
			if(num1[j]!=0)
			//����ʮ���١�ǧ�������� 
			transfer(j);
		}
	}
	getchar();
	return 0; 
}


//�������뺯��
int scan(string str1[],string str2[],string str3[])
{
	int i=0;
	while(1)
	{
		cin>>str1[i];
		if(str1[i]=="����")
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
 

//������ĺ�����ֵ����ת������������ 
int turn_to_num(string str2[],string str3[],string str14,int i)
{
	int character_to_num(string str);
	int operation(int sum,int num,string str2); 
	int sum,num;
	sum=character_to_num(str14);
	for(int j=0;j<=i;j++)
	{
		num=character_to_num(str3[j]);    //�Ѻ���ת�����ִ��num�� 
		sum=operation(sum,num,str2[j]);   //���мӼ����㣬�����ս�����sum�� 
	}
	return sum;
}


//���ú����㵽ʮ�밢�������ֵ�һһ��Ӧ��ϵ 
int character_to_num(string str)
{
	int a;
	if(str=="��")a=0;
	else if(str=="һ")a=1;
	else if(str=="��")a=2;
	else if(str=="��")a=3;
	else if(str=="��")a=4;
	else if(str=="��")a=5;
	else if(str=="��")a=6;
	else if(str=="��")a=7;
	else if(str=="��")a=8;
	else if(str=="��")a=9;
	else if(str=="ʮ")a=10;
	return a;	
}


//�ж��Ƿ����δ����ı���
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


//���庺������Ӧ�����㷨��
int operation(int sum,int num,string str2)
{
	if(str2=="����")
	sum=sum+num;
	else if(str2=="����")
	sum=sum-num;
	return sum; 
}


//�Ѱ���������0-9ת���ɺ������ 
void num_to_str(int num1)
{
	switch(num1)
	{
		case 0:cout<<"��";break;
		case 1:cout<<"һ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"��";break;
		case 4:cout<<"��";break;
		case 5:cout<<"��";break;
		case 6:cout<<"��";break;
		case 7:cout<<"��";break;
		case 8:cout<<"��";break;
		case 9:cout<<"��";break;
	}
}


//���ֵ�λ 
void transfer(int j)
{
	switch(j)
	{
		case 0:break;
		case 1:cout<<"ʮ";break;
		case 2:cout<<"��";break;
		case 3:cout<<"ǧ";break;
		case 4:cout<<"��";break;
		case 5:cout<<"ʮ��";break;	
	}
 } 
 

 
