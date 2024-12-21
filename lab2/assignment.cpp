#include <iostream>
#include <thread>
#include <cstring> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>  

using namespace std;

int shm_id;
char *shared_memory;

void createSharedMemory() {
    key_t key = ftok("shmfile", 65); 
    shm_id = shmget(key, 128, 0666 | IPC_CREAT); 
    if (shm_id < 0) {
        cerr << "Failed to create shared memory!" << endl;
        exit(1);
    }
    shared_memory = (char *)shmat(shm_id, nullptr, 0); 
    if (shared_memory == (char *)-1) {
        cerr << "Failed to attach shared memory!" << endl;
        exit(1);
    }
    cout << "Shared memory created successfully!" << endl;
}
void insertDataToSharedMemory() {
    if (shared_memory == nullptr) {
        cerr << "Shared memory not created!" << endl;
        return;
    }
    string message = "Hello from Thread 2!";
    strncpy(shared_memory, message.c_str(), 128); 
    cout << "Data inserted into shared memory!" << endl;
}
int main() {
    thread t1(createSharedMemory);
    t1.join();
    thread t2(insertDataToSharedMemory);
    t2.join();
    if (shared_memory != nullptr) {
        cout << "Data in shared memory: " << shared_memory << endl;
    }
    shmdt(shared_memory);
    shmctl(shm_id, IPC_RMID, nullptr);
    cout << "Shared memory detached and destroyed!" << endl;
    return 0;
}
