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
//    string filename;
//    
////    timestamp ( );
//    cout << "\n";
//    cout << "OBJ_IO_PRB:\n";
//    cout << "  C++ version\n";
//    cout << "  Test the OBJ_IO library.\n";
//
//    filename = "cube.obj";
//    test01 ( filename );
//    
//    filename = "cube.obj";
//    //test02 ( filename );
//    
//    filename = "cube_normals.obj";
//    test03  ( filename );
//    
//    filename = "cube_no_normals.obj";
    //test04 ( filename );
//    
//    filename = "/tmp/luofei_cube.obj";
//    test03 (filename);
    //
    //  Terminate.
    //
//    cout << "\n";
//    cout << "OBJ_IO_PRB:\n";
//    cout << "  Normal end of execution.\n";
//    cout << "\n";
    
//    timestamp ( );
    
//    double (*node_xyz)[5];
//    double b[][4]={
//        {1.0,2.0,3.0,4.0},
//        {5.0,6.0,7.0,8.0},
//        {9.0,10.0,11.0,12.0}
//    };
//    node_xyz = b;
//    countFace(b,3,4);
//    getFaces(b,3,4);
    
//    vector<vector<int>> it;

//    it.resize(size);
//    for (int i=0; i<size; i++) {
//        it[i].resize(5);
//    }
//    
//     vector<int> row1 = {1,2,3,4,5};
//     vector<int> row2 = {7,8,9,10,11};
//     vector<int> row3 = {12,13,14,15,16};
//     vector<int> row4 = {17,18,19,20,21};
//     vector<int> row5 = {22,23,24,25,26};
//     vector<int> row6 = {27,28,29,30,31};
//    cout <<"it f = " <<  it.size()<<endl;
//
//    it.push_back(row1);
//    it.push_back(row2);
//    it.push_back(row3);
//    it.push_back(row4);
//    it.push_back(row5);
//    it.push_back(row6);
//    
//    cout << it.size() <<endl;
//    vectorArrayPrint(it);
//
//    
//    vector<vector<int>> test;
//    test = getFacesVector(it,6,5);
//    
//    vectorArrayPrint(test);
    
//    vector<Point3D> pointList;

//    
//   
//    
//    vetex.push_back({5,6,7});
//     vetex.push_back({10,6,7});
//    vetex.push_back({11,6,7});
//    
//    cout << vetex[0].z<<endl;
//    cout << "sizef of" <<vetex.size()<<endl;
    

//    string s = "123 456 789 333 444";
//    vector<double> result;
//    result = split(s, " ");
//    for (vector<double>::iterator i=result.begin(); i != result.end(); i++) {
//        cout << *i << endl;
//    }
//
    
    Obj *o = new Obj();
//    o->vetex;
    vector<Point3D> vetex;
//    vetex= (vector<Point3D>)malloc(sizeof(Point3D));
//    Point3D *point = (Point3D *)malloc(sizeof(Point3D));
//    o->vetex = (vector<Point3D>  *)malloc(sizeof(vector<Point3D>));

    
//    vetex
//    for (vector<Point3D>::iterator i=vetex.begin(); i != vetex.end(); i++) {
//        cout << (*i).x << " " <<  (*i).y << " " <<  (*i).z << endl;
//
    o->storeVetex(vetex);
    
    
   vector<vector<int>> ve = o->vetexToArray(vetex);
  
//vectorArrayPrint(ve);
//   vector<vector<int>> v =  getFacesVector(ve, 664, 1080);
//    vectorArrayPrint(v);
//    cout << "size of " << ve.size();
    vector<vector<int>> v =  o->getFacesVector(ve, 664, 1080);
//  o->vectorArrayPrint(v);
    o->new_obj_write("/tmp/luofei.obj",vetex, ve, v);
//    delete [] o;
    return 0;
}






