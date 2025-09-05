#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define M_PI 3.14159265358979323846
vector<double> q;
priority_queue<double> res;
double f_min(double a, double b, double c)
{
    // 求 ax^2 + bx + c 在 [0,1] 上的最小值

    // 特殊情况：a = 0，退化为线性函数
    if (abs(a) < 1e-12)
    {
        if (abs(b) < 1e-12)
        {
            return c; // 常函数
        }
        // 线性函数 bx + c
        double f0 = c;     // f(0)
        double f1 = b + c; // f(1)
        return min(f0, f1);
    }

    // 二次函数情况
    double f0 = c;         // f(0) = c
    double f1 = a + b + c; // f(1) = a + b + c

    // 对称轴 x = -b/(2a)
    double vertex_x = -b / (2.0 * a);

    // 如果对称轴在 [0,1] 区间内
    if (vertex_x >= 0 && vertex_x <= 1)
    {
        double vertex_y = a * vertex_x * vertex_x + b * vertex_x + c;

        if (a > 0)
        {
            // 开口向上，顶点是最小值
            return vertex_y;
        }
        else
        {
            // 开口向下，顶点是最大值，最小值在端点
            return min(f0, f1);
        }
    }
    else
    {
        // 对称轴不在区间内，最小值必在端点
        return min(f0, f1);
    }
}
int main()
{
    // 需要遍历的数值
    double gama, t1, t2, speed;
    double alpha, t;
    alpha = atan(0.1);
    // double x1;
    double y1 = 0;
    // double z1
    // double x3
    // double y3
    // doubel z3
    double st = 0, ed = 0, ans = 0;
    int flag = 1;
    for (gama = 0; gama <= 180; gama += 5)
    {
        for (t1 = 0; t1 <= 26.0; t1 += 1)
        {
            for (t2 = 0; t2 <= 20.0; t2 += 1)
            {
                for (speed = 70; speed <= 140; speed += 5)
                {
                    for (t = 0; t <= 20; t += 0.1)
                    {
                        flag = 1;
                        // cout << t << " ";
                        double gama_rad = gama * M_PI / 180.0;
                        double x1 = 20000 - 300 * (t + t1 + t2) * cos(alpha);
                        double z1 = 2000 - 300 * (t + t1 + t2) * sin(alpha);
                        double x3 = 17800 - speed * (t1 + t2) * cos(gama_rad);
                        double y3 = speed * (t1 + t2) * sin(gama_rad);
                        double z3 = 1800 - 0.5 * 9.8 * t2 * t2 - 3 * t;
                        if (z3 < -10)
                        {
                            break;
                        }
                        for (double theta = 0; theta < 360; theta += 1)
                        {
                            double theta_rad = theta * M_PI / 180.0;
                            double x2 = 7.0 * cos(theta_rad);
                            double y2 = 200.0 + 7.0 * sin(theta_rad);
                            for (double z2 = 0; z2 <= 10; z2 += 10)
                            {
                                // double res = (pow(((y3 - y1) * (z2 - z1) - (z3 - z1) * (y2 - y1)), 2) + pow(((z3 - z1) * (x2 - x1) - (x3 - x1) * (z2 - z1)), 2) + pow(((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)), 2)) / ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
                                double a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
                                double b = 2 * ((x2 - x3) * (x1 - x2) + (y2 - y3) * (y1 - y2) + (z2 - z3) * (z1 - z2));
                                double c = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2) - 100;

                                if (f_min(a, b, c) <= 0)
                                {
                                }
                                else
                                {
                                    flag = 0;
                                }
                            }
                        }
                        if (!flag)
                        {
                        }
                        else
                        {
                            q.push_back(t);
                        }
                    }
                    // cout << q.size() << endl;
                    // cout << q[0] << " " << q[q.size() - 1] << endl;
                    for (int i = 0; i < q.size() - 1; i++)
                    {
                        // cout << q[i] << endl;
                        if (abs(q[i + 1] - q[i] - 0.1) < 1e-9)
                        {
                            ans += 0.01;
                        }
                    }
                    if (ans >= 1.3)
                    {
                        res.push(ans);
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << res.top() << " ";
        res.pop();
    }
    return 0;
}
