#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


int getaddring( const char *node, //ip address or "www.example.com"
                const char *service, //port number or "http"
                const struct addrinfo *hints, 
                struct addrinfo **res);




//example if server want to listen host ip at port 3490;
int status;
struct addrinfo hints;
struct addrinfo *servinfo;


memset(&hints, 0, sizeof hints);

hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;


if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
    fprintf(stderr, "hetaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
}



freeaddrinfo(servinfo);



