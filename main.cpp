#include "shared_memory.h"
#include "stack.h"
#include "SimpleCounter.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define SHARED_STR_OFFSET 10

void sample_stack() {
  // Stack<int> *s = new Stack<int>();
  // s->push(1);
  // int ret;
  // s->pop(&ret);
  // std::cout << ret << std::endl;

  // Stack<int> *s2 = new Stack<int>(20);
  // s2->push(10);
  // int ret2;
  // s2->pop(&ret2);
  // std::cout << ret2 << std::endl;

  std::vector<Stack<int>> vs = std::vector<Stack<int>>(10);

}

void sample_shared_mem(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "use ./sample (input_string) (mode)" << endl;
    cout << "mode: 1 -> write, 2 -> read" << endl;
    return;
  }

  char *block = attach_memory_block(SHARED_MEMORY_FILENAME, BLOCK_SIZE);
  //char *block = attach_memory_block(SHARED_MEMORY_FILENAME, BLOCK_SIZE);
  if(block == nullptr) {
    cout << "[ERROR] failed to get block" << endl;
    cout << errno << endl;
    return;
  }

  if(argv[2][0] == '1') {
    cout << "Write '" << argv[1] << "' to shared memory." << endl;
    // FIXED with SHARED_STR_OFFSET !!
    strncpy(block, argv[1], SHARED_STR_OFFSET);
    // strncpy(block, argv[1], BLOCK_SIZE);
    // !!
  } else if(argv[2][0] == '2') {
    cout << "Read from shared memory." << endl;
    cout << "The content I read is..." << endl;
    cout << block << endl;
  } else if(argv[2][0] == '3') {
    cout << "Destroy shared memory file." << endl;
    destroy_memory_block(block);
    return;
  } else if(argv[2][0] == '4') {
    cout << "New SimpleCounter size: " << sizeof(SimpleCounter) << endl;
    SimpleCounter *c = new(block+SHARED_STR_OFFSET) SimpleCounter();
    c->countUP();
  } else if(argv[2][0] == '5') {
    cout << "Count up SimpleCounter" << endl;
    SimpleCounter *c = (SimpleCounter *)(block + SHARED_STR_OFFSET);
    c->countUP();
  } else if(argv[2][0] == '6') {
    cout << "Get value of SimpleCounter" << endl;
    SimpleCounter *c = (SimpleCounter *)(block + SHARED_STR_OFFSET);
    cout << "Counter Val: " << c->getCounter() << endl;
  } else {
    cout << "[ERRROR] command mode is not defined" << endl;
  }

  detach_memory_block(block);
}

int main(int argc, char *argv[]) {
  std::cout << "sample codes!" << std::endl;

  // sample_stack();
  sample_shared_mem(argc, argv);

  return 0;
}
