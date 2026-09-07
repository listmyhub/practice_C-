#include"idwwarp.h"
#include"widget.h"
#include<QDebug>

QImage idwwarp::warp(QImage& src, QVector<QPointF>& srcpts, QVector<QPointF>& dstpts) {
    qDebug() << src.width() << src.height();
    qDebug() << "原点数量" << srcpts.size();
    qDebug() << "目标点数量" << dstpts.size();
    for (int i = 0;i < srcpts.size();i++) {
        qDebug() << srcpts[i].x() << " " << srcpts[i].y();
        qDebug() << dstpts[i].x() << " " << dstpts[i].y();
    }
    int w = src.width();
    int h = src.height();
    QImage dst(w, h, src.format());
    dst.fill(Qt::lightGray);
    int n = srcpts.size();
    const double eps = 1e-8;
    double power = 2.0;
    for (int u = 0;u < w;u++) {
        for (int v = 0;v < h;v++) {
            double sum_x = 0.0;
            double sum_y = 0.0;
            double sum_w = 0.0;
            for (int N = 0;N < n;N++) {
                double dx = u - dstpts[N].x();
                double dy = v - dstpts[N].y();
                double d = sqrt(dx * dx + dy * dy);
                if (d < eps) {
                    d = eps;
                }
                double weight = 1.0 / pow(d, power);
                sum_w += weight;
                sum_x += weight * (dstpts[N].x() - srcpts[N].x());
                sum_y += weight * (dstpts[N].y() - srcpts[N].y());
            }
            if (sum_w < eps) {
                continue;
            }
            float x = sum_x / sum_w;
            float y = sum_y / sum_w;
            dst.setPixel(u, v, bilinearInterp(src, u -x, v -y));
        }
    }
    return dst;
}