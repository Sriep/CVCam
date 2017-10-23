#include "opencvrunnable.h"
#include "opencvfilter.h"

OpenCVFilter::OpenCVFilter()
{
}

SketchVFilter::SketchVFilter()
{
}

QVideoFilterRunnable* SketchVFilter::createFilterRunnable()
{
    return new SketchVFRunnable(this);
}

