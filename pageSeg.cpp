
#include<bits/stdc++.h>
using namespace std;
char memory[1025];
char seg[4][3][10];
int Pp (int x)
    {
        int p0,p1;
        if(((x>>10)& 1))p0=1;
        else p0=0;
        if(((x>>11)& 1))p1=2;
        else p1=0;
        return p0+p1;
    }
int ofset(int a)
    {
        int p=1,s=0;
        for(int i=0;i<10;i++)
        {
            if(((a>>i)& 1)){

                s+=p;

            }
            else p+=p;
        }

        return s;



    }
int ckOpMode(int p)
    {
        if(strcmp(seg[p][2],"R/W")==0 || strcmp(seg[p][2],"W/R")==0 ) return 2;
        else if( strcmp(seg[p][2],"W")==0 || strcmp(seg[p][2],"w")==0  ) return 1;
        else if( strcmp(seg[p][2],"R")==0 || strcmp(seg[p][2],"r")==0  ) return 0;
        else return -1;

    }

int main()
{

    FILE *value,*Pseg,*input,*output;

    char ch;
    memory[0]='A';
    value=fopen("value.txt","r");
    ch=getc(value);
    fclose(value);
    value=fopen("value.txt","r");

    for(int i=1;ch!=EOF;i++)
    {
        fscanf(value," %[^\n]",&memory[i]);
        ch=getc(value);
    }

    fclose(value);

    output=fopen("output.txt","w");
    cout<<"Memory size: "<<strlen(memory)<<endl;
    fprintf(output,"Memory Size %d\n",strlen(memory));
    fclose(output);


/*
    for(int i =0;i<strlen(memory);i++)
    {
        cout<<memory[i]<<endl;
    }
*/
    Pseg=fopen("seg.txt","r");
    ch=getc(Pseg);
    fclose(Pseg);
    int c;
    Pseg=fopen("seg.txt","r");
    for(int i=0;ch!=EOF;i++)
    {
        for(int j=0;j<3;j++)
        {

            fscanf(Pseg,"%s",&seg[i][j]);
            ch=getc(Pseg);
        }
        c=i;
    }

    fclose(Pseg);
    /*
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<< seg[i][j]<<"\t";

        }
        cout<<endl;

    }
*/

    input=fopen("input.txt","r");
    ch=getc(input);
    fclose(input);
    input=fopen("input.txt","r");
    output=fopen("output.txt","a+");

    int a;
    char v;
    char op;


    for(int i=1;ch!=EOF;i++)
    {

            fscanf(Pseg,"%c",&op);
             if ((op=='r') || (op=='R') )
            {
                fscanf(input,"%d",&a);
                int pos;
                pos=Pp(a);
                cout<<"For Input Line "<<i <<" : ";
                fprintf(output,"For Input Line %d : ",i);
                if(ckOpMode(pos)==0 || ckOpMode(pos)==2 ) {
                        if(atoi(seg[pos][1])>=ofset(a))
                        {
                            cout<<memory[atoi(seg[pos][0])+ofset(a)]<<endl;
                            fprintf(output,"%c\n",memory[atoi(seg[pos][0])+ofset(a)]);
                        }
                        else {cout<<"Out of Bound !!! \n";
                        fprintf(output,"Out of Bound !!! \n");
                        }


                }
                else {cout<<"Have No Permission to Read Data !!! \n";
                fprintf(output,"Have No Permission to Read Data !!! \n");
                }



            }
            else if ((op=='W') || (op=='w') )
            {

                fscanf(input,"%d %c",&a,&v);
                int pos;
                pos=Pp(a);
                cout<<"For Input Line "<<i <<" : ";
                fprintf(output,"For Input Line %d : ",i);
                if(ckOpMode(pos)==1 || ckOpMode(pos)==2) {
                        if(atoi(seg[pos][1])>=ofset(a))
                        {
                            memory[atoi(seg[pos][0])+ofset(a)]=v;
                            cout<<"New value is : "<<memory[atoi(seg[pos][0])+ofset(a)]<<endl;
                            fprintf(output,"New value is : %c\n",memory[atoi(seg[pos][0])+ofset(a)]);
                        }
                        else {cout<<"Out of Bound !!! \n";
                        fprintf(output,"Out of Bound !!! \n");
                        }


                }
                else {cout<<"Have No Permission to Write Data !!! \n";
                fprintf(output,"Have No Permission to Write Data !!! \n");
                }

            }
            ch=getc(Pseg);

        //c=i;

    }
    fclose(output);

    return 0;

}
