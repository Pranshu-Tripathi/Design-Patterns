#include "neuron.h"
#include "neuron_layer.h"
#include "neuron_connection_algo.h"
#include <iostream>


int main()
{
    Neuron n1, n2;
    n1.connectTo(n2);

    NeuronLayer layer1{5};
    NeuronLayer layer2{3};
    /**
     * Now if we want to connect we have four possible options
     * 1. neuron to layer
     * 2. layer to neuron
     * 3. layer to layer
     * 4. neuron to neuron
     * We don't specifically want to implement all of these cases.
     * So here we use CRTP to implement the connectTo Function.
    */
    layer1.connectTo(layer2);
    n1.connectTo(layer1);
    layer2.connectTo(n2);
    
    std::cout << n1 << n2 << layer1 << layer2;
    return 0;
}