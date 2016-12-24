#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int globalvar=6;
char buf[]="write to stdout\n";
int main(){
int res,t;
pid_t pid;
int var=88;
if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
      printf("write error\n");
printf("befeore the vfork starts\n");
if((pid=fork())<0)
        printf("fork error\n");
else if(pid==0)
        {
        printf("pid of child process %ld\n",(long)getpid());
        globalvar++;
        var++;
        }
else{
        t=wait(&res);
        printf("%d is t \n",t);
        printf("pid of parent process %ld\n",(long)getpid());     
}
//printf("pid of child process %ld",(long)getpid());
printf("globalvar=%d var=%d t=%d\n",globalvar,var,t);
exit(0);
}

