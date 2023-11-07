#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
        int status, cpid, endpid;

        if((cpid=fork())==0){
                printf("\tchild process:%d\n",getpid());
                sleep(10);
                printf("\tchild end\n");
                exit(10);
        }

        endpid=wait(&status);
        printf("end pid : %d\n",endpid);
        printf("WIFEXITED : %d\n",WIFEXITED(status));
        printf("WEXITSTATUS : %d\n",WEXITSTATUS(status));
        printf("WIFSIGNALED : %d\n",WIFSIGNALED(status));

        printf("\n");
        printf("parent end\n");

}

/*int execve(const char *pathname, char *const argv[], char *const envp[])
{
    // execve(path, args, env)
    return 0;
}*/


/*int main(int argc, char *argv[], char *envp[]) // execve()
{
    pid_t pid;
    int x;
    x = 0;

    pid = fork();
    if(pid > 0)
    {  // 부모 코드
        x = 1;
        printf("부모 PID : %ld,  x : %d , pid : %d\n",(long)getpid(), x, pid);
    }
    else if(pid == 0)
    {  // 자식 코드
        x = 2;
        printf("자식 PID : %ld,  x : %d\n",(long)getpid(), x);
    }
    else
    {  // fork 실패
        printf("fork Fail! \n");
        return -1;
    }
    return 0;
}*/


// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main (int argc, char* argv[])
// {
// 	int n;
// 	pid_t pid;
// 	int fd[2];
	
// 	pipe(fd);
// 	if((pid = fork()) == 0) // 0 : child process
// 	{
// 		close(fd[0]); // fd[0] : read end, fd[1] : write end 
// 		dup2(fd[1], 1); // copy fd[1] to 1: output
// 		close(fd[1]); 
// 		execl("/bin/who", "who" , NULL); // execute who
// 	}
// 	else // parent process
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], 0);
// 		close(fd[0]);
// 		execl("/bin/wc", "wc", NULL); // execute wc
// 	}
	 
// 	return 0;
// }