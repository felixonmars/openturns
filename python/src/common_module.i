// SWIG file common_module.i

%module(package="openturns", docstring="Utility classes.") common
//%feature("autodoc","1");

%{
#include "OTconfig.hxx"
#include "OTCommon.hxx"
%}

%include typemaps.i
%include OTtypes.i
%include OTexceptions.i
%include std_vector.i

/* Base/Common */
%include Memory.i
%include Object.i
%include PersistentObject.i
%include SharedPointer.i
%include Pointer.i
%include InterfaceObject.i
%include TypedInterfaceObject.i
%include TypedCollectionInterfaceObject.i
%include Study.i
%include StorageManager.i
//%include BinaryStorageManager.i
#ifdef OPENTURNS_HAVE_LIBXML2
%include XMLStorageManager.i
#endif
%include TTY.i
%include Log.i
%include Path.i
%include Catalog.i
%include ResourceMap.i
%include ComparisonOperatorImplementation.i
%include ComparisonOperator.i
%include Equal.i
%include Greater.i
%include GreaterOrEqual.i
%include Less.i
%include LessOrEqual.i
%include PlatformInfo.i

/* At last we include template definitions */
%include BaseCommonTemplateDefs.i
