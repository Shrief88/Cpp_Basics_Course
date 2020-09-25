#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void string_To_float(string s,string arrs[100][100],float Matrix[100][100],int& rows,int& col){
    if(s[0]=='['){
        for(int n=1 ;s[n]!=' '&&s[n]!=']';n++)    
            arrs[rows][col]+=s[n];
    
        for(int i=1;i<s.length();i++){

            if (s[i]==' '){
                col++;
                for (int j =++i ; s[j]!=' '&&s[j]!=']'&&s[j]!=';';j++)
                    arrs[rows][col]+=s[j];
            }

            if (s[i]==';'){
                rows++;
                col =0;
                for (int k =++i ; s[k]!=' '&&s[k]!=']';k++)
                        arrs[rows][col]+=s[k];
            }
        }
    }

    float v ;
    for (int i=0;i<=rows;i++)
        for (int j=0;j<=col;j++){
           v=atof(arrs[i][j].c_str());
           Matrix[i][j]=v;
        }

}

void add(float Matrix1[100][100],float Matrix2[100][100],float Matrix3[100][100],int rows,int col){
   for (int i =0;i<=rows;i++){
       for (int j=0;j<=col;j++)
           Matrix3[i][j]=Matrix1[i][j]+Matrix2[i][j];
   }
}

void substract(float Matrix1[100][100],float Matrix2[100][100],float Matrix3[100][100],int rows,int col){
    for (int i =0;i<=rows;i++){
       for (int j=0;j<=col;j++)
           Matrix3[i][j]=Matrix1[i][j]-Matrix2[i][j];   
    }
}

void multiply(float Matrix1[100][100],float Matrix2[100][100],float Matrix3[100][100],int rows1,int col2,int rows2){
    for(int i=0;i<=rows1;i++){
        for(int j=0;j<=col2;j++)
            for (int k=0;k<=rows2;k++)
                Matrix3[i][j] += Matrix1[i][k] * Matrix2[k][j];
    }
}

void coutform(float Matrix3[100][100],int rows ,int col){
  cout << "[";
  for (int i=0;i<=rows;i++){
    for (int j=0;j<=col;j++){
       cout <<Matrix3[i][j];
       if(j==col)
         break;
       cout << " ";
    }
     if(i==rows)
        break;
     cout << ";";
   }
     cout << "]";
}

void Power(float Matrix1[100][100],float Matrix2 [100][100],float Matrix3[100][100],int rows1,int rows2,int rows3 ,int pow){
    for (int i=0;i<=rows1;i++){
        for (int j=0;j<=rows1;j++)
            Matrix2[i][j]=Matrix1[i][j];
    }
    for(int m=1;m<pow;m++){
       multiply(Matrix1,Matrix2,Matrix3,rows1,rows1,rows1);
       for (int i=0;i<=rows1;i++){
           for (int j=0;j<=rows1;j++){
            Matrix1[i][j]=Matrix3[i][j];
            Matrix3[i][j]=0;
           }
        }
    }
}

void Transpose(float Matrix1[100][100],float Matrix3[100][100],int rows,int col)
{
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=col;j++)
        {
            Matrix3[j][i]= Matrix1[i][j];
        }
    }
}
void Determinant (float Matrix1[100][100],int rows,int col){
   float sum =1,counter =0;
   if(Matrix1[0][0]==0){
       for (int i=1;i<=rows;i++){
           if (Matrix1[i][0]!=0){
               for (int j=0;j<=col;j++)
                   swap(Matrix1[0][j],Matrix1[i][j]);
           }       
           else counter ++;
       }
   }
   for (int j=0;j<col;j++){
       for (int c=j+1 ;c<=rows ;c++){
         for (int k=col;k>=0;k--)
           Matrix1[c][k]=Matrix1[c][k]-((Matrix1[c][j]/Matrix1[j][j])*Matrix1[j][k]);
       }
    }
    if (counter == rows){
            sum=0;
            cout << sum;
    }
    else{
       for(int i=0;i<=rows;i++){
         for(int j=0;j<=col;j++){
         if (i==j)
            sum*=Matrix1[i][j];
         }
       }
          cout << sum;
    }
}

