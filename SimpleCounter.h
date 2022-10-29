
#ifndef CPP_SAMPLE__SIMPLECOUNTER_H_
#define CPP_SAMPLE__SIMPLECOUNTER_H_

class SimpleCounter {
  public:
  int cnt = 0;
  SimpleCounter() {
    cnt = 0;
  }
  void countUP() {
    cnt++;
  }
  int getCounter() {
    return cnt;
  }
};

#endif//CPP_SAMPLE__SIMPLECOUNTER_H_
