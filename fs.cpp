#include <iostream>
#include <array>
#include "fs.h"
using namespace std;

FS::FS()
{
    std::cout << "FS::FS()... Creating file system\n";
    this->disk.read(1,(unsigned char*)this->fat);
}

FS::~FS()
{

}
//function to get the file details
std::array<std::string, 4> FS::getFileDetails(const std::string& filepath) {
    std::string filename, extension, stem;
    
    // Find the last '/' or '\\'
    size_t lastSlash = filepath.find_last_of("/\\");
    filename = (lastSlash != std::string::npos) ? filepath.substr(lastSlash + 1) : filepath;

    // Find the last '.' to separate the extension
    size_t lastDot = filename.rfind('.');
    if (lastDot != std::string::npos) {
        extension = filename.substr(lastDot); // Extension includes the dot
        stem = filename.substr(0, lastDot);  // Filename without extension
    } else {
        extension = ""; // No extension
        stem = filename; // Entire filename is the stem
    }
    //remove the file name from the path
    string path = filepath.substr(0, lastSlash);
    cout << "Path: " << path << endl;
    if (path.empty()||path == filename) {
        path = "/";
    }
    return std::array<std::string, 4>{filename, stem, extension, path};
    return {filename, stem, extension, path};
}



// formats the disk, i.e., creates an empty file system
int
FS::format()
{
    /*the first block will be used for root, whcih means it's busy*/
    this->fat[0] = ROOT_BLOCK;
    this->fat[1] = FAT_BLOCK;
    /*initializing the other blocks as free
    We are using a block size of 4096 it hardcoded in disk.h*/
    for (int i = 2; i < BLOCK_SIZE; i++)
    {
        this->fat[i] = FAT_FREE;
    }
    cout << "Fat: " << sizeof(this->fat) << endl;  
    /*writing the fat to the disk, Disk::write(unsigned block_no, uint8_t *blk)
    Fat are is an array*/
    if(this->disk.write(FAT_BLOCK,(uint8_t*)this->fat) !=0)
    {
        cout << "Failed to write to disk" << endl;
        return 1;
    }
    std::cout << "FAT written successfully to disk.\n";
    cout<<"Disk Formatted"<<endl;
    return 0;

}

// create <filepath> creates a new file on the disk, the data content is
// written on the following rows (ended with an empty row)
int
FS::create(std::string filepath)
{
    
    std::cout << "FS::create(" << filepath << ")\n";
    return 0;
}

// cat <filepath> reads the content of a file and prints it on the screen
int
FS::cat(std::string filepath)
{
    std::cout << "FS::cat(" << filepath << ")\n";
    return 0;
}

// ls lists the content in the currect directory (files and sub-directories)
int
FS::ls()
{
    std::cout << "FS::ls()\n";
    return 0;
}

// cp <sourcepath> <destpath> makes an exact copy of the file
// <sourcepath> to a new file <destpath>
int
FS::cp(std::string sourcepath, std::string destpath)
{
    std::cout << "FS::cp(" << sourcepath << "," << destpath << ")\n";
    return 0;
}

// mv <sourcepath> <destpath> renames the file <sourcepath> to the name <destpath>,
// or moves the file <sourcepath> to the directory <destpath> (if dest is a directory)
int
FS::mv(std::string sourcepath, std::string destpath)
{
    std::cout << "FS::mv(" << sourcepath << "," << destpath << ")\n";
    return 0;
}

// rm <filepath> removes / deletes the file <filepath>
int
FS::rm(std::string filepath)
{
    std::cout << "FS::rm(" << filepath << ")\n";
    return 0;
}

// append <filepath1> <filepath2> appends the contents of file <filepath1> to
// the end of file <filepath2>. The file <filepath1> is unchanged.
int
FS::append(std::string filepath1, std::string filepath2)
{
    std::cout << "FS::append(" << filepath1 << "," << filepath2 << ")\n";
    return 0;
}

// mkdir <dirpath> creates a new sub-directory with the name <dirpath>
// in the current directory
int
FS::mkdir(std::string dirpath)
{
    std::cout << "FS::mkdir(" << dirpath << ")\n";
    return 0;
}

// cd <dirpath> changes the current (working) directory to the directory named <dirpath>
int
FS::cd(std::string dirpath)
{
    std::cout << "FS::cd(" << dirpath << ")\n";
    return 0;
}

// pwd prints the full path, i.e., from the root directory, to the current
// directory, including the currect directory name
int
FS::pwd()
{
    std::cout << "FS::pwd()\n";
    return 0;
}

// chmod <accessrights> <filepath> changes the access rights for the
// file <filepath> to <accessrights>.
int
FS::chmod(std::string accessrights, std::string filepath)
{
    std::cout << "FS::chmod(" << accessrights << "," << filepath << ")\n";
    return 0;
}
