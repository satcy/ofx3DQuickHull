//
//  ofx3DQuickHull.h
//  ofx3DQuickHull
//
//  Created by satcy on 2016/12/01.
//
//
#pragma once

#include "ofMesh.h"

namespace ofx3DQuickHull {
    ofMesh quickhull3d(vector<ofVec3f> & _vertices);
}
