#include <iostream>
#include <chrono>
#include <thread>
#include "Eigen/Dense"

Eigen::MatrixXd matrixMultDraft(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
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

Eigen::MatrixXd matrixMultFastComma(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
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

Eigen::MatrixXd matrixMultFastCurly(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
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

Eigen::MatrixXd matrixMultFastLoop(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
{
  const Eigen::MatrixXd m3 = m1 * m2;
  Eigen::Matrix<double, 6, 6> result;
  int ResultPtrIndex = 0;

  const double *m1Ptr = m1.data();
  const double *m3Ptr = m3.data();
  double *resultPtr = result.data();
  

  for(int rowIndex = 0; rowIndex < 6; rowIndex++) {
    for(int columnIndex = 0; columnIndex < 6; columnIndex++) {
      *(resultPtr + ResultPtrIndex) = *(m1Ptr + rowIndex) * *(m3Ptr + columnIndex) + *(m1Ptr + rowIndex + 6)  * *(m3Ptr + columnIndex + 6) + *(m1Ptr + rowIndex + 12) * *(m3Ptr + columnIndex + 12) 
      + *(m1Ptr + rowIndex + 18) * *(m3Ptr + columnIndex + 18) + *(m1Ptr + rowIndex + 24) * *(m3Ptr + columnIndex + 24) + *(m1Ptr + rowIndex + 30) * *(m3Ptr + columnIndex + 30);
      ResultPtrIndex++;
    }
  }

  return result;
}

Eigen::MatrixXd matrixMultOld(const Eigen::MatrixXd &m1, const Eigen::MatrixXd &m2)
{
  return m1 * m2 * m1.transpose();
}

int main()
{
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  const int ITERATIONS = 10000000;

  Eigen::MatrixXd kewl3 = Eigen::MatrixXd::Random(6, 6);
  Eigen::MatrixXd kewl4 = Eigen::MatrixXd::Random(6, 6);

  //Eigen::MatrixXd arr1 [ITERATIONS];
  //Eigen::MatrixXd arr2 [ITERATIONS];

   /* for(int i = 0; i < ITERATIONS; i++) {
    arr1[i] = Eigen::MatrixXd::Random(6, 6);
    arr2[i] = Eigen::MatrixXd::Random(6, 6);
  } */

   auto t5 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    //matrixMultDraft(arr1[i], arr2[i]);
    matrixMultDraft(kewl3, kewl4);
  }

  auto t6 = high_resolution_clock::now();

  duration<double, std::milli> ms_double3 = t6 - t5;

  std::cout << "Draft:";
  std::cout << ms_double3.count() << "ms\n";
  std::cout << "\n\n";

  auto t1 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    //matrixMultFastComma(arr1[i], arr2[i]);
    matrixMultFastComma(kewl3, kewl4);
  }

  auto t2 = high_resolution_clock::now();

  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << "Comma:";
  std::cout << ms_double.count() << "ms\n";
  std::cout << "\n\n";

  auto t7 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    //matrixMultFastCurly(arr1[i], arr2[i]);
    matrixMultFastCurly(kewl3, kewl4);
  }

  auto t8 = high_resolution_clock::now();

  duration<double, std::milli> ms_double4 = t8 - t7;

  std::cout << "Curly:";
  std::cout << ms_double4.count() << "ms\n";
  std::cout << "\n\n";

  auto t9 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    //matrixMultFastLoop(arr1[i], arr2[i]);
    matrixMultFastLoop(kewl3, kewl4);
  }

  auto t10 = high_resolution_clock::now();

  duration<double, std::milli> ms_double5 = t10 - t9;

  std::cout << "Loop:";
  std::cout << ms_double5.count() << "ms\n";
  std::cout << "\n\n";

  auto t3 = high_resolution_clock::now();

  for (int i = 0; i < ITERATIONS; i++)
  {
    //matrixMultOld(arr1[i], arr2[i]);
    matrixMultOld(kewl3, kewl4);
  }

  auto t4 = high_resolution_clock::now();

  duration<double, std::milli> ms_double2 = t4 - t3;
  std::cout << "Old:";
  std::cout << ms_double2.count() << "ms\n"; 

  return 0;
}