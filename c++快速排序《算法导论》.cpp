//摘自CSDN  
#include <iostream>  
#include <vector>  
using namespace std;   
void swap(int &p,int &q)  
{  
    int t;  
    t = p;  
    p = q;  
    q = t;  
}  
//快速排序算法中的一趟划分函数  
int partition(vector<int> &data, int low, int high)  
{  
    //基准记录  
	int i    = low;
    int temp = data[low];  
    for(int j = low + 1; j <= high; ++j )
	{
		if(data[j] <= temp)  //查找关键字小于temp的记录，并依次放到data[low]的右侧
			swap(data[++i], data[j]); 
	}
	swap(data[low], data[i]);//将基准记录temp定位，使其左侧记录均不大于temp,右侧均大于temp  
    return i;  
}  
//快速排序  
void quickSort(vector<int> &data,int low,int high)  
{  
    int i;  
    if(low<high)//只有一个或无记录时不须排序  
    {  
        i=partition(data,low,high);//对data[low]到data[high]进行一次划分  
        quickSort(data,low,i-1);//递归处理左区间  
        quickSort(data,i+1,high);//递归处理右区间  
    }  
}  
int main()  
{  
    int n, m;  
    vector<int> input;  
    //输入数据  
    cout<<"请输入数组的长度: ";  
    cin>>n;  
    cout<<"请对数组赋值: ";  
    for(int i=0; i<n; ++i)  
    {  
        cin>>m;  
        input.push_back(m);  
    }  
    //处理数据  
    quickSort(input,0,n-1);  
    //输出结果  
    for(int i=0; i<n; ++i)  
        cout<<input[i]<<" ";  
    cout<<endl;  
    system("pause");  
    return 0;  
}  
