#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Eigen/Dense"
#include "Math/SMatrix.h"

//Time taken: 9914.71ms
Eigen::MatrixXd matrixMultManual(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
{

  const Eigen::MatrixXd m3 = m1 * m2;

  const double a = m1(0, 0) * m3(0, 0) + m1(0, 1) * m3(0, 1) + m1(0, 2) * m3(0, 2) + m1(0, 3) * m3(0, 3) + m1(0, 4) * m3(0, 4) + m1(0, 5) * m3(0, 5);
  const double b = m1(1, 0) * m3(0, 0) + m1(1, 1) * m3(0, 1) + m1(1, 2) * m3(0, 2) + m1(1, 3) * m3(0, 3) + m1(1, 4) * m3(0, 4) + m1(1, 5) * m3(0, 5);
  const double c = m1(2, 0) * m3(0, 0) + m1(2, 1) * m3(0, 1) + m1(2, 2) * m3(0, 2) + m1(2, 3) * m3(0, 3) + m1(2, 4) * m3(0, 4) + m1(2, 5) * m3(0, 5);
  const double d = m1(3, 0) * m3(0, 0) + m1(3, 1) * m3(0, 1) + m1(3, 2) * m3(0, 2) + m1(3, 3) * m3(0, 3) + m1(3, 4) * m3(0, 4) + m1(3, 5) * m3(0, 5);
  const double e = m1(4, 0) * m3(0, 0) + m1(4, 1) * m3(0, 1) + m1(4, 2) * m3(0, 2) + m1(4, 3) * m3(0, 3) + m1(4, 4) * m3(0, 4) + m1(4, 5) * m3(0, 5);
  const double f = m1(5, 0) * m3(0, 0) + m1(5, 1) * m3(0, 1) + m1(5, 2) * m3(0, 2) + m1(5, 3) * m3(0, 3) + m1(5, 4) * m3(0, 4) + m1(5, 5) * m3(0, 5);

  const double g = m1(0, 0) * m3(1, 0) + m1(0, 1) * m3(1, 1) + m1(0, 2) * m3(1, 2) + m1(0, 3) * m3(1, 3) + m1(0, 4) * m3(1, 4) + m1(0, 5) * m3(1, 5);
  const double h = m1(1, 0) * m3(1, 0) + m1(1, 1) * m3(1, 1) + m1(1, 2) * m3(1, 2) + m1(1, 3) * m3(1, 3) + m1(1, 4) * m3(1, 4) + m1(1, 5) * m3(1, 5);
  const double i = m1(2, 0) * m3(1, 0) + m1(2, 1) * m3(1, 1) + m1(2, 2) * m3(1, 2) + m1(2, 3) * m3(1, 3) + m1(2, 4) * m3(1, 4) + m1(2, 5) * m3(1, 5);
  const double j = m1(3, 0) * m3(1, 0) + m1(3, 1) * m3(1, 1) + m1(3, 2) * m3(1, 2) + m1(3, 3) * m3(1, 3) + m1(3, 4) * m3(1, 4) + m1(3, 5) * m3(1, 5);
  const double k = m1(4, 0) * m3(1, 0) + m1(4, 1) * m3(1, 1) + m1(4, 2) * m3(1, 2) + m1(4, 3) * m3(1, 3) + m1(4, 4) * m3(1, 4) + m1(4, 5) * m3(1, 5);
  const double l = m1(5, 0) * m3(1, 0) + m1(5, 1) * m3(1, 1) + m1(5, 2) * m3(1, 2) + m1(5, 3) * m3(1, 3) + m1(5, 4) * m3(1, 4) + m1(5, 5) * m3(1, 5);

  const double m = m1(0, 0) * m3(2, 0) + m1(0, 1) * m3(2, 1) + m1(0, 2) * m3(2, 2) + m1(0, 3) * m3(2, 3) + m1(0, 4) * m3(2, 4) + m1(0, 5) * m3(2, 5);
  const double n = m1(1, 0) * m3(2, 0) + m1(1, 1) * m3(2, 1) + m1(1, 2) * m3(2, 2) + m1(1, 3) * m3(2, 3) + m1(1, 4) * m3(2, 4) + m1(1, 5) * m3(2, 5);
  const double o = m1(2, 0) * m3(2, 0) + m1(2, 1) * m3(2, 1) + m1(2, 2) * m3(2, 2) + m1(2, 3) * m3(2, 3) + m1(2, 4) * m3(2, 4) + m1(2, 5) * m3(2, 5);
  const double p = m1(3, 0) * m3(2, 0) + m1(3, 1) * m3(2, 1) + m1(3, 2) * m3(2, 2) + m1(3, 3) * m3(2, 3) + m1(3, 4) * m3(2, 4) + m1(3, 5) * m3(2, 5);
  const double q = m1(4, 0) * m3(2, 0) + m1(4, 1) * m3(2, 1) + m1(4, 2) * m3(2, 2) + m1(4, 3) * m3(2, 3) + m1(4, 4) * m3(2, 4) + m1(4, 5) * m3(2, 5);
  const double r = m1(5, 0) * m3(2, 0) + m1(5, 1) * m3(2, 1) + m1(5, 2) * m3(2, 2) + m1(5, 3) * m3(2, 3) + m1(5, 4) * m3(2, 4) + m1(5, 5) * m3(2, 5);

  const double s = m1(0, 0) * m3(3, 0) + m1(0, 1) * m3(3, 1) + m1(0, 2) * m3(3, 2) + m1(0, 3) * m3(3, 3) + m1(0, 4) * m3(3, 4) + m1(0, 5) * m3(3, 5);
  const double t = m1(1, 0) * m3(3, 0) + m1(1, 1) * m3(3, 1) + m1(1, 2) * m3(3, 2) + m1(1, 3) * m3(3, 3) + m1(1, 4) * m3(3, 4) + m1(1, 5) * m3(3, 5);
  const double u = m1(2, 0) * m3(3, 0) + m1(2, 1) * m3(3, 1) + m1(2, 2) * m3(3, 2) + m1(2, 3) * m3(3, 3) + m1(2, 4) * m3(3, 4) + m1(2, 5) * m3(3, 5);
  const double v = m1(3, 0) * m3(3, 0) + m1(3, 1) * m3(3, 1) + m1(3, 2) * m3(3, 2) + m1(3, 3) * m3(3, 3) + m1(3, 4) * m3(3, 4) + m1(3, 5) * m3(3, 5);
  const double w = m1(4, 0) * m3(3, 0) + m1(4, 1) * m3(3, 1) + m1(4, 2) * m3(3, 2) + m1(4, 3) * m3(3, 3) + m1(4, 4) * m3(3, 4) + m1(4, 5) * m3(3, 5);
  const double x = m1(5, 0) * m3(3, 0) + m1(5, 1) * m3(3, 1) + m1(5, 2) * m3(3, 2) + m1(5, 3) * m3(3, 3) + m1(5, 4) * m3(3, 4) + m1(5, 5) * m3(3, 5);

  const double y = m1(0, 0) * m3(4, 0) + m1(0, 1) * m3(4, 1) + m1(0, 2) * m3(4, 2) + m1(0, 3) * m3(4, 3) + m1(0, 4) * m3(4, 4) + m1(0, 5) * m3(4, 5);
  const double z = m1(1, 0) * m3(4, 0) + m1(1, 1) * m3(4, 1) + m1(1, 2) * m3(4, 2) + m1(1, 3) * m3(4, 3) + m1(1, 4) * m3(4, 4) + m1(1, 5) * m3(4, 5);
  const double A = m1(2, 0) * m3(4, 0) + m1(2, 1) * m3(4, 1) + m1(2, 2) * m3(4, 2) + m1(2, 3) * m3(4, 3) + m1(2, 4) * m3(4, 4) + m1(2, 5) * m3(4, 5);
  const double B = m1(3, 0) * m3(4, 0) + m1(3, 1) * m3(4, 1) + m1(3, 2) * m3(4, 2) + m1(3, 3) * m3(4, 3) + m1(3, 4) * m3(4, 4) + m1(3, 5) * m3(4, 5);
  const double C = m1(4, 0) * m3(4, 0) + m1(4, 1) * m3(4, 1) + m1(4, 2) * m3(4, 2) + m1(4, 3) * m3(4, 3) + m1(4, 4) * m3(4, 4) + m1(4, 5) * m3(4, 5);
  const double D = m1(5, 0) * m3(4, 0) + m1(5, 1) * m3(4, 1) + m1(5, 2) * m3(4, 2) + m1(5, 3) * m3(4, 3) + m1(5, 4) * m3(4, 4) + m1(5, 5) * m3(4, 5);

  const double E = m1(0, 0) * m3(5, 0) + m1(0, 1) * m3(5, 1) + m1(0, 2) * m3(5, 2) + m1(0, 3) * m3(5, 3) + m1(0, 4) * m3(5, 4) + m1(0, 5) * m3(5, 5);
  const double F = m1(1, 0) * m3(5, 0) + m1(1, 1) * m3(5, 1) + m1(1, 2) * m3(5, 2) + m1(1, 3) * m3(5, 3) + m1(1, 4) * m3(5, 4) + m1(1, 5) * m3(5, 5);
  const double G = m1(2, 0) * m3(5, 0) + m1(2, 1) * m3(5, 1) + m1(2, 2) * m3(5, 2) + m1(2, 3) * m3(5, 3) + m1(2, 4) * m3(5, 4) + m1(2, 5) * m3(5, 5);
  const double H = m1(3, 0) * m3(5, 0) + m1(3, 1) * m3(5, 1) + m1(3, 2) * m3(5, 2) + m1(3, 3) * m3(5, 3) + m1(3, 4) * m3(5, 4) + m1(3, 5) * m3(5, 5);
  const double I = m1(4, 0) * m3(5, 0) + m1(4, 1) * m3(5, 1) + m1(4, 2) * m3(5, 2) + m1(4, 3) * m3(5, 3) + m1(4, 4) * m3(5, 4) + m1(4, 5) * m3(5, 5);
  const double J = m1(5, 0) * m3(5, 0) + m1(5, 1) * m3(5, 1) + m1(5, 2) * m3(5, 2) + m1(5, 3) * m3(5, 3) + m1(5, 4) * m3(5, 4) + m1(5, 5) * m3(5, 5);

  Eigen::MatrixXd kewl(6, 6);

  kewl << a, b, c, d, e, f,
      g, h, i, j, k, l,
      m, n, o, p, q, r,
      s, t, u, v, w, x,
      y, z, A, B, C, D,
      E, F, G, H, I, J;

  return kewl;
}

//Time taken: 3435.89ms
Eigen::MatrixXd matrixMultPointerComma(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
{
  const Eigen::MatrixXd m3 = m1 * m2;

  const double *m1P = m1.data();
  const double *m3P = m3.data();

  const double a = *m1P       * *m3P       + *(m1P + 6)  * *(m3P + 6)  + *(m1P + 12) * *(m3P + 12) + *(m1P + 18) * *(m3P + 18) + *(m1P + 24) * *(m3P + 24) + *(m1P + 30) * *(m3P + 30);
  const double b = *(m1P + 1) * *m3P       + *(m1P + 7)  * *(m3P + 6)  + *(m1P + 13) * *(m3P + 12) + *(m1P + 19) * *(m3P + 18) + *(m1P + 25) * *(m3P + 24) + *(m1P + 31) * *(m3P + 30);
  const double c = *(m1P + 2) * *m3P       + *(m1P + 8)  * *(m3P + 6)  + *(m1P + 14) * *(m3P + 12) + *(m1P + 20) * *(m3P + 18) + *(m1P + 26) * *(m3P + 24) + *(m1P + 32) * *(m3P + 30);
  const double d = *(m1P + 3) * *m3P       + *(m1P + 9)  * *(m3P + 6)  + *(m1P + 15) * *(m3P + 12) + *(m1P + 21) * *(m3P + 18) + *(m1P + 27) * *(m3P + 24) + *(m1P + 33) * *(m3P + 30);
  const double e = *(m1P + 4) * *m3P       + *(m1P + 10) * *(m3P + 6)  + *(m1P + 16) * *(m3P + 12) + *(m1P + 22) * *(m3P + 18) + *(m1P + 28) * *(m3P + 24) + *(m1P + 34) * *(m3P + 30);
  const double f = *(m1P + 5) * *m3P       + *(m1P + 11) * *(m3P + 6)  + *(m1P + 17) * *(m3P + 12) + *(m1P + 23) * *(m3P + 18) + *(m1P + 29) * *(m3P + 24) + *(m1P + 35) * *(m3P + 30);

  const double g = *m1P       * *(m3P + 1) + *(m1P + 6)  * *(m3P + 7)  + *(m1P + 12) * *(m3P + 13) + *(m1P + 18) * *(m3P + 19) + *(m1P + 24) * *(m3P + 25) + *(m1P + 30) * *(m3P + 31);
  const double h = *(m1P + 1) * *(m3P + 1) + *(m1P + 7)  * *(m3P + 7)  + *(m1P + 13) * *(m3P + 13) + *(m1P + 19) * *(m3P + 19) + *(m1P + 25) * *(m3P + 25) + *(m1P + 31) * *(m3P + 31);
  const double i = *(m1P + 2) * *(m3P + 1) + *(m1P + 8)  * *(m3P + 7)  + *(m1P + 14) * *(m3P + 13) + *(m1P + 20) * *(m3P + 19) + *(m1P + 26) * *(m3P + 25) + *(m1P + 32) * *(m3P + 31);
  const double j = *(m1P + 3) * *(m3P + 1) + *(m1P + 9)  * *(m3P + 7)  + *(m1P + 15) * *(m3P + 13) + *(m1P + 21) * *(m3P + 19) + *(m1P + 27) * *(m3P + 25) + *(m1P + 33) * *(m3P + 31);
  const double k = *(m1P + 4) * *(m3P + 1) + *(m1P + 10) * *(m3P + 7)  + *(m1P + 16) * *(m3P + 13) + *(m1P + 22) * *(m3P + 19) + *(m1P + 28) * *(m3P + 25) + *(m1P + 34) * *(m3P + 31);
  const double l = *(m1P + 5) * *(m3P + 1) + *(m1P + 11) * *(m3P + 7)  + *(m1P + 17) * *(m3P + 13) + *(m1P + 23) * *(m3P + 19) + *(m1P + 29) * *(m3P + 25) + *(m1P + 35) * *(m3P + 31);

  const double m = *m1P       * *(m3P + 2) + *(m1P + 6)  * *(m3P + 8)  + *(m1P + 12) * *(m3P + 14) + *(m1P + 18) * *(m3P + 20) + *(m1P + 24) * *(m3P + 26) + *(m1P + 30) * *(m3P + 32);
  const double n = *(m1P + 1) * *(m3P + 2) + *(m1P + 7)  * *(m3P + 8)  + *(m1P + 13) * *(m3P + 14) + *(m1P + 19) * *(m3P + 20) + *(m1P + 25) * *(m3P + 26) + *(m1P + 31) * *(m3P + 32);
  const double o = *(m1P + 2) * *(m3P + 2) + *(m1P + 8)  * *(m3P + 8)  + *(m1P + 14) * *(m3P + 14) + *(m1P + 20) * *(m3P + 20) + *(m1P + 26) * *(m3P + 26) + *(m1P + 32) * *(m3P + 32);
  const double p = *(m1P + 3) * *(m3P + 2) + *(m1P + 9)  * *(m3P + 8)  + *(m1P + 15) * *(m3P + 14) + *(m1P + 21) * *(m3P + 20) + *(m1P + 27) * *(m3P + 26) + *(m1P + 33) * *(m3P + 32);
  const double q = *(m1P + 4) * *(m3P + 2) + *(m1P + 10) * *(m3P + 8)  + *(m1P + 16) * *(m3P + 14) + *(m1P + 22) * *(m3P + 20) + *(m1P + 28) * *(m3P + 26) + *(m1P + 34) * *(m3P + 32);
  const double r = *(m1P + 5) * *(m3P + 2) + *(m1P + 11) * *(m3P + 8)  + *(m1P + 17) * *(m3P + 14) + *(m1P + 23) * *(m3P + 20) + *(m1P + 29) * *(m3P + 26) + *(m1P + 35) * *(m3P + 32);

  const double s = *m1P       * *(m3P + 3) + *(m1P + 6)  * *(m3P + 9)  + *(m1P + 12) * *(m3P + 15) + *(m1P + 18) * *(m3P + 21) + *(m1P + 24) * *(m3P + 27) + *(m1P + 30) * *(m3P + 33);
  const double t = *(m1P + 1) * *(m3P + 3) + *(m1P + 7)  * *(m3P + 9)  + *(m1P + 13) * *(m3P + 15) + *(m1P + 19) * *(m3P + 21) + *(m1P + 25) * *(m3P + 27) + *(m1P + 31) * *(m3P + 33);
  const double u = *(m1P + 2) * *(m3P + 3) + *(m1P + 8)  * *(m3P + 9)  + *(m1P + 14) * *(m3P + 15) + *(m1P + 20) * *(m3P + 21) + *(m1P + 26) * *(m3P + 27) + *(m1P + 32) * *(m3P + 33);
  const double v = *(m1P + 3) * *(m3P + 3) + *(m1P + 9)  * *(m3P + 9)  + *(m1P + 15) * *(m3P + 15) + *(m1P + 21) * *(m3P + 21) + *(m1P + 27) * *(m3P + 27) + *(m1P + 33) * *(m3P + 33);
  const double w = *(m1P + 4) * *(m3P + 3) + *(m1P + 10) * *(m3P + 9)  + *(m1P + 16) * *(m3P + 15) + *(m1P + 22) * *(m3P + 21) + *(m1P + 28) * *(m3P + 27) + *(m1P + 34) * *(m3P + 33);
  const double x = *(m1P + 5) * *(m3P + 3) + *(m1P + 11) * *(m3P + 9)  + *(m1P + 17) * *(m3P + 15) + *(m1P + 23) * *(m3P + 21) + *(m1P + 29) * *(m3P + 27) + *(m1P + 35) * *(m3P + 33);

  const double y = *m1P       * *(m3P + 4) + *(m1P + 6)  * *(m3P + 10) + *(m1P + 12) * *(m3P + 16) + *(m1P + 18) * *(m3P + 22) + *(m1P + 24) * *(m3P + 28) + *(m1P + 30) * *(m3P + 34);
  const double z = *(m1P + 1) * *(m3P + 4) + *(m1P + 7)  * *(m3P + 10) + *(m1P + 13) * *(m3P + 16) + *(m1P + 19) * *(m3P + 22) + *(m1P + 25) * *(m3P + 28) + *(m1P + 31) * *(m3P + 34);
  const double A = *(m1P + 2) * *(m3P + 4) + *(m1P + 8)  * *(m3P + 10) + *(m1P + 14) * *(m3P + 16) + *(m1P + 20) * *(m3P + 22) + *(m1P + 26) * *(m3P + 28) + *(m1P + 32) * *(m3P + 34);
  const double B = *(m1P + 3) * *(m3P + 4) + *(m1P + 9)  * *(m3P + 10) + *(m1P + 15) * *(m3P + 16) + *(m1P + 21) * *(m3P + 22) + *(m1P + 27) * *(m3P + 28) + *(m1P + 33) * *(m3P + 34);
  const double C = *(m1P + 4) * *(m3P + 4) + *(m1P + 10) * *(m3P + 10) + *(m1P + 16) * *(m3P + 16) + *(m1P + 22) * *(m3P + 22) + *(m1P + 28) * *(m3P + 28) + *(m1P + 34) * *(m3P + 34);
  const double D = *(m1P + 5) * *(m3P + 4) + *(m1P + 11) * *(m3P + 10) + *(m1P + 17) * *(m3P + 16) + *(m1P + 23) * *(m3P + 22) + *(m1P + 29) * *(m3P + 28) + *(m1P + 35) * *(m3P + 34);

  const double E = *m1P       * *(m3P + 5) + *(m1P + 6)  * *(m3P + 11) + *(m1P + 12) * *(m3P + 17) + *(m1P + 18) * *(m3P + 23) + *(m1P + 24) * *(m3P + 29) + *(m1P + 30) * *(m3P + 35);
  const double F = *(m1P + 1) * *(m3P + 5) + *(m1P + 7)  * *(m3P + 11) + *(m1P + 13) * *(m3P + 17) + *(m1P + 19) * *(m3P + 23) + *(m1P + 25) * *(m3P + 29) + *(m1P + 31) * *(m3P + 35);
  const double G = *(m1P + 2) * *(m3P + 5) + *(m1P + 8)  * *(m3P + 11) + *(m1P + 14) * *(m3P + 17) + *(m1P + 20) * *(m3P + 23) + *(m1P + 26) * *(m3P + 29) + *(m1P + 32) * *(m3P + 35);
  const double H = *(m1P + 3) * *(m3P + 5) + *(m1P + 9)  * *(m3P + 11) + *(m1P + 15) * *(m3P + 17) + *(m1P + 21) * *(m3P + 23) + *(m1P + 27) * *(m3P + 29) + *(m1P + 33) * *(m3P + 35);
  const double I = *(m1P + 4) * *(m3P + 5) + *(m1P + 10) * *(m3P + 11) + *(m1P + 16) * *(m3P + 17) + *(m1P + 22) * *(m3P + 23) + *(m1P + 28) * *(m3P + 29) + *(m1P + 34) * *(m3P + 35);
  const double J = *(m1P + 5) * *(m3P + 5) + *(m1P + 11) * *(m3P + 11) + *(m1P + 17) * *(m3P + 17) + *(m1P + 23) * *(m3P + 23) + *(m1P + 29) * *(m3P + 29) + *(m1P + 35) * *(m3P + 35);

  Eigen::MatrixXd kewl(6, 6);

  kewl << a, b, c, d, e, f,
          g, h, i, j, k, l,
          m, n, o, p, q, r,
          s, t, u, v, w, x,
          y, z, A, B, C, D,
          E, F, G, H, I, J;

  return kewl;
}

//Time taken: 3285.63ms
Eigen::MatrixXd matrixMultPointerCurly(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
{
  const Eigen::MatrixXd m3 = m1 * m2;

  const double *m1P = m1.data();
  const double *m3P = m3.data();

  const double a = *m1P       * *m3P       + *(m1P + 6)  * *(m3P + 6)  + *(m1P + 12) * *(m3P + 12) + *(m1P + 18) * *(m3P + 18) + *(m1P + 24) * *(m3P + 24) + *(m1P + 30) * *(m3P + 30);
  const double b = *(m1P + 1) * *m3P       + *(m1P + 7)  * *(m3P + 6)  + *(m1P + 13) * *(m3P + 12) + *(m1P + 19) * *(m3P + 18) + *(m1P + 25) * *(m3P + 24) + *(m1P + 31) * *(m3P + 30);
  const double c = *(m1P + 2) * *m3P       + *(m1P + 8)  * *(m3P + 6)  + *(m1P + 14) * *(m3P + 12) + *(m1P + 20) * *(m3P + 18) + *(m1P + 26) * *(m3P + 24) + *(m1P + 32) * *(m3P + 30);
  const double d = *(m1P + 3) * *m3P       + *(m1P + 9)  * *(m3P + 6)  + *(m1P + 15) * *(m3P + 12) + *(m1P + 21) * *(m3P + 18) + *(m1P + 27) * *(m3P + 24) + *(m1P + 33) * *(m3P + 30);
  const double e = *(m1P + 4) * *m3P       + *(m1P + 10) * *(m3P + 6)  + *(m1P + 16) * *(m3P + 12) + *(m1P + 22) * *(m3P + 18) + *(m1P + 28) * *(m3P + 24) + *(m1P + 34) * *(m3P + 30);
  const double f = *(m1P + 5) * *m3P       + *(m1P + 11) * *(m3P + 6)  + *(m1P + 17) * *(m3P + 12) + *(m1P + 23) * *(m3P + 18) + *(m1P + 29) * *(m3P + 24) + *(m1P + 35) * *(m3P + 30);

  const double g = *m1P       * *(m3P + 1) + *(m1P + 6)  * *(m3P + 7)  + *(m1P + 12) * *(m3P + 13) + *(m1P + 18) * *(m3P + 19) + *(m1P + 24) * *(m3P + 25) + *(m1P + 30) * *(m3P + 31);
  const double h = *(m1P + 1) * *(m3P + 1) + *(m1P + 7)  * *(m3P + 7)  + *(m1P + 13) * *(m3P + 13) + *(m1P + 19) * *(m3P + 19) + *(m1P + 25) * *(m3P + 25) + *(m1P + 31) * *(m3P + 31);
  const double i = *(m1P + 2) * *(m3P + 1) + *(m1P + 8)  * *(m3P + 7)  + *(m1P + 14) * *(m3P + 13) + *(m1P + 20) * *(m3P + 19) + *(m1P + 26) * *(m3P + 25) + *(m1P + 32) * *(m3P + 31);
  const double j = *(m1P + 3) * *(m3P + 1) + *(m1P + 9)  * *(m3P + 7)  + *(m1P + 15) * *(m3P + 13) + *(m1P + 21) * *(m3P + 19) + *(m1P + 27) * *(m3P + 25) + *(m1P + 33) * *(m3P + 31);
  const double k = *(m1P + 4) * *(m3P + 1) + *(m1P + 10) * *(m3P + 7)  + *(m1P + 16) * *(m3P + 13) + *(m1P + 22) * *(m3P + 19) + *(m1P + 28) * *(m3P + 25) + *(m1P + 34) * *(m3P + 31);
  const double l = *(m1P + 5) * *(m3P + 1) + *(m1P + 11) * *(m3P + 7)  + *(m1P + 17) * *(m3P + 13) + *(m1P + 23) * *(m3P + 19) + *(m1P + 29) * *(m3P + 25) + *(m1P + 35) * *(m3P + 31);

  const double m = *m1P       * *(m3P + 2) + *(m1P + 6)  * *(m3P + 8)  + *(m1P + 12) * *(m3P + 14) + *(m1P + 18) * *(m3P + 20) + *(m1P + 24) * *(m3P + 26) + *(m1P + 30) * *(m3P + 32);
  const double n = *(m1P + 1) * *(m3P + 2) + *(m1P + 7)  * *(m3P + 8)  + *(m1P + 13) * *(m3P + 14) + *(m1P + 19) * *(m3P + 20) + *(m1P + 25) * *(m3P + 26) + *(m1P + 31) * *(m3P + 32);
  const double o = *(m1P + 2) * *(m3P + 2) + *(m1P + 8)  * *(m3P + 8)  + *(m1P + 14) * *(m3P + 14) + *(m1P + 20) * *(m3P + 20) + *(m1P + 26) * *(m3P + 26) + *(m1P + 32) * *(m3P + 32);
  const double p = *(m1P + 3) * *(m3P + 2) + *(m1P + 9)  * *(m3P + 8)  + *(m1P + 15) * *(m3P + 14) + *(m1P + 21) * *(m3P + 20) + *(m1P + 27) * *(m3P + 26) + *(m1P + 33) * *(m3P + 32);
  const double q = *(m1P + 4) * *(m3P + 2) + *(m1P + 10) * *(m3P + 8)  + *(m1P + 16) * *(m3P + 14) + *(m1P + 22) * *(m3P + 20) + *(m1P + 28) * *(m3P + 26) + *(m1P + 34) * *(m3P + 32);
  const double r = *(m1P + 5) * *(m3P + 2) + *(m1P + 11) * *(m3P + 8)  + *(m1P + 17) * *(m3P + 14) + *(m1P + 23) * *(m3P + 20) + *(m1P + 29) * *(m3P + 26) + *(m1P + 35) * *(m3P + 32);

  const double s = *m1P       * *(m3P + 3) + *(m1P + 6)  * *(m3P + 9)  + *(m1P + 12) * *(m3P + 15) + *(m1P + 18) * *(m3P + 21) + *(m1P + 24) * *(m3P + 27) + *(m1P + 30) * *(m3P + 33);
  const double t = *(m1P + 1) * *(m3P + 3) + *(m1P + 7)  * *(m3P + 9)  + *(m1P + 13) * *(m3P + 15) + *(m1P + 19) * *(m3P + 21) + *(m1P + 25) * *(m3P + 27) + *(m1P + 31) * *(m3P + 33);
  const double u = *(m1P + 2) * *(m3P + 3) + *(m1P + 8)  * *(m3P + 9)  + *(m1P + 14) * *(m3P + 15) + *(m1P + 20) * *(m3P + 21) + *(m1P + 26) * *(m3P + 27) + *(m1P + 32) * *(m3P + 33);
  const double v = *(m1P + 3) * *(m3P + 3) + *(m1P + 9)  * *(m3P + 9)  + *(m1P + 15) * *(m3P + 15) + *(m1P + 21) * *(m3P + 21) + *(m1P + 27) * *(m3P + 27) + *(m1P + 33) * *(m3P + 33);
  const double w = *(m1P + 4) * *(m3P + 3) + *(m1P + 10) * *(m3P + 9)  + *(m1P + 16) * *(m3P + 15) + *(m1P + 22) * *(m3P + 21) + *(m1P + 28) * *(m3P + 27) + *(m1P + 34) * *(m3P + 33);
  const double x = *(m1P + 5) * *(m3P + 3) + *(m1P + 11) * *(m3P + 9)  + *(m1P + 17) * *(m3P + 15) + *(m1P + 23) * *(m3P + 21) + *(m1P + 29) * *(m3P + 27) + *(m1P + 35) * *(m3P + 33);

  const double y = *m1P       * *(m3P + 4) + *(m1P + 6)  * *(m3P + 10) + *(m1P + 12) * *(m3P + 16) + *(m1P + 18) * *(m3P + 22) + *(m1P + 24) * *(m3P + 28) + *(m1P + 30) * *(m3P + 34);
  const double z = *(m1P + 1) * *(m3P + 4) + *(m1P + 7)  * *(m3P + 10) + *(m1P + 13) * *(m3P + 16) + *(m1P + 19) * *(m3P + 22) + *(m1P + 25) * *(m3P + 28) + *(m1P + 31) * *(m3P + 34);
  const double A = *(m1P + 2) * *(m3P + 4) + *(m1P + 8)  * *(m3P + 10) + *(m1P + 14) * *(m3P + 16) + *(m1P + 20) * *(m3P + 22) + *(m1P + 26) * *(m3P + 28) + *(m1P + 32) * *(m3P + 34);
  const double B = *(m1P + 3) * *(m3P + 4) + *(m1P + 9)  * *(m3P + 10) + *(m1P + 15) * *(m3P + 16) + *(m1P + 21) * *(m3P + 22) + *(m1P + 27) * *(m3P + 28) + *(m1P + 33) * *(m3P + 34);
  const double C = *(m1P + 4) * *(m3P + 4) + *(m1P + 10) * *(m3P + 10) + *(m1P + 16) * *(m3P + 16) + *(m1P + 22) * *(m3P + 22) + *(m1P + 28) * *(m3P + 28) + *(m1P + 34) * *(m3P + 34);
  const double D = *(m1P + 5) * *(m3P + 4) + *(m1P + 11) * *(m3P + 10) + *(m1P + 17) * *(m3P + 16) + *(m1P + 23) * *(m3P + 22) + *(m1P + 29) * *(m3P + 28) + *(m1P + 35) * *(m3P + 34);

  const double E = *m1P       * *(m3P + 5) + *(m1P + 6)  * *(m3P + 11) + *(m1P + 12) * *(m3P + 17) + *(m1P + 18) * *(m3P + 23) + *(m1P + 24) * *(m3P + 29) + *(m1P + 30) * *(m3P + 35);
  const double F = *(m1P + 1) * *(m3P + 5) + *(m1P + 7)  * *(m3P + 11) + *(m1P + 13) * *(m3P + 17) + *(m1P + 19) * *(m3P + 23) + *(m1P + 25) * *(m3P + 29) + *(m1P + 31) * *(m3P + 35);
  const double G = *(m1P + 2) * *(m3P + 5) + *(m1P + 8)  * *(m3P + 11) + *(m1P + 14) * *(m3P + 17) + *(m1P + 20) * *(m3P + 23) + *(m1P + 26) * *(m3P + 29) + *(m1P + 32) * *(m3P + 35);
  const double H = *(m1P + 3) * *(m3P + 5) + *(m1P + 9)  * *(m3P + 11) + *(m1P + 15) * *(m3P + 17) + *(m1P + 21) * *(m3P + 23) + *(m1P + 27) * *(m3P + 29) + *(m1P + 33) * *(m3P + 35);
  const double I = *(m1P + 4) * *(m3P + 5) + *(m1P + 10) * *(m3P + 11) + *(m1P + 16) * *(m3P + 17) + *(m1P + 22) * *(m3P + 23) + *(m1P + 28) * *(m3P + 29) + *(m1P + 34) * *(m3P + 35);
  const double J = *(m1P + 5) * *(m3P + 5) + *(m1P + 11) * *(m3P + 11) + *(m1P + 17) * *(m3P + 17) + *(m1P + 23) * *(m3P + 23) + *(m1P + 29) * *(m3P + 29) + *(m1P + 35) * *(m3P + 35);

  const Eigen::Matrix<double, 6, 6> kewl {
          {a, b, c, d, e, f},
          {g, h, i, j, k, l},
          {m, n, o, p, q, r},
          {s, t, u, v, w, x},
          {y, z, A, B, C, D},
          {E, F, G, H, I, J},
  };

  return kewl;
}

//Time taken: 457.002ms
ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> rootMatMult(const ROOT::Math::SMatrix<double, 6, 6> &m2, const ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> &m1)
{
  return ROOT::Math::Similarity(m2, m1);
}

//Time taken: 676.414ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoop(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      *(resultPtr + ResultPtrIndex) = *(m1Ptr + rowIndex) * *(m3Ptr + columnIndex) + *(m1Ptr + rowIndex + 6) * *(m3Ptr + columnIndex + 6) + *(m1Ptr + rowIndex + 12) * *(m3Ptr + columnIndex + 12) + *(m1Ptr + rowIndex + 18) * *(m3Ptr + columnIndex + 18) + *(m1Ptr + rowIndex + 24) * *(m3Ptr + columnIndex + 24) + *(m1Ptr + rowIndex + 30) * *(m3Ptr + columnIndex + 30);

      ResultPtrIndex++;
    }
  }

  return result;
}

