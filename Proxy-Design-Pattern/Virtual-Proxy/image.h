#pragma once

class Image {
    public:
        virtual void draw() = 0;
        virtual ~Image() = default;
};