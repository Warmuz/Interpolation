#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return (5/(pow(x,2)+2));
    //3*pow(x,7)-2*pow(x,6)+4*pow(x,4)-pow(x,3)+2*pow(x,2)-10*x+120
    //fabs(x)
    
}

double lagrange(int n, double a, double b, double x0){
    
    double* x;
    double* y;
    double* arr;
    double nominator;
    double denominator;
    double step=(b-a)/n;
    double value=0;
    double error=0;
    
  
    x = new double [n+1];
    y = new double [n+1];
    arr = new double [n];
    
    cout<<"Equally spaced nodes"<<endl;
    for(int i=0;i<n+1;i++){
        if(i==0){
            x[i] = a;
        }
        else{
            a=a+step;
            x[i]=a;
        }
        cout<<x[i]<<endl;
    }
    cout<<"Function value "<<endl;
    for (int i=0;i<n+1;i++){            //calculating function value from analytic function f
        y[i]=f(x[i]);
        cout<<y[i]<<endl;
    }
    
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
        value += arr[i];
    }
    
    for(int i=0;i<=n;i++){                  //finding the largest argument
        if(x[0]<x[i])
            x[0]=x[i];
    }
    cout<<"xmax: "<<x[0]<<endl;
    cout<<"f(xmax): "<<f(x[0])<<endl;

    error=fabs(f(x[0])-value);
    
    
   
    delete []y;
    delete []x;
    
    cout<<"Lagrange:"<<value<<endl;
    cout<<"Error of Lagrange: "<<error<<endl;
    cout<<endl;
    cout<<"-------------------------"<<endl;
    return value;
    
    
}

double chebyshev(int n, double a, double b, double x0){
    double* x;
    double* y;
    double* arr;
    double nominator;
    double denominator;
    double value=0;
    double error=0;
    
    x = new double [n+1];
    y = new double [n+1];
    arr = new double [n];
    
    cout<<"Chebyshev nodes"<<endl;
    for(int i=0;i<n+1;i++){
        x[i]=cos(((double)(2*i+1)/(double)(2*n+2))*M_PI);
        x[i]=0.5*((b-a)*x[i]+a+b);
        cout<<x[i]<<endl;
    }
    cout<<"Function value"<<endl;
    for(int i=0;i<n+1;i++){
        y[i]=f(x[i]);
        cout<<y[i]<<endl;
    }
    
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
        value += arr[i];
    }
    
    for(int i=0;i<=n;i++){                  //finding the largest argument
        if(x[0]<x[i])
            x[0]=x[i];
    }
    cout<<"xmax: "<<x[0]<<endl;
    cout<<"f(xmax): "<<f(x[0])<<endl;
    error=fabs(f(x[0])-value);
    
    delete []y;
    delete []x;
    
    cout<<"Chebyshev: "<<value<<endl;
    cout<<"Error of Chebyshev: "<<error<<endl;
    return value;
}

int main() {
    int n=7;
    double a=10,b=-10,x0=0.1;
    lagrange(n,a,b,x0);
    chebyshev(n,a,b,x0);
}
