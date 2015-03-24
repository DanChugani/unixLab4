#include <stdio.h>
#include <grp.h>
#include <pwd.h>

int main(int argc, char *argv[],char * envp[])
{

int i;
struct group *groupName;
struct passwd *pwdRec;
char ** p;
FILE *f;

 f = fopen("users.txt","w");
	if (f==NULL)
	{
	 fprintf(stdout,"no file, you can start crying now...");
	}

   if((groupName=getgrnam(argv[1])) != NULL)
   {      
      fprintf(stdout,"Group Name: %s\n",groupName->gr_name);
      	for( p = groupName->gr_mem; *p != NULL; p++)
	{     	
	 fprintf(f, "\t%s\n", *p );
    	 fprintf(stdout,"\tmember:%s\n",*p);
	}


   }else
	{
		fprintf(stdout,"Group Name: \"%s\" was not found\n",argv[1]);
	}

}

