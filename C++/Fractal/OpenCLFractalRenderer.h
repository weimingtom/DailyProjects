#ifndef OPENCL_FRACTAL_RENDERER_H
#define OPENCL_FRACTAL_RENDERER_H

#include <memory>

#include "FractalRenderer.h"
#include "ImageGenerater_OpenCL.h"

class OpenCLFractalRenderer : public IFractalRenderer
{
public:
    OpenCLFractalRenderer(int width, int height)
        : mMandelbrot(std::make_unique<ImageGenerater_OpenCL>("mandelbrot.cl", "main", width, height)),
        mJulia(std::make_unique<ImageGenerater_OpenCL>("julia.cl", "main", width, height))
    {
    }

    virtual void ResetBuffer(int width, int height)
    {
        mMandelbrot = std::make_unique<ImageGenerater_OpenCL>("mandelbrot.cl", "main", width, height);
        mJulia = std::make_unique<ImageGenerater_OpenCL>("julia.cl", "main", width, height);
    }

    virtual void RenderMandelbrot(
        int *buffer, int width, int height, int maxIteration,
        TFloat minX, TFloat maxX, TFloat minY, TFloat maxY) override
    {
        mMandelbrot->Run(buffer, maxIteration, minX, maxX, minY, maxY);
    }

    virtual void RenderJuliaSet(
        int *buffer, int width, int height, int maxIteration, TFloat cx, TFloat cy,
        TFloat minX, TFloat maxX, TFloat minY, TFloat maxY) override
    {
        mJulia->Run(buffer, maxIteration, cx, cy, minX, maxX, minY, maxY);
    }

private:
    std::unique_ptr<ImageGenerater_OpenCL> mMandelbrot;
    std::unique_ptr<ImageGenerater_OpenCL> mJulia;
};

#endif