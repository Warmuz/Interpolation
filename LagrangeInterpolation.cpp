
#include <iostream>

using namespace std;
double f(double x)
{
    return x*x*x*x;
}

const int n=5;                          //size of a array

int main() {
    //double x[n]={-1, 2, 0, 4};            //arguments
    double x[100];
    //double y[n]={-2, 0, -1, 5};         //function value
    double y[100];
    double arr[n]={1};
    double a=-10, b=10;
    double val=0;
    double x0=2;                        //argument in which we will be calculated a function value
    double step = (b - a)/n;
    
    double denominator;
    double nominator;
    
    for (int i=0;i<n+1;i++)
    {
        if(i==0)
        {
            x[i] = a;
        }
        else
        {
            a = a + step;
            x[i]= a;
        }
        cout << x[i] << endl;
    }
    cout << endl;
    for(int i=0;i<n+1;i++){
        y[i] = f(x[i]);
        cout << y[i] << endl;
    }
    cout << endl;
    
    
    
    for(int i=0;i<=n;i++){
        
      
        nominator=1;
        denominator=1;
        
        for(int j=0;j<=n;j++){
            
            if(i!=j){
                nominator *= (x0-x[j]);
                denominator *= (x[i]-x[j]);
            }
        }
        
        arr[i]=(nominator/denominator)*y[i];
        //cout<<arr[i]<<endl;
        val = val +arr[i];
    }
    cout<<val<<endl;
    cout << f(x0) ;
    return 0;
}

