#include "neuron_connection_algo.h"
#include "neuron.h"
#include "neuron_layer.h"

template <typename Self>
template <typename T>
void NeuronConnectionAlgo<Self>::connectTo(T& other)
{
    for (Neuron& from : *static_cast<Self*>(this))
    {
        for (Neuron& to : other)
        {
            from.addOutgoingConnection(to);
            to.addIncomingConnection(from);
        }
    }
}
// Explicit Instantiation
template void NeuronConnectionAlgo<Neuron>::connectTo(Neuron&);
template void NeuronConnectionAlgo<NeuronLayer>::connectTo(Neuron&);
template void NeuronConnectionAlgo<NeuronLayer>::connectTo(NeuronLayer&);
template void NeuronConnectionAlgo<Neuron>::connectTo(NeuronLayer&); 
