#include<stdio.h>
void main()
{
    int i,j;
    int n;
    int ar[100];
    int ar2[100];
    int temp;
    int count=0;
    FILE* fp1,*fp2,*fp3,*fp4;
     fp1=fopen("cvb.txt","r");
     fp2=fopen("abc.txt","w");

     fscanf(fp1,"%d",&ar[0]);
     n=ar[0];
     printf("the first number in an array is\n");
     printf("%d\n",n);
     int p=n;




     for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d\n",&ar[i]);



    }


    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%d\n",&ar[i]);
        count++;
        printf("The array elemnts are\n");
        printf("%d\n",ar[i]);
        fprintf(fp2,"%d\n",ar[i]);

    }






    for(i=p-1;i>=0;i--)
    {
        fscanf(fp2,"%d\n",&ar[i]);

        fprintf(fp2,"%d\n",ar[i]);
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(ar[j]>ar[j+1])
           {
              temp=ar[j];
               ar[j]=ar[j+1];
               ar[j+1]=temp;
           }
        }
    }




    for(i=0;i<n;i++)
    {
         fprintf(fp2,"%d\n",ar[i]);
    }



    fclose(fp1);
    fclose(fp2);



}



random numbers generation code


#include<stdio.h>

void main()
{
    int i,j;
    int n;

    int temp=0;
    FILE* fp3,*fp4;
     fp3=fopen("adi.txt","w");
     fp4=fopen("hello.txt","w");
     time_t t;
     srand((unsigned) time(&t));
     n=6;
    int p=n;
     int ar2[n];




    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%10;
        fprintf(fp3,"%d\n",ar2[i]);

    }


     for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(ar2[j]>ar2[j+1])
           {
              temp=ar2[j];
               ar2[j]=ar2[j+1];
               ar2[j+1]=temp;
           }
        }
    }





    for(i=0;i<p;i++)
    {
         fprintf(fp4,"%d\n",ar2[i]);
    }

    fclose(fp3);
    fclose(fp4);
}
