#include <stdio.h>

typedef struct control_message
{
    int opcode;
    int statuscode;
} cm;

typedef union Packet
{
    cm controlmsg;
    char payload[100];
} packet;

typedef struct DataPacket
{
    int flag;
    packet p1;
} datapacket;

int main()
{
    datapacket d1[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter choice :\n");
        printf("1.Control Message\n2.Payload\n");
        scanf("%d", &d1[i].flag);
        switch (d1[i].flag)
        {
        case 1:
            printf("Enter the opcode :");
            scanf("%d", &d1[i].p1.controlmsg.opcode);
            printf("Enter the statuscode :");
            scanf("%d", &d1[i].p1.controlmsg.statuscode);

            printf("opcode : %d\n", d1[i].p1.controlmsg.opcode);
            printf("Status code : %d\n", d1[i].p1.controlmsg.statuscode);
            break;
        case 2:
            printf("Enter the payload :");
            gets(d1[i].p1.payload);
            printf("Payload : ");
            puts(d1[i].p1.payload);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}