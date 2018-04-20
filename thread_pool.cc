#include <thread>
#include <iostream>
#include <future>
#include <mutex>
#include <vector>
#include <functional>
#include <new>

using namespace std;

int sum (int a, int b)
{
    cout<<a<<"+"<<b<<endl;
    return a+b;
}



class ThreadPool
{
    public:
    
    template <class T>
    
    future <T> doit (function<T(void)> fn)
    {
        promise <T> * p = new promise <T>;
        future <T> f = p->get_future();
        p->set_value(fn());
        return f;
//        return async(fn);
    }
};

int main()
{
        class ThreadPool pool;
    //    vector <future<int>> jobs;
    //    for (int i = 0; i < 10; i++)
     //   {
            future<int> temp = pool.doit<int>(bind (sum,1,2));
            cout<<temp.get()<<endl;
    //        jobs.push_back(temp);
    //    }
        return 0;
};
