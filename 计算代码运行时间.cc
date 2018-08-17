#include <boost/timer.hpp>
timer t_ogm;
......
some handle steps
......
float time_cost = t_ogm.elapsed();//返回处理处理时间



//----------

    const clock_t begin_time = clock();
    int x = 0;

    for(int i = 0; i<INT_MAX; i++)
    {
        if(i != -1)
        {
            x = 3;
        }
        else
        {

        }
    }

    float seconds = float(clock() - begin_time);
    seconds = seconds/1000;
    std::cout << "if use seconds : [" << seconds << "]" << std::endl;

