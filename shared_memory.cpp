#include "shared_memory.h"

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>

#define IPC_ERROR (-1)

using namespace std;

static int get_shared_block(char *filename, int size) {
  key_t key;
  key = ftok(filename, 1);
  if(key == IPC_ERROR) {
    cout << "[ERROR] failed to ftok in get_shared_block()" << endl;
    return IPC_ERROR;
  }
  return shmget(key, size, 0644 | IPC_CREAT);
}

char *attach_memory_block(char *filename, int size) {
  int shared_block_id = get_shared_block(filename, size);
  char *result;

  if(shared_block_id == IPC_ERROR) {
    cout << "[ERROR] failed to get_shared_block in attach_memory_block" << endl;
    return nullptr;
  }

  result = (char *)shmat(shared_block_id, nullptr, 0);
  if (result == (char *)IPC_ERROR) {
    cout << "[ERROR] failed to shmat in attach_memory_block" << endl;
    return nullptr;
  }

  return result;
}

bool detach_memory_block(char *block) {
  return (shmdt(block) != IPC_ERROR);
}

bool destroy_memory_block(char *filename) {
  int shared_block_id = get_shared_block(filename, 0);
  if(shared_block_id == IPC_ERROR) {
    cout << "[ERROR] failed to get_shared_block in destroy_memory_block" << endl;
    return false;
  }

  return (shmctl(shared_block_id, IPC_RMID, nullptr) != IPC_ERROR);
}

