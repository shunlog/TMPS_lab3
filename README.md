# Structural Design Patterns

## Author: Balan Artiom

----

## Objectives:

* Get familiar with the Design Patterns;
* Choose a specific domain;
* Implement at least 2 CDPs for the specific domain; 


## Used Design Patterns: 

* Adapter pattern
* Composite pattern

## Implementation

For the **adapter pattern**, pretend there is a legacy library called `legacySocket`,
but our client needs a Target that implements the `SocketInterface`.
To solve this, we write an adapter called `LegacySocketAdapter`
which uses a `LegacySocket` object and basically renames the methods by wrapping around them.

Thus, the client can use a `LegacySocket` without being concerned with  its old legacy interface,
and as if `LegacySocket` implemented its new fashionable `SocketInterface`:

``` c++
// legacy library
class LegacySocket {
public:
    void connectLegacy();
    void sendDataLegacy();
};

...

// interface required by client 
class SocketInterface {
public:
    virtual void connect() = 0;
    virtual void sendData() = 0;
};

...

// client code
LegacySocketAdapter adapter(new LegacySocket);
adapter.connect();
adapter.sendData();
```


I wanted to send some files over this socket,
and the best pattern to represent a hierarchical filesystem is the **composite pattern**.
The *Composite* is the `Directory` and the *Leaf* is the `File`.

Then I define the `list_files()` method.
For Directories, it recurses into its files:

``` c++
void Directory::list_files(std::vector<std::string>& files, const std::string& path) const {
    std::string newPath = path + "/" + name_;

    for (const auto& child : children_) {
        child->list_files(files, newPath);
    }
}
```

While for Files, it pushes the file path to the list:

``` c++
void File::list_files(std::vector<std::string>& files, const std::string& path) const {
    files.push_back(path + "/" + name_);
}
```

## Conclusions / Screenshots / Results
Here is a sample program and the output it generates:
``` c++
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
```

Output:
```
$ make run -B
g++ -Wall -fdiagnostics-color -g *.cpp **/*.cpp -o main
./main
Connected using legacy socket.
Sending file: /Root/File1
Sending file: /Root/File2
Sending file: /Root/Directory1/File3
```

