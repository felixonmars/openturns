// SWIG file ODESolver.i

OTAutodoc(ODESolver)

%{
#include "ODESolver.hxx"
%}

OTTypedInterfaceObjectHelper(ODESolver)

%include ODESolver.hxx
namespace OT { %extend ODESolver { ODESolver(const ODESolver & other) { return new OT::ODESolver(other); } } }
