#include <iostream>
#include <sstream>

#include "rtree.h"
#include "gmsh.h"
#include "Context.h"
#include "GmshMessage.h"

#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

#include "MVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MVertexRTree.h"

#ifndef Periodicity_INCLUDED
#define Periodicity_INCLUDED

void getElementEdgeNodesCoord(const int elementType,
                                            std::vector<std::size_t> & nodeTags,
                                            std::vector<double> & coord,
                                            std::size_t & numElements,
                                            const int tag = -1,
                                            const bool primary = false);

void getElementFaceNodes(const int elementType,
                                        const int faceType,
                                        std::vector<std::size_t> & nodeTags,
                                        std::vector<double> & coord,
                                        const int tag = -1,
                                        const bool primary = false);


void getFullPeriodicKeys(
  GEntity *ge,
  const int elementType, const std::string &fsName,int &order, 
  int &numComponents, const int tag, int &tagMaster, const int dim,
  std::vector<int> &typeKeys, std::vector<int> &typeKeysMaster,
  std::vector<std::size_t> &entityKeys,
  std::vector<std::size_t> &entityKeysMaster, 
  std::vector<double> &coord,
  std::vector<double> &coordMaster, 
  std::vector<int> &orientationSign,
  const bool returnCoord);


#endif // Periodicity_INCLUDED