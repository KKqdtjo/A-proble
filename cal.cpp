#include <iostream>
#include <cmath>
using namespace std;
// double tan alpha=0.1
// tan belta=9/89
// double t;
// double x1=20000-300*(t+5.1)*cos alpha;
// double y1=0;
// double z1=0.1*x1;
// double x2;
// x2^2+(y2-200)^2<=49
// 0<=z2<=10
// double x3=17800-5.1*120*cosbelta
// y3=0
// z3=1800-5.1*120*belta-0.5*10(g)*(3.6^2)-3*t
// z3>=-10
// f(t)=y3-y1
int main()
{
    double alpha, beta, t;
    alpha = atan(0.1);
    beta = atan(9.0 / 89.0);
    // double x1;
    double y1 = 0;
    // double z1
    double x3 = 17800 - 5.1 * 120 * cos(beta);
    double y3 = 0;
    // doubel z3;
    double st = 0, ed = 0, ans = 0;
    int flag = 0;
    for (t = 0; double z3 = 1800 - 5.1 * 120 * beta - 0.5 * 10 * (3.6 * 3.6) - 3 * t >= -10; t += 0.01)
    {
        // cout << t << " ";
        double x1 = 20000 - 300 * (t + 5.1) * cos(alpha);
        double z1 = 0.1 * x1;
        for (double x2 = -7; x2 <= 7; x2 += 0.01)
        {
            for (double y2 = 193; y2 <= 207 && ((x2 * x2 + (y2 - 200) * (y2 - 200)) <= 49); y2 += 0.01)
            {
                for (double z2 = 0; z2 <= 10; z2 += 0.01)
                {
                    double res = pow(((y3 - y1) * (z2 - z1) - (z3 - z1) * (y2 - y1)), 2) + pow(((z3 - z1) * (x2 - x1) - (x3 - x1) * (z2 - z1)), 2) + pow(((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)), 2);
                    if (res <= 100)
                    {
                        if (flag)
                        {
                            ed = res;
                        }
                        else
                        {
                            st = res;
                        }
                        flag = 1;
                    }
                    else
                    {
                        if (flag)
                        {
                            ans += st - ed;
                        }
                        else
                        {
                        }
                        flag = 0;
                    }
                }
            }
        }
    }
    cout << "持续时间为：" << ans << endl;
    return 0;
}