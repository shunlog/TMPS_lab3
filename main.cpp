#include <iostream>
#include <vector>
#include "legacy_socket_adapter.cpp"
#include "filesystem.h"

int main() {
    // create sample directory
    Directory root("Root");
    File file1("File1");
    File file2("File2");
    Directory directory("Directory1");
    File file3("File3");

    directory.add(&file3);
    root.add(&file1);
    root.add(&file2);
    root.add(&directory);

    // obtain list of files
    std::vector<std::string> files;
    root.list_files(files, "");

    // create a socket
    LegacySocketAdapter adapter(new LegacySocket);
    adapter.connect();

    // send the files
    for (std::string f : files){
        adapter.send_file(f);
    }
}
