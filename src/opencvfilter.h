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
    void finished(QObject* result);

};

class UnchangedVFilter : public OpenCVFilter
{
public:
    UnchangedVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};

class ToonVFilter : public OpenCVFilter
{
public:
    ToonVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};

class SketchVFilter : public OpenCVFilter
{
public:
    SketchVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};

class EvilVFilter : public OpenCVFilter
{
public:
    EvilVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};

class AlienVFilter : public OpenCVFilter
{
public:
    AlienVFilter();
    virtual QVideoFilterRunnable* createFilterRunnable();
};


#endif // OPENCVFILTER_H
