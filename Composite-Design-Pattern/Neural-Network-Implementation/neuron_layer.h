#pragma once
#include "neuron.h"
#include "neuron_connection_algo.h"
#include <vector>

/* 
   This is a bad practice but just for 
   state of the art implementation we can ignore this
   for now. This is bad because STL don't have virtual
   destructor and we can't delete the derived class
*/
class NeuronLayer: public std::vector<Neuron> , public NeuronConnectionAlgo<NeuronLayer>
{
    public:
        NeuronLayer(int count) {
            while(count --> 0) {
                emplace_back(Neuron{});
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const NeuronLayer& obj) {
            for (auto& n : obj) {
                os << n;
            }
            return os;
        }
};