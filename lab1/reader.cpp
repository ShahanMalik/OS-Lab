#include<iostream>
#include<sys/ipc.h>  // required for shared memory
#include<sys/shm.h>  // required for shared memory
using namespace std;

int main() {
    key_t key = ftok("shmfile", 100); // unique key is generated
    int shm_id = shmget(key, 128, 0666 | IPC_CREAT); // shared memory of size 128 bytes is declared
    char *sh_data = (char*) shmat(shm_id, 0, 0); // shared memory is attached with process
    cout << "Message Received from Shared Memory is: " << endl;
    cout << sh_data << endl; // data is read from shared memory
    shmdt(sh_data); // process is detached from shared memory
    shmctl(shm_id, IPC_RMID, NULL); // shared memory is destroyed
    return 0;
}
