#include <stdio.h>
#include <grp.h>

int main(int argc, char * argv[ ])
{
int i;
struct group *groupName;
char ** p;


   if((groupName=getgrnam(argv[1])) != NULL)
   {      
      fprintf(stdout,"Group Name: %s\n",groupName->gr_name);
      for( p = groupName->gr_mem; *p != NULL; p++ ) {
       printf( "\t%s\n", *p );
    	}
      // fprintf(stdout,"GID: %d\n",groupName->gr_gid);
      /*
	//List everyone in the group
         for(i=0; groupRec->gr_mem[i]; i++)
            fprintf(stdout,"   member: %s\n",groupRec->gr_mem[i]);
            fprintf(stdout,"\n\n");
	*/
   }

}

