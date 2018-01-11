//ժ��CSDN ----Chris's note 
#include <iostream>  
#include <vector>  
using namespace std;  
//��������Ԫ��ֵ  
void swap(int &p,int &q)  
{  
    int t;  
    t = p;  
    p = q;  
    q = t;  
}  
//���������㷨�е�һ�˻��ֺ���  
int partition(vector<int> &data, int low, int high)  
{  
    //��׼��¼  
	int i    = low;
    int temp = data[low];  
    for(int j = low + 1; j <= high; ++j )
	{
		if(data[j] <= temp)  //���ҹؼ���С��temp�ļ�¼�������ηŵ�data[low]���Ҳ�
			swap(data[++i], data[j]); 
	}
	swap(data[low], data[i]);//����׼��¼temp��λ��ʹ������¼��������temp,�Ҳ������temp  
    return i;  
}  
//��������  
void quickSort(vector<int> &data,int low,int high)  
{  
    int i;  
    if(low<high)//ֻ��һ�����޼�¼ʱ��������  
    {  
        i=partition(data,low,high);//��data[low]��data[high]����һ�λ���  
        quickSort(data,low,i-1);//�ݹ鴦��������  
        quickSort(data,i+1,high);//�ݹ鴦��������  
    }  
}  
int main()  
{  
    int n, m;  
    vector<int> input;  
    //��������  
    cout<<"����������ĳ���: ";  
    cin>>n;  
    cout<<"������鸳ֵ: ";  
    for(int i=0; i<n; ++i)  
    {  
        cin>>m;  
        input.push_back(m);  
    }  
    //��������  
    quickSort(input,0,n-1);  
    //������  
    for(int i=0; i<n; ++i)  
        cout<<input[i]<<" ";  
    cout<<endl;  
    system("pause");  
    return 0;  
}  
