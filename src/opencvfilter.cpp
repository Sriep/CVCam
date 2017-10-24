#include "opencvrunnable.h"
#include "opencvfilter.h"

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
    return new SketchVFRunnable(this);
}
QVideoFilterRunnable* ToonVFilter::createFilterRunnable()
{
    return new SketchVFRunnable(this);
}
QVideoFilterRunnable* SketchVFilter::createFilterRunnable()
{
    return new SketchVFRunnable(this);
}
QVideoFilterRunnable* EvilVFilter::createFilterRunnable()
{
    return new SketchVFRunnable(this);
}
QVideoFilterRunnable* AlienVFilter::createFilterRunnable()
{
    return new SketchVFRunnable(this);
}

