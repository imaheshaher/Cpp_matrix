#include "iostream"
using namespace std;

void accept(int a[10][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    cin>>a[i][j];
  }
  
}

void display(int a[10][10],int r,int c)
{
  int i,j;
  
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    cout<<" "<< a[i][j]<<" ";
    cout<<endl;
  }
  
}

void addition(int a[10][10],int b[10][10],int r,int c)
{
  int i,j;
  int add[10][10];
  for(i=0;i<r;i++)
  {
    for (j=0;j<c;j++)
    {
      add[i][j]=a[i][j]+b[i][j];
    }
  }
  display(add,r,c);
    
}

void substraction(int a[10][10],int b[10][10],int r,int c)
{
  int i,j;
  int sub[10][10];
  for(i=0;i<r;i++)
  {
    for (j=0;j<c;j++)
    {
      sub[i][j]=a[i][j]-b[i][j];
    }
  }
  display(sub,r,c);
    
}

void multiplication(int a[10][10],int b[10][10],int r,int c)
{
 int i=0,j=0;
 int mul[10][10];
 for(i=0;i<r;i++)
 {
 	
   for(j=0;j<c;j++)
   {
 	mul[i][j]=0;
     for (int k=0;k<r && k<c;k++)
     {
       mul[i][j]+=a[i][k]*b[k][j];
     //cout<<"mul["<<i<<"]["<<j<<"] = "<<mul[i][j]<<endl; 
     }
     
     }
   }
 

display(mul,r,c);
}

void transpose(int a[10][10],int r,int c)
{
  int i,j;
  int trans[10][10];
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      trans[i][j]=a[j][i];
    }
  }
  display(trans,r,c);
}
void saddlepoint(int a[10][10],int r,int c)
{
//	cout<<"this is saddle point\n";
  int i,j,k;
  int cl;
  int max,min;
  for(i=0;i<r;i++)
  {
  	min=a[i][0];
  for(j=0;j<c;j++)
  {	
  	if(a[i][j]<min)
  	{	cl=j;
			
  		min=a[i][j];

  	}
  	else
  	{
  		cl=j-1;
  	}
  }
 // cout<<"min "<<min<<"and column -->"<<cl<<endl;
 max=min;
 for (j=0;j<c;j++)
 {
 	if(a[cl][j]>max)
 	{
 	max=a[cl][j];
 	}
 	
 }
 
 //cout<<"min element is "<<min<<endl;
 //cout<<"max element is "<<max<<endl;
if (max==min)
cout<<"found at position ["<<cl<<j<<"]="<<max<<endl;
}
}
int main()
{
  int r,c,ch;
  int a[10][10];
  int b[10][10];
 cout<<"Here the Operation on Matrix" <<endl;
 cout<<"Main Menu"<<endl;
 
 do {
   cout<<"\t1.Accept Matrix 1\n\t2.Accept Matrix 2\n\t3.Addition of Matrix\n\t4.Substraction\n\t5.Multiplication\n\t6.Transpose\n\t7.Saddle Point"<<endl;
   cout<<"Your choice ::";
   cin>>ch;
   switch(ch)
   {
     case 1: cout<<"Enter the Number of rows::";
     cin>>r;
      cout<<"Enter the Number of column::";
     cin>>c;
     cout<<"\n Enter the "<< r*c<<" element "<<endl;
     accept(a,r,c);
     cout<<"Matrix 1 ::"<<endl;
     display(a,r,c);
     break;
     
     case 2: 

     cout<<"Enter the Number of rows::";
     cin>>r;
      cout<<"Enter the Number of column::";
     cin>>c;
     cout<<"\n Enter the "<< r*c<<" element "<<endl;
     accept(b,r,c);
     cout<<"Matrix 2 ::"<<endl;
     display(b,r,c);
     break;
     case 3:
     	
      cout<<"Addition of Matrix 1 and Matrix 2 which both having same dimension "<<r<<"X"<<c<<endl;
      addition(a,b,r,c);
      break;
      case 4:
        cout<<"Substraction of Matrix 1 - Matrix 2 which both having same dimension "<<r<<"X"<<c<<endl;
        substraction(a,b,r,c);
        cout<<"Substraction of Matrix 2 - Matrix 1 which both having same dimension "<<r<<"X"<<c<<endl;
        substraction(b,a,r,c);
        
      
      break;
      
      case 5:
      cout<<"multiplication of Matrix 1 X Matrix 2 which both having same dimension "<<r<<"X"<<c<<endl;
      multiplication(a,b,r,c);
      cout<<"multiplication of Matrix 2 X Matrix 1 which both having same dimension "<<r<<"X"<<c<<endl;
      multiplication(b,a,r,c);
      break;
      case 6:
        cout<<"Transope matrix\n";
        transpose(a,r,c);
        break;
      case 7:
        cout<<"saddle point ::"<<endl;
        saddlepoint(a,r,c);
        break;
     case 0:
     	break;
     default:
     	cout<<"Your enterd the wrong choice";
   }
   
 }while(ch!=0);


}