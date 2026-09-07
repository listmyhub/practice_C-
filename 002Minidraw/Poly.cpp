#include "Poly.h"
#include"viewwidget.h"
#include<QDebug>
Poly::Poly(){
};
Poly::~Poly(){
	qDebug() << "Poly析构完毕";
};
QVector<QPoint >  Poly::caculate_vertices(QPoint center, double radius, int side_poly) {
	QVector<QPoint > ver;
	for (int i = 0; i < side_poly; i++) {
		double angle = 2 * M_PI * i / side_poly - M_PI / 2;
		int x = center.x() + radius * cos(angle);
		int y = center.y() + radius * sin(angle);
		ver.push_back(QPoint(x, y));
	}
	return ver;
}
void Poly::set_vertices(QVector<QPoint>vertices) {
	     this->vertices = vertices;
}
void Poly::Draw(QPainter& painter) {
	painter.drawPolygon(QPolygon(vertices));
}