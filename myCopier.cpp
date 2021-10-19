/*

myCopier.cpp
Copys files contents within the working directory
e.g myCopier example.src example.dest

! Does not work to copy files outside of the working directory !

Written by Evan

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[], char* env[])
{
    // make sure there are 3 arguments
	if (argc != 3)
 	{
	    cout << "myCopier by Evan" << endl;
        cout << "Usage:" << endl;
        cout << "arg1=src_file, arg2=dest_file" << endl;
        cout << "e.g. myCopier example.src example.dest" << endl;
        return 1;
    }

    // get working dir
	string pwd(getenv("PWD"));

    // get src & dest file names
    string src_file_name(argv[1]);
    string dest_file_name(argv[2]);

    // build src & dest file paths
    string src_file_path = pwd + "/" + src_file_name;
    string dest_file_path = pwd + "/" + dest_file_name;
    
    // init file streams & string storage for reading
    fstream fs_src, fs_dest;
    string line, text;

    cout << "Copying the contents of " + src_file_name + " -> " + dest_file_name << endl;
    
    // open src & dest files
    fs_src.open((src_file_path).c_str(), fstream::in);
    fs_dest.open((dest_file_path).c_str(), fstream::out);

    // line count   
    int lc = 0;

    // read src file line by line
    while (getline(fs_src, line))
    {        
        text += line + "\n";
        lc++;
    }
    // close src file 
    fs_src.close();

    cout << lc << " lines copied" << endl;
    
    // write text to dest file
    fs_dest << text;
    // close dest file
    fs_dest.close();

    cout << "Finished copying" << endl;

	return 0;
}
