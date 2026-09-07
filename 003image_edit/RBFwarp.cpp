#include "RBFwarp.h"
#include <Eigen/Dense>
#include <QDebug>
using namespace Eigen;

double RBFwarp::basefunc(double r) {
    // Thin plate spline kernel
    if (r < 1e-8) 
        return 0;
    return r * r * log(r);
}

QImage RBFwarp::warp(QImage& src, QVector<QPointF>& srcpts,
    QVector<QPointF>& dstpts) {
    int w = src.width(); //srcpts=srcpts+stable_point;
    //dstpts=dstpts+stable_point;
    int h = src.height();
    QImage dst(w, h, src.format());
    dst.fill(Qt::lightGray);

    int n = srcpts.size();
    const double eps = 1e-8;

    // Build the matrix for RBF interpolation
    // Size: (n+3) x (n+3)
    MatrixXd M(n + 3, n + 3);
    M.setZero();

    // Fill the RBF part
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = srcpts[j].x() - srcpts[i].x();  // Use source points here
            double dy = srcpts[j].y() - srcpts[i].y();
            double r = sqrt(dx * dx + dy * dy);
            M(i, j) = basefunc(r);
        }
        M(i, n) = 1.0;
        M(i, n + 1) = srcpts[i].x();
        M(i, n + 2) = srcpts[i].y();
        M(n, i) = 1.0;
        M(n + 1, i) = srcpts[i].x();
        M(n + 2, i) = srcpts[i].y();
    }
    // Build right-hand side vectors
    MatrixXd bx(n + 3, 1);
    MatrixXd by(n + 3, 1);
    for (int i = 0; i < n; i++) {
        bx(i, 0) = dstpts[i].x() - srcpts[i].x();  // Map source to destination x
        by(i, 0) = dstpts[i].y() - srcpts[i].y();  // Map source to destination y
    }
    bx(n, 0) = 0;
    bx(n + 1, 0) = 0;
    bx(n + 2, 0) = 0;
    by(n, 0) = 0;
    by(n + 1, 0) = 0;
    by(n + 2, 0) = 0;
    // Solve the linear systems
    MatrixXd weights_x = M.colPivHouseholderQr().solve(bx);
    MatrixXd weights_y = M.colPivHouseholderQr().solve(by);
    // Warp the image
    for (int u = 0; u < w; u++) {
        for (int v = 0; v < h; v++) {
            // Build evaluation vector for pixel (u, v)
            MatrixXd f(1,n + 3);

            for (int l = 0; l < n; l++) {
                double dx = u - srcpts[l].x();
                double dy = v - srcpts[l].y();
                double r = sqrt(dx * dx + dy * dy);
                f(0,l) = basefunc(r);
            }

            // Affine part
            f(0,n) = 1.0;
            f(0,n + 1) = u;
            f(0,n + 2) = v;

            // Compute corresponding source coordinate
            double src_x = (f*weights_x)(0,0);
            double src_y =( f * weights_y)(0, 0);
            // Sample from source image
            if (u+src_x>= 0 && u+src_x<w && v+src_y>= 0 &&v+src_y< h) {
                dst.setPixel(u+src_x, v+src_y, bilinearInterp(src, u, v));
            }
        }
    }
    return dst;
}