// SWIG file Description.i

%{
#include "Description.hxx"
%}

%include Description_doc.i

%template(StringCollection) OT::Collection<OT::String>;
%template(StringPersistentCollection) OT::PersistentCollection<OT::String>;

%typemap(in) const OT::Description & ($1_basetype temp) {
  if (! SWIG_IsOK(SWIG_ConvertPtr($input, (void **) &$1, $1_descriptor, 0))) {
    try {
      temp = OT::convert<OT::_PySequence_,OT::Description>( $input );
      $1 = &temp;
    } catch (OT::InvalidArgumentException & ex) {
      SWIG_exception(SWIG_TypeError, "Object passed as argument is not convertible to a Description");
    }
  }
}

%typemap(typecheck,precedence=SWIG_TYPECHECK_POINTER) const OT::Description & {
  $1 = SWIG_IsOK(SWIG_ConvertPtr($input, NULL, $1_descriptor, 0)) ||
       OT::isAPythonSequenceOf<OT::_PyString_>( $input );
}

%include Description.hxx

namespace OT {  

%extend Description {

Description(const Description & other) { return new OT::Description(other); }

Description(PyObject * pyObj)
{
 OT::Pointer<OT::Collection<OT::String> > p_coll =  OT::buildCollectionFromPySequence<OT::String>( pyObj );
 return new OT::Description( *p_coll );
}

OT_COLLECTION_GETITEM(OT::Description, OT::String)
OT_COLLECTION_SETITEM(OT::Description, OT::String)

} // Description
} // OT
