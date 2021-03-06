/*
	Global ADT Header File
	Call this when you need access to an ADT file.
*/
#ifndef MODEL_ADT_H
#define MODEL_ADT_H

#include "MPQ.h"

// File Formats
#include "Models\Model_ADT_v18.h"

// --== Primary ADT Class ==--
// Store Data, and Add Functions.
template <class ADTVersion>
class Model_ADT : public cModelBase
{
public:
	// Constructor
	Model_ADT<ADTVersion>() {};
};


#endif