#include <iostream>   
 using namespace std;   
    
 #define MAXNUM 100   
 #define MAX 65536   
 double p[MAXNUM] = {0.00,0.15,0.10,0.05,0.10,0.20};   
 double q[MAXNUM] = {0.05,0.10,0.05,0.05,0.05,0.10};   
 void optimal_bst(double e[][MAXNUM],int root[][MAXNUM],double w[][MAXNUM],int n)   
 {   
         int i =0,j=0;   
         for(i = 1;i<=n+1;i++)   
        {   
                 e[i][i-1] = q[i-1];   
                 w[i][i-1] = q[i-1];   
         }   
         int l = 0;    
         for(l = 1;l<=n;l++)   
         {   
                 for(i = 1;i<=n-l+1;i++)   
                 {   
                         j = i+l-1;   
                         e[i][j] = MAX;   
                         w[i][j] = w[i][j-1] + p[j]+q[j];   
                         for(int r = i;r<=j;r++)   
                         {   
                                 double t = 0;   
                                 t = e[i][r-1]+e[r+1][j] + w[i][j];   
                                 if(t<e[i][j])   
                                 {   
                                         e[i][j]= t;   
                                         root[i][j] = r;   
                                 }   
                         }   
    
                 }   
         }   
    
 }   
 int main()   
 {   
         double e[MAXNUM][MAXNUM];   
         int root[MAXNUM][MAXNUM];   
         double w[MAXNUM][MAXNUM];   
    
         optimal_bst(e,root,w,5);   
    
         for(int i =1;i<=6;i++)   
         {   
                 for(int j = 0;j<=5;j++)   
                 {   
                         cout << e[i][j] << "  ";   
                 }   
                 cout << endl;   
         }   
 }  