//Time taken: 541.569ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopTheTriple(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result = Eigen::Matrix<double, 6, 6>::Zero(6, 6);
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        *(resultPtr + ResultPtrIndex) += *(m1Ptr + rowIndex + offset) * *(m3Ptr + columnIndex + offset);
      }

      ResultPtrIndex++;
    }
  }

  return result;
}

//Time taken: 536.414ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopTripleRef(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result = Eigen::Matrix<double, 6, 6>::Zero(6, 6);
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      for (int offset = 0; offset < 31; offset = offset + 6)
      {
        resultData[ResultDataIndex] += m1Data[rowIndex + offset] * m3Data[columnIndex + offset];
      }

      ResultDataIndex++;
    }
  }

  return result;
}

//Time taken: 670.436ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopRef(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;
  int ResultDataIndex = 0;

  const double *m1Data = m1.data();
  const double *m3Data = m3.data();
  double *resultData = result.data();

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      resultData[ResultDataIndex] = m1Data[rowIndex] * m3Data[columnIndex] + m1Data[rowIndex + 6] * m3Data[columnIndex + 6] + m1Data[rowIndex + 12] * m3Data[columnIndex + 12] + m1Data[rowIndex + 18] * m3Data[columnIndex + 18] + m1Data[rowIndex + 24] * m3Data[columnIndex + 24] + m1Data[rowIndex + 30] * m3Data[columnIndex + 30];
      ResultDataIndex++;
    }
  }

  return result;
}

