#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *customerFile, *orderFile, *productFile, *orderDetailFile;

int wordCount(char *string, char del)
{
    int len=strlen(string);
    int wc=1;
    int i=0;
    for(i=0;i<len; i++)
    {
        if(string[i]==del)
        {
            wc++;
        }
    }
    return wc;
}

char** split(char *string, char del)
{
    fflush(stdin);

    int len=strlen(string);
    int wc=(string,del);
    //printf("%d",wc);
fflush(stdin);
    int *cc;
    char **splitted;
    int i=0,j=0,k=0;
    splitted=malloc(wc*sizeof(char*));
    cc=malloc(wc*sizeof(int));
    cc[0]=0;
    int t=0;
    for(i=0;i<len; i++)
    {
        //printf("\n%c %d %d",string[i], t, cc[t]);
        if(string[i]==del)
        {
           // printf("\n$$$%d",t);
            splitted[t]=malloc(cc[t]*sizeof(char));
            t++;
            cc[t]=0;
            continue;
        }
        cc[t]++;
    }

    //printf("\n$$$%d",t);
    splitted[t]=malloc(cc[t]*sizeof(char));
    //printf("\n@%d",cc[t]);
    /*for(i=0;i<wc;i++)
    {
        for(j=0;j<sizeof(splitted[i]);j++)
            splitted[i][j]=" ";
    }*/

    for( i=0, j=0, k=0;k<len; k++)
    {
        if(string[k]==del)
        {
            j++;
            i=0;
            continue;
        }
        //printf("\n%d %d %d %c",j,i,k,string[k]);
        splitted[j][i]=string[k];
        i++;
    }

    /*for(i=0; i<wc; i++)
    {
        printf("%s",splitted[i]);
    }*/

    fflush(stdin);
    return splitted;
}

char*** readCustomer(char *sel)
{
    int i=0;
    int count=1;
    int count2=0;
    customerFile=fopen("customer","r");
    char c;
    for( c=fgetc(customerFile);c!=EOF;c=fgetc(customerFile))
    {
        if(c=='\n')
        {
            count++;
        }
    }
    fclose(customerFile);

    for( i=0; i<8; i++)
    {
        if(sel[i]=='1')
        {
            count2++;
        }
    }
    //printf("%d %d",count,count2);

    char ***data;
    data=malloc(count*sizeof(char**));
    for( i=0; i<count; i++)
    {
        data[0]=malloc(count2*sizeof(char*));
    }

    customerFile=fopen("customer","r");

    char tmp[1000];

    fgets(tmp,1000,customerFile);
    while(!feof(customerFile))
    {
        //printf("%s",tmp);
        char **tmpSplitted=split(tmp,',');
        int j=0;
        int k=0;
        for( k=0; k<8; k++)
        {
            if(sel[k]=='1')
            {
                data[i][j]=tmpSplitted[k];
                printf("\n%s",data[i][j]);
            }
        }
        fgets(tmp,1000,customerFile);
    }
    return data;
    fclose(customerFile);

}
char*** readOrder(char *sel)
{
    int i=0;
    int count=1;
    int count2=0;
    orderFile=fopen("order","r");
    char c;
    for( c=fgetc(orderFile);c!=EOF;c=fgetc(orderFile))
    {
        if(c=='\n')
        {
            count++;
        }
    }
    fclose(orderFile);

    for(i=0; i<3; i++)
    {
        if(sel[i]=='1')
        {
            count2++;
        }
    }
    //printf("%d %d",count,count2);

    char ***data;
    data=malloc(count*sizeof(char**));
    for(i=0; i<count; i++)
    {
        data[0]=malloc(count2*sizeof(char*));
    }

    orderFile=fopen("order","r");
    char tmp[1000];
     i=0;
    fgets(tmp,1000,orderFile);
    while(!feof(orderFile))
    {
        //printf("%s",tmp);
        char **tmpSplitted=split(tmp,',');
        int j=0;
        int k=0;
        for( k=0; k<3; k++)
        {
            if(sel[k]=='1')
            {
                data[i][j]=tmpSplitted[k];
                printf("\n%s",data[i][j]);
            }
        }
        fgets(tmp,1000,orderFile);
    }
    return data;
    fclose(orderFile);

}

