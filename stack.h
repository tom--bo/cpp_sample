#ifndef CPP_SAMPLE__STACK_H_
#define CPP_SAMPLE__STACK_H_

template <class T>
class Stack {
private:
  int capacity;
  int cnt;
  T *data;

public:
  Stack(int n) : capacity(n), cnt(0) {
    data = new T[capacity];
  }

  Stack() : capacity(10), cnt(0) {
    data = new T[capacity];
  }

  bool push(T val) {
    if(cnt < capacity -1) {
      data[cnt++] = val;
      return 0;
    }
    return 1;
  }

  bool pop(T *ret) {
    if(cnt < 1) {
      return 1;
    }
    *ret = data[--cnt];
    return 0;
  }
};

#endif//CPP_SAMPLE__STACK_H_
