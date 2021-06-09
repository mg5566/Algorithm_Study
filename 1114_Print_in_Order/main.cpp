class Foo {
  private:
    mutex first_mutex;
    mutex second_mutex;

public:
    Foo() {
      first_mutex.lock();
      second_mutex.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_mutex.unlock();
    }

    void second(function<void()> printSecond) {
        first_mutex.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        first_mutex.unlock();
        second_mutex.unlock();
    }

    void third(function<void()> printThird) {
        second_mutex.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        second_mutex.unlock();
    }
};
