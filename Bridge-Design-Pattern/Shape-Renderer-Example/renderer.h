#pragma once

class Renderer{
    public:
        virtual void render_shape() = 0;
};

class VectorRenderer : public Renderer{
    public:
        VectorRenderer(){}
        void render_shape() override;
};


class RasterRenderer : public Renderer{
    public:
        RasterRenderer(){}
        void render_shape() override;
};