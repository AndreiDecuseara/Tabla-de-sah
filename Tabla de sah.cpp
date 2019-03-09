#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream f("date1.in");




int main()
{
   int n,x;
   f>>n;
   vector< vector<int> > v;
   vector< int > aux1;

   int aux[n][n];

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           aux[i][j]=0;
       }
   }


   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           f>>x;
           aux1.push_back(x);

           aux[i][j]=x;

       }
       v.push_back(aux1);
       aux1.erase(aux1.begin(),aux1.end());
   }

    int maxim=0;
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<n;j++)
            {
                if(j!=n-1 && j!=0)
                {
                   if(v[i+1][j+1]==1 || v[i+1][j-1]==1)
                    {
                        if (aux[i+1][j+1] > aux[i+1][j-1])aux[i][j]+=aux[i+1][j+1];
                        else aux[i][j]+=aux[i+1][j-1];


                    }
                    else if(v[i+1][j]==1)aux[i][j]=-1;
                    else if(v[i+1][j]==0)aux[i][j]+=aux[i+1][j];
                }
                else if(j==0)
                {
                    if(v[i+1][j+1]==1 )
                    {
                       aux[i][j]+=aux[i+1][j+1];
                    }
                    else if(v[i+1][j]==1)aux[i][j]=-1;
                    else if(v[i+1][j]==0)aux[i][j]+=aux[i+1][j];
                }
                else if(j==n-1)
                {
                    if(v[i+1][j-1]==1)
                    {
                        aux[i][j]+=aux[i+1][j-1];
                    }
                    else if(v[i+1][j]==1)aux[i][j]=-1;
                    else if(v[i+1][j]==0)aux[i][j]+=aux[i+1][j];
                }
                if(aux[i][j]>maxim) maxim=aux[i][j];
           }


    for(int j=0;j<n;j++)
    {
        int i=0;
        if(maxim==aux[0][j])
        {
            cout<<"(0,"<<j<<") ";
            while(i!=n-1)
            {
                if(aux[i+1][j-1]>aux[i+1][j])
                {
                    if(aux[i+1][j-1]>aux[i+1][j+1]) {cout<<"("<<i+1<<","<<j-1<<") ";j=j-1;}
                    else { cout<<"("<<i+1<<","<<j+1<<") ";j=j+1; }
                }
                else
                {
                    if(aux[i+1][j]>aux[i+1][j+1])
                        cout<<"("<<i+1<<","<<j<<") ";
                    else {cout<<"("<<i+1<<","<<j+1<<") ";j=j+1;}
                }
                i++;

            }
        }
        cout<<endl;
    }

return 0;
}
