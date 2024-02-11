#include "neuron.h"
#include <iostream>

Neuron::Neuron():
    id(neuron_id++)
{
}

Neuron::~Neuron()
{
}

// void Neuron::connectTo(Neuron& other)
// {
//     addOutgoingConnection(other);
//     other.addIncomingConnection(*this);
// }

void Neuron::addIncomingConnection(Neuron& other)
{
    in.push_back(std::make_shared<Neuron>(other));
}

void Neuron::addOutgoingConnection(Neuron& other)
{
    out.push_back(std::make_shared<Neuron>(other));
}

std::ostream& operator<<(std::ostream& os, const Neuron& obj)
{
    os << "Neuron " << obj.id << "\n";
    os << "Incoming connections: " << obj.in.size() << " : ";
    for (auto& n : obj.in)
    {
        os << n->id << " ";
    }
    os << "\n";
    os << "Outgoing connections: " << obj.out.size() << " : ";
    for (auto& n : obj.out)
    {
        os << n->id << " ";
    }
    os << "\n";
    return os;
}
