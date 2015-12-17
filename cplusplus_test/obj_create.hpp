//
//  obj_create.hpp
//  cplusplus_test
//
//  Created by luofei on 12/14/15.
//  Copyright © 2015 luofei. All rights reserved.
//

#ifndef obj_create_hpp
#define obj_create_hpp

#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
# include <iostream>
using namespace std;

typedef struct Point3D{
    double x;
    double y;
    double z;
}Point3D;


class Obj
{
    



public:
    

    
    vector<Point3D> vetex;
  
    void vectorArrayPrint(vector<vector<int> > it);

  
    void storeVetex(vector<Point3D> &vetex);
    std::vector<double> split(std::string str,std::string pattern);
    void new_obj_write ( string output_filename, vector<Point3D> &vetex,  vector<vector<int> > vetexArray, vector<vector<int> > facesVector);
    
    bool checkFacesVector(Point3D a, Point3D b, Point3D c);
    
//    vector<vector<int> > vetexToArray();
    vector<vector<int> > vetexToArray(vector<Point3D> &vetex);
    vector<vector<int> > getFacesVector(vector<vector<int> > &vetex , int row, int col);

    
};


#endif /* obj_create_hpp */
