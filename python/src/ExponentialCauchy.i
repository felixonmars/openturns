// SWIG file ExponentialCauchy.i

%{
#include "ExponentialCauchy.hxx"
%}

%include ExponentialCauchy_doc.i

%include ExponentialCauchy.hxx
namespace OT { %extend ExponentialCauchy { ExponentialCauchy(const ExponentialCauchy & other) { return new OT::ExponentialCauchy(other); } } }
