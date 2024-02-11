#pragma once
#include "neuron_connection_algo.h"
#include <vector>
#include <memory>
#include <iostream>

static int neuron_id = 1;

class Neuron : public NeuronConnectionAlgo<Neuron>
{
    public:
        Neuron();
        ~Neuron();
        // void connectTo(Neuron& other);
        Neuron* begin() {return this;}
        Neuron* end() {return this + 1;}
        void addIncomingConnection(Neuron& other);
        void addOutgoingConnection(Neuron& other);
    
    protected:
        friend std::ostream& operator<<(std::ostream& os, const Neuron& obj);

    private:
        std::vector<std::shared_ptr<Neuron> > in, out;
        unsigned int id;
};