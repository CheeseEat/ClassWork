#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>

void main(int argc, char *argv[])
{

    //checking argument amount
    if(argc != 6)
    {
        printf("invalid input\n");
        return;
    }

    //Getting arguments
    char* sourceIP_string = argv[1];

    char* sourcePort_string = argv[2];
    int sourcePort = atoi(sourcePort_string);

    char* destinationIP_string = argv[3];

    char* destinationPort_string = argv[4];
    int destinationPort = atoi(destinationPort_string);

    char* loss_rate_string = argv[5];
    int loss_rate = atoi(loss_rate_string);


    //Creating Sockets
    int sock_src = socket(PF_INET, SOCK_DGRAM, 0);

    int sock_dest = socket(PF_INET, SOCK_DGRAM, 0);
    

    //Binding source socket to a port
    struct sockaddr_in addr_src;
    addr_src.sin_family = PF_INET;
    addr_src.sin_port = htons(sourcePort);
    addr_src.sin_addr.s_addr = inet_addr(sourceIP_string);
    if(bind(sock_src, (struct sockaddr*) &addr_src, sizeof(addr_src)) == -1)
    {
        printf("src bind failed\n");
    }
    else
    {
        printf("src bind successful\n");
    }


    //Setting up socket to send UDP packets to
    struct sockaddr_in addr_dest;
    addr_dest.sin_family = PF_INET;
    addr_dest.sin_port = htons(destinationPort);
    addr_dest.sin_addr.s_addr = inet_addr(destinationIP_string);

    char buffer[2500];
    struct sockaddr_in blank_addr;
    int blanklen = sizeof(blank_addr);

    //Continue to recieve and send packets
    while(1) 
    {
        
        //Recieve
        int recResult = recvfrom(sock_src, buffer, sizeof(buffer), 0, (struct sockaddr*)&blank_addr, &blanklen);

        if(recResult == -1)
        {
            printf("recieve failed");
        }
        else
        {
            printf("Recived %d bytes", recResult);
        }

        //if statement for artifical loss rate
        if(rand() % 1000 >= loss_rate)
        {

            //sendto
            int sendResult = sendto(sock_dest, buffer, sizeof(buffer), 0 , (struct sockaddr*)&addr_dest, sizeof(addr_dest));

            if(sendResult == -1)
            {
                printf("send failure");
            }
            else
            {
                printf("sent %d bytes", sendResult);
            }
        
        }

    }

}