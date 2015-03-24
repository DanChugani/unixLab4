/* Author: Chandan Chugani
// Date: March 24th, 2015 
// Professor: Leon King
// Description: This program reads a group from /etc/group 
//	looks it up in /etc/passwd and if it exists writes 
//	to a file called users.txt.No errors to report,however
//	if you load no argv, program will seg fault...
//	View this repository on gitHub!
//
// GitHub: https://github.com/DanChugani/unixLab4 
*/
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

int main(int argc, char *argv[],char * envp[])
{

struct group *groupName; 
struct passwd *pwdRec;
char ** p;
FILE *f;
 /* Open/make a file called users.txt */
 f = fopen("users.txt","w");
	if (f==NULL) /*check and make sure file is empty*/
	{
	 fprintf(stdout,"no file, you can start crying now...");
	}

   if((groupName=getgrnam(argv[1])) != NULL)/*Checks and makes sure that argv[1] is in /etc/group */
   {      
    fprintf(stdout,"Group Name: %s\n",groupName->gr_name);
      	for( p = groupName->gr_mem; *p != NULL; p++)/*Check if group has members*/
	{     	
	//fprintf(f, "\t%s\n", *p );
    	 fprintf(stdout,"\tmember:%s\n",*p); /*print out group member(s)*/
	 
	 pwdRec=getpwnam(*p);/*set pwdRec to the value of *p(Group Name)*/
         putpwent(pwdRec,f);/*Write all the information to the file*/
	}
   }else/*If group Name does not exist in /etc/group*/
	{
		fprintf(stdout,"Group Name: \"%s\" was not found\n",argv[1]);
	}
 fclose(f); /*Always close your files*/
}/*end of main*/

