//
//  obj_create.cpp
//  cplusplus_test
//
//  Created by luofei on 12/14/15.
//  Copyright © 2015 luofei. All rights reserved.
//

#include "obj_create.hpp"

// Get vetex
std::vector<double> Obj::split(std::string str,std::string pattern)
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
void Obj::storeVetex(vector<Point3D> &vetex)
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
vector<vector<int> > Obj::getFacesVector(vector<vector<int> > &vetex , int row, int col)
{
    cout << "getFacesVector method" << endl;


    vector<vector<int> > faces;

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

bool Obj::checkFacesVector(Point3D a, Point3D b, Point3D c)
{
    double max = 100.0;
    double A = pow((a.x - b.x),2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2);
    double B = pow((a.x - c.x),2) + pow((a.y - c.y), 2) + pow((a.z - c.z), 2);
    double C = pow((c.x - b.x),2) + pow((c.y - b.y), 2) + pow((c.z - b.z), 2);
    if ((A > max) || (B > max) || (C > max)) {
        return false;
    }
    return true;
}


// Vetex to dyadic array
vector<vector<int> > Obj::vetexToArray(vector<Point3D> &vetex)
{
    vector<vector<int> > vetexArray;
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
void Obj::vectorArrayPrint(vector<vector<int> > it)
{
    for (vector<vector<int> >::iterator i = it.begin();i != it.end(); i++) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}


void Obj::new_obj_write ( string output_filename, vector<Point3D> &vetex,  vector<vector<int> > vetexArray, vector<vector<int> > facesVector)
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
    
    vector<vector<int> > ve = vetexArray;
//    vector<vector<int>> v =  getFacesVector(ve, 664, 1080);
    vector<vector<int> > v = facesVector;
    
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
        
        bool check = checkFacesVector(vetex[v[face][0]], vetex[v[face][1]], vetex[v[face][2]]);
        if (check){
            output << "f";
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