char*** readProduct(char *sel)
{
    int i=0;
    int count=1;
    int count2=0;
    productFile=fopen("product","r");
    char c;
    for( c=fgetc(productFile);c!=EOF;c=fgetc(productFile))
    {
        if(c=='\n')
        {
            count++;
        }
    }
    fclose(productFile);

    for(i=0; i<4; i++)
    {
        if(sel[i]=='1')
        {
            count2++;
        }
    }
    //printf("%d %d",count,count2);

    char ***data;
    data=malloc(count*sizeof(char**));
    for(i=0; i<count; i++)
    {
        data[0]=malloc(count2*sizeof(char*));
    }

    productFile=fopen("product","r");
    char tmp[1000];

    fgets(tmp,1000,productFile);
    while(!feof(productFile))
    {
        //printf("%s",tmp);
        char **tmpSplitted=split(tmp,',');
        int j=0;
        int k=0;
        for( k=0; k<4; k++)
        {
            if(sel[k]=='1')
            {
                data[i][j]=tmpSplitted[k];
                printf("\n%s",data[i][j]);
            }
        }
        fgets(tmp,1000,productFile);
    }
    return data;
    fclose(productFile);

}
char*** readOrderDetail(char *sel)
{
    int i=0;
    int count=1;
    int count2=0;
    orderDetailFile=fopen("order_detail","r");
    char c;
    for( c=fgetc(orderDetailFile);c!=EOF;c=fgetc(orderDetailFile))
    {
        if(c=='\n')
        {
            count++;
        }
    }
    fclose(orderDetailFile);

    for(i=0; i<3; i++)
    {
        if(sel[i]=='1')
        {
            count2++;
        }
    }
    //printf("%d %d",count,count2);

    char ***data;
    data=malloc(count*sizeof(char**));
    for(i=0; i<count; i++)
    {
        data[0]=malloc(count2*sizeof(char*));
    }

    orderDetailFile=fopen("order_detail","r");
    char tmp[1000];
     i=0;
    fgets(tmp,1000,orderDetailFile);
    while(!feof(orderDetailFile))
    {
        //printf("%s",tmp);
        char **tmpSplitted=split(tmp,',');
        int j=0;
        int k=0;
        for(k=0; k<3; k++)
        {
            if(sel[k]=='1')
            {
                data[i][j]=tmpSplitted[k];
                printf("\n%s",data[i][j]);
            }
        }
        fgets(tmp,1000,orderDetailFile);
    }
    return data;
    fclose(orderDetailFile);

}

void writeCustomer()
{
    char cid[10],fname[100],lname[100],gen[10],dob[10],cno[10],address[100],pincode[10];
    customerFile=fopen("customer","a+");
    printf("Enter customer id:\n");
    fflush(stdin);
    gets(cid);
    printf("Enter customer first name:\n");
    fflush(stdin);
    gets(fname);
    printf("Enter last name:\n ");
    fflush(stdin);
    gets(lname);

    printf("Enter gen:\n");
    fflush(stdin);
    gets(gen);
    printf("Enter dob:\n");
    fflush(stdin);
    gets(dob);
    printf("Enter customer contact number:\n");
    fflush(stdin);
    gets(cno);

    printf("Enter customer short address:\n");
    fflush(stdin);
    gets(address);
    printf("Enter customer pincode:\n");
    fflush(stdin);
    gets(pincode);

    fprintf(customerFile,"%s,%s,%s,%s,%s,%s,%s,%s\n",cid,fname,lname,gen,dob,cno,address,pincode);
    fclose(customerFile);
}

void writeOrder()
{
    char cid[10],oid[10],odate[100];
    orderFile=fopen("order","a+");
    printf("Enter order id:\n");
    fflush(stdin);
    gets(oid);
    printf("Enter order date:\n");
    fflush(stdin);
    gets(odate);
    printf("Enter customer id \n");
    fflush(stdin);
    gets(cid);
    fprintf(orderFile,"%s,%s,%s\n",oid,odate,cid);
    fclose(orderFile);
}

void writeProduct()
{
    char pid[10],pname[10],price[10],uom[10];
    productFile=fopen("product","a+");
    printf("Enter product id:\n");
    fflush(stdin);
    gets(pid);
    printf("Enter product name:\n");
    fflush(stdin);
    gets(pname);
    printf("Enter price:\n ");
    fflush(stdin);
    gets(price);
    printf("Enter unit of measurement:\n ");
    fflush(stdin);
    gets(uom);
    fprintf(productFile,"%s,%s,%s,%s\n",pid,pname,price,uom);
    fclose(productFile);
}
void writeOrderDetail()
{
    char oid[10],pid[10],qnt[100];
    orderDetailFile=fopen("order_detail","a+");
    printf("Enter order id:\n");
    fflush(stdin);
    gets(oid);
    printf("Enter product id:\n");
    fflush(stdin);
    gets(pid);
    printf("Enter quantity:\n ");
    fflush(stdin);
    gets(qnt);
    fprintf(orderDetailFile,"%s,%s,%s\n",oid,pid,qnt);
    fclose(orderDetailFile);
}

