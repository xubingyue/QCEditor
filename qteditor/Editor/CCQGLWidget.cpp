#include "CCQGLWidget.h"
#include "qevent.h"


CCQGLWidget::CCQGLWidget(int width, int height, QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer), parent)
{
    resize(width, height);
}

CCQGLWidget::~CCQGLWidget()
{
}
void CCQGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    QGLWidget::mouseMoveEvent(event);
}

void CCQGLWidget::mousePressEvent(QMouseEvent *event)
{
    QGLWidget::mousePressEvent(event);
}

void CCQGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QGLWidget::mouseReleaseEvent(event);
}

void CCQGLWidget::wheelEvent(QWheelEvent *event)
{
	QGLWidget::wheelEvent(event);
}

void CCQGLWidget::keyPressEvent(QKeyEvent *event)
{
	QGLWidget::keyPressEvent(event);
}

void CCQGLWidget::keyReleaseEvent(QKeyEvent *event)
{
	QGLWidget::keyReleaseEvent(event);
}

void CCQGLWidget::paintEvent(QPaintEvent* event)
{
	QGLWidget::paintEvent(event);

	makeCurrent();
	cocos2d::Director::getInstance()->mainLoop();
	swapBuffers();
}

void CCQGLWidget::resizeEvent(QResizeEvent* evnet)
{
	const QSize& sz = evnet->size();
	GLView* v = cocos2d::Director::getInstance()->getOpenGLView();
	if (v)
		v->setFrameSize(sz.width(), sz.height());
}
