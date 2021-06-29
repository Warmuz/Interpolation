#include <iostream>
#include <math.h>


using namespace std;
double f(double x)
{
    return x*x*x*x;
}

const int n=10;  //size of a array

int main() {
    //double x[n]={-1, 2, 0, 4};            //arguments
    double x[100];
    //double y[n]={-2, 0, -1, 5};         //function value
    double y[100];
    double arr[n]={1};
    //double a=-10, b=10;
    double val=0;
    double x0=10;                        //argument in which we will be calculated a function value
    double dI =0;
    double dN;
    double denominator;
    double nominator;
    for (int i=0;i<n+1;i++)
    {
        dI = i;
        dN = n;
        x[i] =cos(((2*dI+1)/(2*dN))*M_PI);
        cout<<x[i]<<endl;
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
    cout << endl;
    cout<<val<<endl;
    cout << f(x0) ;
    return 0;
}

