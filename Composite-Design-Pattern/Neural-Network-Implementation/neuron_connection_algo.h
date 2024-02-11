#pragma once

template <typename Self>
class NeuronConnectionAlgo
{
    public:
        NeuronConnectionAlgo() = default;
        ~NeuronConnectionAlgo() = default;
        template <typename T> void connectTo(T& other);
};
