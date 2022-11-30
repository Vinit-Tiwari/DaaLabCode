#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
void bruteForce(float a[],int n){
    // n is size 
    float min = a[0];
    float max = a[0];
    for(int i=0;i<n;i++){
        if(a[i]<=min){
            min = a[i];
        }
        if(a[i]>=max){
            max = a[i];
        }
    }
    cout<<"-------------------------------"<<endl;
    cout<<"MAX value is : "<<max<<endl;
    cout<<"MIN value is : "<<min<<endl;
    cout<<"-------------------------------"<<endl;
}
void Divide_N_Conquer(int x,int y,float a[], float *min , float *max){
    if(x==y){
        *min = a[x];
        *max = a[y];
    }else if(x==y-1){
        if(a[x]<a[y]){
           *min = a[x];
           *max = a[y];
        }else{
            *min=a[y];
            *max=a[x];
        }
    }
    else{
        float min1,min2,max1,max2;
        int mid=(x+y)/2;
        Divide_N_Conquer(x,mid,a,&min1,&max1);
        Divide_N_Conquer(mid+1,y,a,&min2,&max2);
        if(min1<min2){
            *min=min1;
        }
        else{
            *min=min2;
        }
        if(max1<max2){
            *max=max2;
        }
        else{
            *max=max1;
        }
    }
}
int main(){

    ifstream fin("Stock_data.csv",ios::in);

    float open[30],high[30],low[30],close[30];
    string date,volume;

    string mystring;
    string line;

    int i=0;
    cout<<"\n                           Table \n";
    cout<<"Date"<<"\t\t"<<"Open"<<"\t"<<"High"<<"\t"<<"Low"<<"\t"<<"Close"<<"\t"<<" Volume"<<endl;

    while( getline(fin,line)){
        stringstream ss(line);
        getline(ss,date,',');
        getline(ss,mystring,',');
        open[i]=stof(mystring);
        getline(ss,mystring,',');
        high[i]=stof(mystring);
        getline(ss,mystring,',');
        low[i]=stof(mystring);
        getline(ss,mystring,',');
        close[i]=stof(mystring);
        getline(ss,volume,'\n');

        cout<<date<<"\t"<<open[i]<<"\t"<<high[i]<<"\t"<<low[i]<<"\t"<<close[i]<<"\t"<<volume<<endl;
        i++;
    }
    cout<<"-------------------------------------------------------------------------"<<endl;
    // array size will be i;
    int size = i; // array size;
    int initial = 0; // initial index of array
    int last = i-1; // last index of array
    int column;  // 
    float min,max; // variable for divide N conquer
    int type; // 1.for Brute & 2. for DAC
    while(1){
        cout<<"\n1.BRUTE FORCE ALGORTIHM "<<endl;
        cout<<"2.DIVIDE AND CONQUER "<<endl;
        cout<<"3.EXIT ";
        cout<<"\nWhich Algorithm you have to perform : ";
        cin>>type;

        switch(type){
            case 1:
                cout<<"\n----You have selected Brute Force Algorithm----"<<endl;
                while(1){
                    cout<<"Enter on which column you have to find MIN and MAX : ";
                    cin>>column;
                    switch(column){
                        case 1:
                            cout<<"Find Min and Max for OPEN"<<endl;
                            bruteForce(open,size);
                            break;
                        case 2:
                            cout<<"Find Min and Max for HIGH"<<endl;
                            bruteForce(high,size);
                            break;
                        case 3:
                            cout<<"Find Min and Max for LOW"<<endl;
                            bruteForce(low,size);
                            break;
                        case 4:
                            cout<<"Find Min and Max for CLOSE"<<endl;
                            bruteForce(close,size);
                            break;
                        case 5:
                            break;
                    }
                    if(column == 5)
                        break;
                }
                break;

            case 2:
                cout<<"\n----You have selected Divide N Conquer Algorithm----"<<endl;
                while(1){
                    cout<<"Enter on which column you have to find MIN and MAX : ";
                    cin>>column;
                    switch(column){
                        case 1:
                            cout<<"Find Min and Max for OPEN"<<endl;
                            Divide_N_Conquer(initial,last,open,&min,&max);
                            cout<<"-------------------------------"<<endl;
                            cout<<"MAX value is : "<<max<<endl;
                            cout<<"MIN value is : "<<min<<endl;
                            cout<<"-------------------------------"<<endl;
                            break;
                        case 2:
                            cout<<"Find Min and Max for HIGH"<<endl;
                            Divide_N_Conquer(initial,last,high,&min,&max);
                            cout<<"-------------------------------"<<endl;
                            cout<<"MAX value is : "<<max<<endl;
                            cout<<"MIN value is : "<<min<<endl;
                            cout<<"-------------------------------"<<endl;
                            break;
                        case 3:
                            cout<<"Find Min and Max for LOW"<<endl;
                            Divide_N_Conquer(initial,last,low,&min,&max);
                            cout<<"-------------------------------"<<endl;
                            cout<<"MAX value is : "<<max<<endl;
                            cout<<"MIN value is : "<<min<<endl;
                            cout<<"-------------------------------"<<endl;
                            break;
                        case 4:
                            cout<<"Find Min and Max for CLOSE"<<endl;
                            Divide_N_Conquer(initial,last,close,&min,&max);
                            cout<<"-------------------------------"<<endl;
                            cout<<"MAX value is : "<<max<<endl;
                            cout<<"MIN value is : "<<min<<endl;
                            cout<<"-------------------------------"<<endl;
                            break;
                        case 5:
                            break;
                    }
                    if(column == 5){
                        break;
                    }
                }
                break;

            case 3: 
                exit(0);
                cout<<"Program ended successfully"<<endl;
        }
    }
}