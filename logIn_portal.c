#include<stdio.h>
#include<string.h>

//variable
int a,i=3,j,k,com,cmpr,log_pass_com;
char admin[10]="mahdir";
char admin_pass[10];
char email_st[30][50]={"mahdiralahi@gmail.com","sakilmahmud@gmail.com","alichas@gmail.com"};
char pass_st[30][50]={"mahdir2899","sakil4646","azmee777"};
char log_mail[30];
char log_pass[30];
//function prototyping
int home();
void createAc();
void mail_check();
int pass_check();
void admin_fun();
void log_in();
int log_pass_check(int a);


int home()
{
     printf("                                      HOME\n\n");
     printf("                          1. Create New Account.\n");
     printf("                          2. Log In.\n");
     printf("                          3. Admin Panel.\n");
     printf("                          Press option number : ");
     scanf("%d",&a);
     return a;
}

void createAc()
{
     printf("                                  Enter Email: ");
     scanf("%s",&email_st[i]);
     printf("                                  Enter Password: ");
     scanf("%s",&pass_st[i]);
     mail_check();

}

void mail_check()
{
     for(j=0; j<i; j++)
     {
         com = strcmp(email_st[i],email_st[j]);
         if(com==0)
         {
              printf("\n                                         Mail address already Exists!\n\n");
              break;
         }
     }
     int m = pass_check();
     if(com==0 || m<8)
     {
          createAc();
     }
     else
     {
          i++;
          printf("\n                                                 Successfully Registered!\n\n");
     }
}

int pass_check()
{
     int len = strlen(pass_st[i]);
     if(len<8)
     {
          printf("\n                                         Enter Strong Password(more than 8 letter/digit)\n\n");
     }
     return len;
}

void log_in()
{
     printf("                                  Enter Mail : ");
     scanf("%s",&log_mail);
     printf("                                  Enter Password : ");
     scanf("%s",&log_pass);

     for(j=0; j<i; j++)
     {
          cmpr= strcmp(log_mail, email_st[j]);
          if(cmpr==0)
          {
               break;
          }
     }
     if(cmpr!=0)
     {
          printf("\n                                           Enter valid mail Address.\n\n");
          log_in();
     }
     else
     {
          int u = log_pass_check(j);
     if(u!=0)
     {
          log_in();
     }
     else
     {
          printf("\n                                          Welcome to Your Portal\n\n\n");
     }
     }

}

int log_pass_check(int a)
{
     log_pass_com= strcmp(log_pass,pass_st[a]);
     if(log_pass_com!=0)
     {
          printf("\n                                        Wrong Password!\n\n");
     }
     return log_pass_com;
}

void admin_fun()
{
     printf("                                  Enter Password : ");
     scanf("%s",&admin_pass);
     int p=strcmp(admin_pass,admin);

     if(p!=0)
     {
          printf("\n                                   Wrong Password!\n\n");
          admin_fun();
     }
     else
     {
          printf("\n                                All Information:\n\n");
          for(j=0; j<i; j++ )
          {
               printf("%s      %s\n",email_st[j],pass_st[j]);
          }
     }
}

int main()
{
     printf("                                <<<<Log-In Portal>>>>\n\n\n");
     int m;
     m=home();

     while(6)
     {
          if(m==1)
          {
               printf("\n\n                               *Create New Account*\n");
              createAc();
          }
          else if(m==2)
          {
               printf("\n\n                                     *Log-In*\n\n");
               log_in();
          }
          else if(m==3)
          {
               printf("\n\n                                  *Admin Pannel*\n\n");
               admin_fun();
          }
          m=home();
     }
}
