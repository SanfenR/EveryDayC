//
// Created by sanfen on 2017/12/6.
//

//http://acm.hdu.edu.cn/showproblem.php?pid=1006

#include <iostream>
#include <cmath>

using namespace std;

#define HALFDAY (12*3600)

double Max(double a, double b, double c) {
    if (b > a) a = b;
    if (c > a) a = c;
    return a;
}

double Min(double a, double b, double c) {
    if (b < a) a = b;
    if (c < a) a = c;
    return a;
}

double calculateAngle(double v, int t) {
    double num = v * t;
    int numInt = (int) num;
    double dec = num - numInt;
    return (numInt % 360) + dec;
}

int main() {
//    double d;
//    double second = 1;
//    double min = 60 * second;
//    double hour = 60 * min;
//    double day = 24 * hour;
//
//    double vt = 360 / day ;
//    double vm = 360 / hour;
//    double vs = 360 / min ;
//    double st, sm, ss;
//    double dtm, dts, dms;
//
//    while (cin >> d && d != -1) {
//        int count = 0;
//        double d1 = 360 - d;
//        for (int i = 0; i < day / 2; ++i) {
//            st = calculateAngle(vt, i);
//            sm = calculateAngle(vm, i);
//            ss = calculateAngle(vs, i);
//            dtm = fabs(st - sm);
//            dms = fabs(sm - ss);
//            dts = fabs(ss - st);
//            if ((dtm > d)
//                && (dtm <= d1)
//                && (dts > d)
//                && (dts <= d1)
//                && (dms > d)
//                && (dms <= d1)) {
//                count++;
//            }
//        }
//        printf("%.3lf", (double)count / day * 100 * 2);
//        cout << endl;
//    }

    double tmh = 360 / (0.1 - 1.0 / 120), tmh_b, tmh_e,
            tsm = 360 / (6 - 0.1), tsm_b, tsm_e,
            tsh = 360 / (6 - 1.0 / 120), tsh_b, tsh_e;

    double D, i, j, k, begin, end, res;

    while (scanf("%lf", &D) && D != -1) {
        tmh_b = D / (0.1 - 1.0 / 120);
        tmh_e = (360 - D) / (0.1 - 1.0 / 120);
        tsm_b = D / (6 - 0.1);
        tsm_e = (360 - D) / (6 - 0.1);
        tsh_b = D / (6 - 1.0 / 120);
        tsh_e = (360 - D) / (6 - 1.0 / 120);

        for (i = res = 0; i <= HALFDAY; i += tmh) {
            for (j = 0; j <= HALFDAY; j += tsm) {
                if (i + tmh_e > j + tsm_b
                    && i + tmh_b < j + tsm_e) {
                    for (k = 0; k <= HALFDAY; k += tsh) {
                        if (j + tsm_e > k + tsh_b
                            && i + tmh_e > k + tsh_b
                            && i + tmh_b < k + tsh_e
                            && j + tsm_b < k + tsh_e) {
                            begin = Max(i + tmh_b, j + tsm_b, k + tsh_b);
                            end = Min(i + tmh_e, j + tsm_e, k + tsh_e);
                            if (begin < end) res += end - begin;
                        }
                    }
                }
            }
        }
        printf("%.3f\n", res * 100 / HALFDAY);
    }
    return 0;
}