void Inverse(float Matrix1[100][100],float Matrix2[100][100],int rows,int col){
    if(Matrix1[0][0]==0){
       for (int i=1;i<=rows;i++){
           if (Matrix1[i][0]!=0){
               for (int j=0;j<=col;j++)
                   swap(Matrix1[0][j],Matrix1[i][j]);
           }
       }
    }
    for (int i=0;i<=rows;i++){
        for (int j=0;j<=col;j++){
            if (i==j)
                Matrix2[i][j]=1;
        }
    }
    int i =0;
    for (int j=0;j<col;j++){
       for(int m=col;m>=0;m--)
           Matrix2[i][m]=Matrix2[i][m]/Matrix1[i][i];
        for(int m=col;m>=0;m--)
            Matrix1[i][m]=Matrix1[i][m]/Matrix1[i][i];
       for (int c=j+1 ;c<=rows ;c++){
         for (int k=col;k>=0;k--)
           Matrix2[c][k]=Matrix2[c][k]-((Matrix1[c][j]/Matrix1[j][j])*Matrix2[j][k]);
       }
       for (int c=j+1 ;c<=rows ;c++){
         for (int k=col;k>=0;k--)
           Matrix1[c][k]=Matrix1[c][k]-((Matrix1[c][j]/Matrix1[j][j])*Matrix1[j][k]);
       }
       i++;
    }
    int b=rows;
    for (int j=col;j>0;j--)
    {
       for(int m=0;m<=col;m++)
           Matrix2[b][m]=Matrix2[b][m]/Matrix1[b][b];
       
       for(int m=0;m<=col;m++)
           Matrix1[i][m]=Matrix1[i][m]/Matrix1[i][i];

       for (int c=j-1;c>=0 ;c--){
         for (int k=col;k>=0;k--)
            Matrix2[c][k]=Matrix2[c][k]-((Matrix1[c][j]/Matrix1[j][j])*Matrix2[j][k]);
       }

       for (int c=j-1;c>=0 ;c--){
         for (int k=col;k>=0;k--)
            Matrix1[c][k]=Matrix1[c][k]-((Matrix1[c][j]/Matrix1[j][j])*Matrix1[j][k]);
       }
       b--;
    }
}

void Devide(float Matrix1[100][100],float Matrix2[100][100],float Matrix3[100][100],float Matrix4[100][100],int rows1,int col1,int rows2,int col2)
{
    Inverse(Matrix2,Matrix3,rows2,col2);
    multiply(Matrix1,Matrix3,Matrix4,rows1,col2,rows2);
}

int main()
{
    string s1,s2,x;
    string arrs1[100][100],arrs2[100][100];
    float Matrix1[100][100],Matrix2[100][100],Matrix3[100][100],Matrix4[100][100];
    int rows1=0,col1=0,rows2=0,col2=0;
    getline(cin,s1);
    getline (cin,x);

    string_To_float(s1,arrs1,Matrix1,rows1,col1);

    if (x[0]=='+'||x[0]=='-'||x[0]=='*'||x[0]=='/'){
        getline(cin,s2);
        string_To_float(s2,arrs2,Matrix2,rows2,col2);
    }

    if (x[0] =='+'){
        if(rows1!=rows2||col1!=col2)
            cout<<"Error";
        else{
             add(Matrix1,Matrix2,Matrix3,rows1,col1);
             coutform(Matrix3,rows1,col1);
        }
    }

    else if (x[0]=='-'){
        if(rows1!=rows2||col1!=col2)
           cout<<"Error";
        else{
             substract(Matrix1,Matrix2,Matrix3,rows1,col1);
             coutform(Matrix3,rows1,col1);
        }

    }

    else if (x[0]=='*'){
        if(col1==rows2){
           multiply(Matrix1,Matrix2,Matrix3,rows1,col2,rows2);
           coutform(Matrix3,rows1,col2);
        }
        else
            cout << "Error";
    }

    else if (x[0]=='T'){
            Transpose(Matrix1,Matrix3,rows1,col1);
            coutform(Matrix3,col1,rows1);
        }
    }

    else if (x[0]=='^'){
        int pow;
        cin >> pow;
        if (rows1!=col1)
            cout << "Error";
        else if (pow==1)
           coutform(Matrix1,rows1,col1);
        else{
            Power(Matrix1,Matrix2,Matrix3,rows1,rows1,rows1,pow);
            coutform(Matrix1,rows1,col1);
        }
    }

    else if (x[0]=='D'){
        if (rows1!=col1)
            cout << "Error";
        else
            Determinant(Matrix1,rows1,col1);
    }
    else if (x[0]=='I'){
        if (rows1!=col1)
            cout <<"Error";
        else{
             Inverse(Matrix1,Matrix2,rows1,col1);
             coutform(Matrix2,rows1,col1);
        }
    }
    else if(x[0]=='/'){
        if (col1!=rows2)
            cout << "Error";
        else    {
            Devide(Matrix1,Matrix2,Matrix3,Matrix4,rows1,col1,rows2,col2);
            coutform(Matrix4,rows1,col2);
        }
    }
}



