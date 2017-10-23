#ifndef OPENCVFILTER_H
#define OPENCVFILTER_H
#include <QAbstractVideoFilter>

class QVideoFilterRunnable;
class OpenCVFilter : public QAbstractVideoFilter
{
    Q_OBJECT
public:
    OpenCVFilter();
signals:
    void finished();

};

class SketchVFilter : public OpenCVFilter
{
public:
    SketchVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};

#endif // OPENCVFILTER_H
