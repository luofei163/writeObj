//
//  main.cpp
//  cplusplus_test
//
//  Created by luofei on 12/6/15.
//  Copyright © 2015 luofei. All rights reserved.
//

# include <cstdlib>
//# include <iostream>
//# include <iomanip>
//# include <fstream>
//# include <vector>
//# include <stdlib.h>
//# include <math.h>
#include "obj_create.hpp"
using namespace std;

//# include "obj_io.hpp"


int main ( int argc, char *argv[] )

{
//
    
    Obj *o = new Obj();
    vector<Point3D> vertex;
//    vertex
//    for (vector<Point3D>::iterator i=vertex.begin(); i != vertex.end(); i++) {
//        cout << (*i).x << " " <<  (*i).y << " " <<  (*i).z << endl;
//
    string pointFile = "/Users/luofei/Desktop/tmp/writeObj/scanface3_texture.points";
    o->storeVertex(vertex, pointFile);
    
    
   vector<vector<int>> ve = o->vertexToArray(vertex);
  
//vectorArrayPrint(ve);
//   vector<vector<int>> v =  getFacesVector(ve, 664, 1080);
//    vectorArrayPrint(v);
//    cout << "size of " << ve.size();
    vector<vector<int>> v =  o->getFacesVector(ve, 664, 1080);
//  o->vectorArrayPrint(v);
    o->new_obj_write("/tmp/luofei.obj",vertex, ve, v);
//    delete [] o;
    return 0;
}