//Time taken: 455.486ms
Eigen::Matrix<double, 6, 6> matrixMultFastLoopAccess(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  const Eigen::Matrix<double, 6, 6> m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;

  for (int rowIndex = 0; rowIndex < 6; rowIndex++)
  {
    for (int columnIndex = 0; columnIndex < 6; columnIndex++)
    {
      result(columnIndex, rowIndex) = m1(rowIndex, 0) * m3(columnIndex, 0) + m1(rowIndex, 1) * m3(columnIndex, 1) + m1(rowIndex, 2) * m3(columnIndex, 2) + m1(rowIndex, 3) * m3(columnIndex, 3) + m1(rowIndex, 4) * m3(columnIndex, 4) + m1(rowIndex, 5) * m3(columnIndex, 5);
    }
  }

  return result;
}

//Time taken: 334.026ms
Eigen::Matrix<double, 6, 6> matrixMultEigen(const Eigen::Matrix<double, 6, 6> &m1, const Eigen::Matrix<double, 6, 6> &m2)
{
  return m1 * m2 * m1.transpose();
}

int main()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  srand(time(0));

  const int ITERATIONS = 10000000;
  double total = 0;

  Eigen::Matrix<double, 6, 6> m1 = Eigen::Matrix<double, 6, 6>::Random(6, 6);
  Eigen::Matrix<double, 6, 6> m2 = Eigen::Matrix<double, 6, 6>::Random(6, 6);

  double a[36];
  std::vector<double> v(21);

   for (int i = 0; i < 36; ++i)
    a[i] = double(rand());

  for (int i = 0; i < 21; ++i)
    v[i] = double(rand());

  ROOT::Math::SMatrix<double, 6> sm1(a, 36);
  ROOT::Math::SMatrix<double, 6, 6, ROOT::Math::MatRepSym<double, 6>> sm2(v.begin(), v.end());

  auto sampleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += m1(0, 0);
  }

  auto sampleT2 = high_resolution_clock::now();
  duration<double, std::milli> sampleTime = sampleT2 - sampleT1;

  auto manualT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultManual(m1, m2)(0, 0);
  }

  auto manualT2 = high_resolution_clock::now();
  duration<double, std::milli> manualTime = manualT2 - manualT1;
  std::cout << "matrixMultManual: " << manualTime.count() - sampleTime.count() << "ms\n\n";

    auto PointerCommaT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultPointerComma(m1, m2)(0, 0);
  }

  auto PointerCommaT2 = high_resolution_clock::now();
  duration<double, std::milli> PointerCommaTime = PointerCommaT2 - PointerCommaT1;
  std::cout << "matrixMultPointerComma: " << PointerCommaTime.count() - sampleTime.count() << "ms\n\n";

  auto PointerCurlyT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultPointerCurly(m1, m2)(0, 0);
  }

  auto PointerCurlyT2 = high_resolution_clock::now();
  duration<double, std::milli> PointerCurlyTime = PointerCurlyT2 - PointerCurlyT1;
  std::cout << "matrixMultPointerCurly: " << PointerCurlyTime.count() - sampleTime.count() << "ms\n\n";

  auto loopT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoop(m1, m2)(0, 0);
  }

  auto loopT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTime = loopT2 - loopT1;
  std::cout << "matrixMultFastLoop: " << loopTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTheTripleT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopTheTriple(m1, m2)(0, 0);
  }

  auto loopTheTripleT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTheTripleTime = loopTheTripleT2 - loopTheTripleT1;
  std::cout << "matrixMultFastLoopTheTriple: " << loopTheTripleTime.count() - sampleTime.count() << "ms\n\n";

  auto loopAccessT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopAccess(m1, m2)(0, 0);
  }

  auto loopAccessT2 = high_resolution_clock::now();
  duration<double, std::milli> loopAccessTime = loopAccessT2 - loopAccessT1;
  std::cout << "matrixMultFastLoopAccess: " << loopAccessTime.count() - sampleTime.count() << "ms\n\n";

  auto loopRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopRef(m1, m2)(0, 0);
  }

  auto loopRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopRefTime = loopRefT2 - loopRefT1;
  std::cout << "matrixMultFastLoopRef: " << loopRefTime.count() - sampleTime.count() << "ms\n\n";

  auto loopTripleRefT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultFastLoopTripleRef(m1, m2)(0, 0);
  }

  auto loopTripleRefT2 = high_resolution_clock::now();
  duration<double, std::milli> loopTripleRefTime = loopTripleRefT2 - loopTripleRefT1;
  std::cout << "matrixMultFastLoopTripleRef: " << loopTripleRefTime.count() - sampleTime.count() << "ms\n\n";

  auto rootT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    sm1(0, 0) = (double)rand();
    total += rootMatMult(sm1, sm2)(0, 0);
  }

  auto rootT2 = high_resolution_clock::now();
  duration<double, std::milli> rootTime = rootT2 - rootT1;
  std::cout << "rootMatMult: " << rootTime.count() - sampleTime.count() << "ms\n\n";

  auto oldT1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    m1(0, 0) = (double)rand();
    total += matrixMultEigen(m1, m2)(0, 0);
  }

  auto oldT2 = high_resolution_clock::now();
  duration<double, std::milli> oldTime = oldT2 - oldT1;
  std::cout << "matrixMultEigen: " << oldTime.count() - sampleTime.count() << "ms\n\n";

  return 0;
}
