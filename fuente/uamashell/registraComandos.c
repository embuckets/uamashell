#include "uamashell.h"
#include<stdio.h> //printf
#include<string.h>    //memset
#include<errno.h> //errno
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>
#include<stdlib.h>
#include<unistd.h>//pid userid
#include<time.h>
 
void registraCMDS(char* comando,int pid)
{

//Variables para abrir archivo bitacora_comandos.log
	FILE* bitacoraC;
	bitacoraC=fopen("programa.log","at");
//Obtener usuario
	char* user;
	user=getlogin();
//Obtener datetime
	char date[20];
	time_t t=time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(date,"%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
//PID
	char idp[16];
	sprintf(idp,"Process ID:%d",pid);
//Obtener IP
    char* defaultIP="127.0.0.1"; 
    FILE *f;
    char line[100] , *p , *c;
     
    f = fopen("/proc/net/route" , "r");
     
    while(fgets(line , 100 , f))
    {
        p = strtok(line , " \t");
        c = strtok(NULL , " \t");
         
        if(p!=NULL && c!=NULL)
        {
            if(strcmp(c , "00000000") == 0)
            {
                break;
            }
        }
    }
     
    //which family do we require , AF_INET or AF_INET6
    int fm = AF_INET;
    struct ifaddrs *ifaddr, *ifa;
    int family , s;
    char host[NI_MAXHOST];
 
    if (getifaddrs(&ifaddr) == -1) 
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
 
    //Walk through linked list, maintaining head pointer so we can free list later
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
        {
            continue;
        }
 
        family = ifa->ifa_addr->sa_family;
 
        if(strcmp( ifa->ifa_name , p) == 0)
        {
            if (family == fm) 
            {
                s = getnameinfo( ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6) , host , NI_MAXHOST , NULL , 0 , NI_NUMERICHOST);
                 
                if (s != 0) 
                {
                    printf("getnameinfo() failed: %s\n", gai_strerror(s));
                    exit(EXIT_FAILURE);
                }
                 
		//printf("address: %s", host);
            }
        }
    }
       if(strcmp(host,"")==0)
	{strcat(host,defaultIP);}
	strcat(host," ");
	strcat(host,date);
	strcat(host," ");
	strcat(host,user);
	strcat(host," ");
	strcat(host,idp);
	strcat(host," ");
	strcat(host,comando);
	strcat(host,"\n");
	fputs(host,bitacoraC);
    	freeifaddrs(ifaddr);
//Fin Obtener IP en  variable host
		
	fclose(bitacoraC);
    return;
}
