//
//  main.cpp
//  cplusplus_test
//
//  Created by luofei on 12/6/15.
//  Copyright © 2015 luofei. All rights reserved.
//

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <vector>
# include <stdlib.h>
# include <math.h>

using namespace std;

# include "obj_io.hpp"

//int main ( int argc, char *argv[] );
void test01 ( string filename );
void test02 ( string filename );
void test03 ( string filename );
void test04 ( string filename );
void getFaces(double (*node_xyz)[4], int x, int y);
int countFace(double (*node_xyz)[4], int x, int y);
void vectorArrayPrint(vector<vector<int>> it);
vector<vector<int>> getFacesVector(vector<vector<int>> vetex , int row, int col);
void storeVetex();
std::vector<double> split(std::string str,std::string pattern);
void new_obj_write ( string output_filename);



typedef struct Point3D{
    double x;
    double y;
    double z;
}Point3D;
vector<Point3D> vetex;
bool checkFacesVector(Point3D a, Point3D b, Point3D c);

vector<vector<int>> vetexToArray();
//****************************************************************************80

int main ( int argc, char *argv[] )

{
    string filename;
    
    timestamp ( );
    cout << "\n";
    cout << "OBJ_IO_PRB:\n";
    cout << "  C++ version\n";
    cout << "  Test the OBJ_IO library.\n";
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
    
    filename = "/tmp/luofei_cube.obj";
    test03 (filename);
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
    storeVetex();
    
//    vetex
//    for (vector<Point3D>::iterator i=vetex.begin(); i != vetex.end(); i++) {
//        cout << (*i).x << " " <<  (*i).y << " " <<  (*i).z << endl;
//    }

    
   vector<vector<int>> ve = vetexToArray();
//vectorArrayPrint(ve);
//   vector<vector<int>> v =  getFacesVector(ve, 664, 1080);
//    vectorArrayPrint(v);
//    cout << "size of " << ve.size();
    new_obj_write("/tmp/luofei.obj");
    return 0;
}

// Get vetex
std::vector<double> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<double> result;
    str+=pattern;//扩展字符串以方便操作
    unsigned long size=str.size();
    
    for(unsigned long i=0; i<size; i++)
    {
        
        //Get three of head value
        if (result.size() >= 3) {
            break;
        }
        
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(stod(s));
            i=pos+pattern.size()-1;
        }
        
    
    }

  
    return result;
}


// Read vetex from file and store vetex to vector<Point3D> vetex
void storeVetex()
{
    
    ifstream fin("/Users/luofei/Desktop/tmp/writeObj/scanface3_texture.points");
    if (!fin) {
        cout << "Can not found scanface3_texture.points" << endl;
        return;
    }

    string buf;
    int i = 0;
    while (getline(fin, buf)) {
        vector<double> result;
        result = split(buf, " ");
        vetex.push_back({result[0],result[1],result[2]});
        i++;
    }
    
    cout << i << endl;

    
}

// Computer faces
vector<vector<int>> getFacesVector(vector<vector<int>> vetex , int row, int col)
{
    cout << "getFacesVector method" << endl;
    
    
    vector<vector<int>> faces;

    for (int i = 0; i < row-1; i++) {
        for (int j = 0; j < col-1; j++) {
            vector<int> row = {vetex[i][j], vetex[i+1][j], vetex[i+1][j+1]};
            faces.push_back(row);
            vector<int> row1 = {vetex[i][j],vetex[i][j+1],vetex[i+1][j+1]};
            faces.push_back(row1);
        }
    }
    
    return faces;

}

bool checkFacesVector(Point3D a, Point3D b, Point3D c)
{
    double max = 10000.0;
    double A = pow((a.x - b.x),2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2);
    double B = pow((a.x - c.x),2) + pow((a.y - c.y), 2) + pow((a.z - c.z), 2);
    double C = pow((c.x - b.x),2) + pow((c.y - b.y), 2) + pow((c.z - b.z), 2);
    if ((A > max) || (B > max) || (C > max)) {
        return false;
    }
    return true;
}


// Vetex to dyadic array
vector<vector<int>> vetexToArray()
{
    vector<vector<int>> vetexArray;
    int vetex_size = vetex.size();
    int col  = 1080;
    int row = vetex_size / col;
  
    vetexArray.resize(row);
    
    cout << "row is " << row;
    cout << "clo is " << col;
    for (int i = 0; i < row; i++) {
        vetexArray[i].resize(col);
    }
    int vetexIndex = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++, vetexIndex++) {
            vetexArray[i][j] = vetexIndex;
        }
    }

//
//    for (int i =0 ; i < vetex.size(); i++) {
//        vetexArray.push_back(vetex);
//    }
    return vetexArray;
}
 



// Print dyadic array
void vectorArrayPrint(vector<vector<int>> it)
{
    for (vector<vector<int>>::iterator i = it.begin();i != it.end(); i++) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}


