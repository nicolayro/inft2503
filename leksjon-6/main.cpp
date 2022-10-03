#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <vector>


using namespace std;

int main() {
    string message;
    
    vector<thread> threads;
    for (int c = 0; c < 4; ++c) {
        threads.emplace_back([c, &message] {
            static mutex message_mutex;
            lock_guard<mutex> lock(mutex);
            message += "thread " + to_string(c) + " says hello\n"; });
    }

    for (auto &thread : threads) {
        thread.join();
    }

    cout << "hello from main" << endl;
    cout << "bye from main" << endl;
    cout << message << endl;

    return 0;
}
