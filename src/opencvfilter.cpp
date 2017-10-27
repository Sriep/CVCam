#include "opencvrunnable.h"
#include "opencvfilter.h"
#include <QDebug>

OpenCVFilter::OpenCVFilter()
{
}

UnchangedVFilter::UnchangedVFilter()
{
}
ToonVFilter::ToonVFilter()
{
}
SketchVFilter::SketchVFilter()
{
}
EvilVFilter::EvilVFilter()
{
}
AlienVFilter::AlienVFilter()
{
}

QVideoFilterRunnable* UnchangedVFilter::createFilterRunnable()
{
    qDebug() << "return UnchangedVFilter";
    return new UnchangedVFRunnable(this);
}
QVideoFilterRunnable* ToonVFilter::createFilterRunnable()
{
    qDebug() << "return ToonVFilter";
    return new SketchVFRunnable(this);
}
QVideoFilterRunnable* SketchVFilter::createFilterRunnable()
{
    qDebug() << "return SketchVFilter";
    return new ToonVFRunnable(this);
}
QVideoFilterRunnable* EvilVFilter::createFilterRunnable()
{
    qDebug() << "return EvilVFilter";
    return new EvilVFRunnable(this);
}
QVideoFilterRunnable* AlienVFilter::createFilterRunnable()
{
    qDebug() << "return EvilVFilter";
    return new AlianVFRunnable(this);
}

