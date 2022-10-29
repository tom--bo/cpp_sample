
#ifndef CPP_SAMPLE__SHARED_MEMORY_H_
#define CPP_SAMPLE__SHARED_MEMORY_H_

#define BLOCK_SIZE 409600
#define SHARED_MEMORY_FILENAME "/tmp/shared_sample/shared_file"

char *attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);


#endif//CPP_SAMPLE__SHARED_MEMORY_H_