int main(int argc, char* argv[])
{
    int c;
    while(1)
    {
		printf("1.Add customer details:");
		printf("2.Add order:");
		printf("3.Add product:");
		printf("4.Add order details:");
		printf("5.Enter Query:");
		printf("0.EXIT:");
		char query[1000];
		//writeProduct();
		//char ***data=readProduct("1111");

		printf("Enter your choice :");
		scanf("%d",&c);


		switch(c)
		{

			case 1:
				writeCustomer();
				break;
			case 2:
				writeOrder();
				break;
			case 3:
				writeProduct();
				break;
			case 4:
				writeOrderDetail();
				break;
			case 5:
				printf("FOLLOWING ARE THE ATTRIBUTES USED:\n");
				printf("Customer:");
				printf("cid,fname,lname,gen,dob,cno,address,pincode\n");
				printf("Order:");
				printf("cid,oid,odate\n");
				printf("Product:");
				printf("pid,pname,price,uom\n");
				printf("Order Details:");
				printf("oid,pid,qnt\n");



				printf("Enter your query: \n");
				fflush(stdin);
				gets(query);

				char** querySplitted=split(query,' ');
				fflush(stdin);
				int wc=wordCount(query,' ');
				fflush(stdin);

				if(strcmp(querySplitted[0],"SELECT")!=0)
				{
					printf("\nCommand %s is not supported yet. Only select is.",querySplitted[0]);
				}

				if(strcmp(querySplitted[1],"*")==0)
				{
					if(strcmp(querySplitted[2],"FROM")!=0)
					{
						printf("Unknown keyword %s. Expected FROM keyword.",querySplitted[2]);
					}
					else if(strcmp(querySplitted[3],"customer")==0)
					{
						char ***data=readCustomer("11111111");
					}

					else if(strcmp(querySplitted[3],"product")==0)
					{
						char ***data=readProduct("1111");
					}

					else if(strcmp(querySplitted[3],"order")==0)
					{
						char ***data=readOrder("111");
					}
					else if(strcmp(querySplitted[3],"order_detail")==0)
					{
						char ***data=readOrderDetail("111");
					}
					else
					{
						printf("Such data doesn't exist");
					}

				}

				else if(strcmp(querySplitted[wc-2],"FROM")==0)
				{
					char tmp2[]="00000000";
					char** columns=split(querySplitted[1],',');
					int n=wordCount(querySplitted[1],',');
					if(strcmp(querySplitted[wc-1],"customer")==0)
					{
						int i=0;
						//printf("inside customer with %s,%d",querySplitted[wc-1],n);
						for( i=0; i<n; i++)
						{
							if(strcmp(columns[i],"cid")==0)
							{

								if(tmp2[0]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[0]='1';
							}
							else if(strcmp(columns[i],"fname")==0)
							{
								if(tmp2[1]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[1]='1';
							}
							else if(strcmp(columns[i],"lname")==0)
							{
								if(tmp2[2]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[2]='1';
							}
							else if(strcmp(columns[i],"gen")==0)
							{
								if(tmp2[3]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[3]='1';
							}
							else if(strcmp(columns[i],"dob")==0)
							{
								if(tmp2[4]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[4]='1';
							}
							else if(strcmp(columns[i],"cno")==0)
							{
								if(tmp2[5]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[5]='1';
							}
							else if(strcmp(columns[i],"address")==0)
							{
								if(tmp2[6]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[6]='1';
							}
							else if(strcmp(columns[i],"pincode")==0)
							{
								if(tmp2[7]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[7]='1';
							}
							//printf("%s",tmp2);
						}
						char ***data=readCustomer(tmp2);
					}



					else if(strcmp(querySplitted[wc-1],"product")==0)
					{
						char tmp2[]="0000";
						int i=0;//printf("inside customer with %s,%d",querySplitted[wc-1],n);
						for(i=0; i<n; i++)
						{
							if(strcmp(columns[i],"pid")==0)
							{

								if(tmp2[0]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[0]='1';
							}
							else if(strcmp(columns[i],"pname")==0)
							{
								if(tmp2[1]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[1]='1';
							}
							else if(strcmp(columns[i],"price")==0)
							{
								if(tmp2[2]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[2]='1';
							}
							else if(strcmp(columns[i],"uom")==0)
							{
								if(tmp2[3]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[3]='1';
							}
						}
						char ***data=readProduct(tmp2);
					}

					else if(strcmp(querySplitted[wc-1],"order")==0)
					{
						char tmp2[]="000";
						int i=0;
						//printf("inside customer with %s,%d",querySplitted[wc-1],n);
						for(i=0; i<n; i++)
						{
							if(strcmp(columns[i],"oid")==0)
							{

								if(tmp2[0]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[0]='1';
							}
							else if(strcmp(columns[i],"odate")==0)
							{
								if(tmp2[1]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[1]='1';
							}
							else if(strcmp(columns[i],"cid")==0)
							{
								if(tmp2[2]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[2]='1';
							}
						}
						char ***data=readOrder(tmp2);
					}
					else if(strcmp(querySplitted[wc-1],"order_detail")==0)
					{
						 char tmp2[]="000";
						int i=0;
						//printf("inside customer with %s,%d",querySplitted[wc-1],n);
						for(i=0; i<n; i++)
						{
							if(strcmp(columns[i],"oid")==0)
							{

								if(tmp2[0]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[0]='1';
							}
							else if(strcmp(columns[i],"pid")==0)
							{
								if(tmp2[1]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[1]='1';
							}
							else if(strcmp(columns[i],"qnt")==0)
							{
								if(tmp2[2]=='1')
								{
									printf("The field %s is repeated. But it will be shown once.",columns[i]);
								}
								tmp2[2]='1';
							}
						}
						char ***data=readOrderDetail(tmp2);
					}
				}
				break;
			case 0:
				exit(0);
				break;
			}
		}
	}
}
