// 9. IMPLEMENT CONGESTION CONTROL USING A LEAKY BUCKET ALGORITHM

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MIN(remaining_packets,y) (remaining_packets>y) ? y : remaining_packets

int main() {
    int output_rate, dropped_packets = 0, bucket_size, remaining_packets, bucket_count = 0, incoming_packets[10] = {0}, i = 0, num_of_seconds = 0, choice;

    printf("\nEnter bucket size: ");
    scanf("%d", &bucket_size);
    
    printf("\nEnter output rate: ");
    scanf("%d", &output_rate);

    do {
        printf("\nEnter number of packets coming at second %d: ", i+1);
        scanf("%d", &incoming_packets[i]);
        i++;

        printf("Enter 1 to continue or 0 to quit: ");
        scanf("%d", &choice);
    } while (choice);

    num_of_seconds = i;

    printf("\num_of_secondsond\treceived\tsend\tdropped_packetsped\tremaining\n");
    for (i = 0; bucket_count || i < num_of_seconds; i++) {
        printf("%d\t%d\t\t%d\t", i+1, incoming_packets[i], MIN((incoming_packets[i] + bucket_count), output_rate));

        if ((remaining_packets = incoming_packets[i] + bucket_count - output_rate) > 0) {
            if (remaining_packets > bucket_size) {
                bucket_count = bucket_size;
                dropped_packets = remaining_packets - bucket_size;
            } else {
                bucket_count = remaining_packets;
                dropped_packets = 0;
            }
        } else {
            bucket_count = 0;
            dropped_packets = 0;
        }
        printf("%d\t%d\n", dropped_packets, bucket_count);
    }
    getch();

    return 0;
}

