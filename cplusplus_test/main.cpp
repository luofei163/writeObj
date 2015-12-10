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



//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for OBJ_IO_PRB.
//
//  Discussion:
//
//    OBJ_IO_PRB tests the OBJ_IO library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2011
//
//  Author:
//
//    John Burkardt
//
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
    cout << "\n";
    cout << "OBJ_IO_PRB:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
    
    timestamp ( );
    
//    double (*node_xyz)[5];
    double b[][4]={
        {1.0,2.0,3.0,4.0},
        {5.0,6.0,7.0,8.0},
        {9.0,10.0,11.0,12.0}
    };
//    node_xyz = b;
//    countFace(b,3,4);
//    getFaces(b,3,4);
    
    vector<vector<int>> it;
     int size = 6;
//    it.resize(size);
//    for (int i=0; i<size; i++) {
//        it[i].resize(5);
//    }
    
     vector<int> row1 = {1,2,3,4,5};
     vector<int> row2 = {7,8,9,10,11};
     vector<int> row3 = {12,13,14,15,16};
     vector<int> row4 = {17,18,19,20,21};
     vector<int> row5 = {22,23,24,25,26};
     vector<int> row6 = {27,28,29,30,31};
    cout <<"it f = " <<  it.size()<<endl;

    it.push_back(row1);
    it.push_back(row2);
    it.push_back(row3);
    it.push_back(row4);
    it.push_back(row5);
    it.push_back(row6);
    
    cout << it.size() <<endl;
    vectorArrayPrint(it);

    
//
    return 0;
}

void getFacesVector(vector<vector<int>> vetex )
{
    cout << "getFacesVector method" << endl;
    
    
    vector<int> faces;
    
    
    for (vector<vector<int>>::iterator i = vetex.begin();i != vetex.end(); i++) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            faces.push_back(*j);
            cout << *j << " ";
        }
    }

}

void vectorArrayPrint(vector<vector<int>> it)
{
    for (vector<vector<int>>::iterator i = it.begin();i != it.end(); i++) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}
//****************************************************************************80

void test01 ( string filename )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests OBJ_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2011
//
//  Author:
//
//    John Burkardt
//
{
    int face_num;
    int node_num;
    int normal_num;
    int order_max;
    
    cout << "\n";
    cout << "TEST01\n";
    cout << "  OBJ_SIZE determines the size of various objects\n";
    cout << "  in an OBJ file.\n";
    
    obj_size ( filename, &node_num, &face_num, &normal_num, &order_max );
    
    obj_size_print ( filename, node_num, face_num, normal_num, order_max );
    
    return;
}
//****************************************************************************80

void test02 ( string input_file_name )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests OBJ_READ.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2011
//
//  Author:
//
//    John Burkardt
//
{
    int *face_node;
    int face_num;
    int *face_order;
    int node_num;
    double *node_xyz;
    double *normal_vector;
    int normal_num;
    int order_max;
    int *vertex_normal;
    
    cout << "\n";
    cout << "TEST02\n";
    cout << "  OBJ_READ reads an object in an OBJ file.\n";
    
    obj_size ( input_file_name, &node_num, &face_num, &normal_num, &order_max );
    
    face_node = new int[order_max*face_num];
    face_order = new int[face_num];
    node_xyz = new double[3*node_num];
    normal_vector = new double[3*normal_num];
    vertex_normal = new int[order_max*face_num];
    
    //obj_read ( input_file_name, node_num, face_num, normal_num,
    //  order_max, node_xyz, face_order, face_node, normal_vector, vertex_normal );
    
    obj_face_node_print ( face_num, order_max, face_order, face_node );
    obj_normal_vector_print ( normal_num, normal_vector );
    obj_node_xyz_print ( node_num, node_xyz );
    
    delete [] face_node;
    delete [] face_order;
    delete [] node_xyz;
    delete [] normal_vector;
    delete [] vertex_normal;
    
    return;
}
//****************************************************************************80

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