void test03 ( string output_filename )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tests OBJ_WRITE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 January 2011
//
//  Author:
//
//    John Burkardt
//
{
# define FACE_NUM 12
# define NODE_NUM 8
# define NORMAL_NUM 6
# define ORDER_MAX 3
    
    int face_node[ORDER_MAX*FACE_NUM] = {
        1, 3, 2,
        2, 3, 4,
        1, 6, 5,
        1, 2, 6,
        3, 7, 4,
        4, 7, 8,
        5, 6, 8,
        5, 8, 7,
        1, 5, 7,
        1, 7, 3,
        2, 4, 6,
        6, 4, 8 };
    int face_num = FACE_NUM;
    int face_order[FACE_NUM] = {
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    int node_num = NODE_NUM;
    double node_xyz[3*NODE_NUM] = {
        0.0, 0.0, 0.0,
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        1.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        0.0, 1.0, 1.0,
        1.0, 1.0, 1.0 };
    int normal_num = NORMAL_NUM;
    double normal_vector[3*NORMAL_NUM] = {
        0.0,  0.0,  1.0,
        0.0,  0.0, -1.0,
        0.0,  1.0,  0.0,
        0.0, -1.0,  0.0,
        1.0,  0.0,  0.0,
        -1.0,  0.0,  0.0 };
    int order_max = ORDER_MAX;
    int vertex_normal[ORDER_MAX*FACE_NUM] = {
        2, 2, 2,
        2, 2, 2,
        4, 4, 4,
        4, 4, 4,
        3, 3, 3,
        3, 3, 3,
        1, 1, 1,
        1, 1, 1,
        6, 6, 6,
        6, 6, 6,
        5, 5, 5,
        5, 5, 5 };
    
    cout << "\n";
    cout << "TEST03\n";
    cout << "  OBJ_WRITE writes an ASCII OBJ file.\n";
    
    obj_write ( output_filename, node_num, face_num, normal_num,
               order_max, node_xyz, face_order, face_node, normal_vector, vertex_normal );
    
    cout << "\n";
    cout << "  Graphics data was written to the OBJ file \""
    << output_filename << "\".\n";
    
    return;
# undef FACE_NUM
# undef NODE_NUM
# undef NORMAL_NUM
# undef ORDER_MAX
}

int countFace(double (*node_xyz)[4], int x, int y )
{
    
    for (int i = 0; i < x; i++) {
        for (int z=0; z < y; z++) {
            cout << node_xyz[i][z] << " ";
        }
        cout<<endl;
    }

    return (x-1) * (y-1) * 2;
}



void getFaces(double (*node_xyz)[4], int row, int line )
{
    cout << "getFaces method" << endl;

    
    int faces[12][3];
    int face_num = 0;
    cout << "row " << row<<endl;
    cout << "line " << line<<endl;
    for (int i = 0; i < row-1; i++) {
        for (int j =0 ; j < line-1; j++,face_num++) {
               
            faces[face_num][0] = node_xyz[i][j];
            faces[face_num][1] = node_xyz[i+1][j];
            faces[face_num][2] = node_xyz[i+1][j+1];
            face_num++;
            faces[face_num][0] = node_xyz[i][j+1];
            faces[face_num][1] = node_xyz[i][j];
            faces[face_num][2] = node_xyz[i+1][j+1];
                    
        }
    }


    
    for (int i=0; i<12; i++) {
        for (int j=0; j<3; j++) {
            cout << faces[i][j]<< " ";
        }
        cout << endl;
    }
    
    
}

void new_obj_write ( string output_filename)
{
    int face;
    int i;
    int j;
    int node;
    int normal;
    ofstream output;
    int text_num;
    int vertex;
    double w;
    
    output.open ( output_filename.c_str ( ) );
    
    if ( !output )
    {
        cerr << "\n";
        cerr << "OBJ_WRITE - Fatal error!\n";
        cerr << "  Could not open the output file \"" << output_filename << "\".\n";
        exit ( 1 );
    }
    
    text_num = 0;
    
    output << "# " << output_filename << "\n";
    output << "# created by obj_io::obj_write.C\n";
    output << "\n";
    output << "g Group001\n";
    
    text_num = text_num + 4;
    //
    //  V: vertex coordinates.
    //  For some reason, a fourth "coordinate" may be recommended.
    //  What is its meaning?
    //
    int node_num = vetex.size();
    if ( 0 < node_num )
    {
        output << "\n";
        text_num = text_num + 1;
    }
    
    w = 1.0;
    for ( node = 0; node < node_num; node++ )
    {
        output << "v";
        output << "  " << vetex[node].x;
        output << "  " << vetex[node].y;
        output << "  " << vetex[node].z << endl;
        
//        output << "  " << w << "\n";
        text_num = text_num + 1;
    }
    //
    //  VN: normal vectors.
    //
//    if ( 0 < normal_num )
//    {
//        output << "\n";
//        text_num = text_num + 1;
//        
//        for ( normal = 0; normal < normal_num; normal++ )
//        {
//            output << "vn";
//            for ( i = 0; i < 3; i++ )
//            {
//                output << "  " << normal_vector[i+normal*3];
//            }
//            output << "\n";
//            text_num = text_num + 1;
//        }
//    }
    //
    //  F: Faces, specified as a list of triples, one triple for each vertex:
    //     vertex index/vertex texture index/vertex normal index
    //
    
    vector<vector<int>> ve = vetexToArray();
    vector<vector<int>> v =  getFacesVector(ve, 664, 1080);
    
    int face_num = v.size();
    
    cout << "face_num of " << v.size()<< endl;
    if ( 0 < face_num )
    {
        output << "\n";
        text_num = text_num + 1;
    }
    
    int sum = 0;
    for ( face = 0; face < face_num; face++ )
    {
        output << "f";
        bool check = checkFacesVector(vetex[v[face][0]], vetex[v[face][1]], vetex[v[face][2]]);
        if (check){
            for (int i = 0 ; i < 3; i++) {
                output << "  " << v[face][i]<< "//";
            }
        }else{
            sum ++;
        }
        
        output << "\n";
        text_num = text_num + 1;
    }
    
    cout << "remove face_num of " << sum<<endl;
    
    output.close ( );
    //
    //  Report.
    //
    if ( false )
    {
        cout << "\n";
        cout << "OBJ_WRITE:\n";
        cout << "  Wrote " << text_num << " text lines to \""
        << output_filename << "\"\n";
    }
    
    return;
}




