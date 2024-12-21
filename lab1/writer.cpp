#include<iostream>
#include<sys/ipc.h>  // required for shared memory
#include<sys/shm.h>  // required for shared memory
using namespace std;

int main() {
    key_t key = ftok("shmfile", 100); // unique key is generated
    int shm_id = shmget(key, 128, 0666 | IPC_CREAT); // shared memory of size 128 bytes is declared
    char *sh_data = (char*) shmat(shm_id, 0, 0); // shared memory is attached with process
    cout << "Write Your Message" << endl;
    cin.getline(sh_data, 100); // data is written to shared memory
    shmdt(sh_data); // process is detached from shared memory
    return 0;
}
